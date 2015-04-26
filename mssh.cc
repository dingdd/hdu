#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#define LINESZ 4096
#define PPLINE (LINESZ *2)
#define ARGVSZ 4096
#define PPSIZE 50

static char *pipes[PPSIZE];
static char ppln[PPLINE+1];
static char cmd[LINESZ+1];
static char *argv[ARGVSZ];
static int argc=0;

static int pipeignore(char *s){
	int cnt=0;
	char *p=s;
	for(;*s;++s){
		if(*s!='|')
			continue;
		*s='\0';
		pipes[cnt++]=p;
		p=s+1;
	}
	pipes[cnt]=p;
	return cnt;
}

static int spaceignore(char *s, char *t){
	// need extra space and set back later
	char *p=--s;
	*p=' ';
	while(*s&&*s!='\n'){
		if(isblank(*s)){
			++s;
			continue;
		}
		if(isblank(*(s-1)))
			*t++=' ';
		*t++=*s++;
	}
	*t=0;
	*p=0;
	return 0;
}

static int split(char *s, char *argv[]){
	int cnt=0;
	for(;*s;++s){
		if(!isblank(*s))
			continue;
		*s++=0;
		argv[cnt]=s;
		if(*s)
			cnt++;
	}
	argv[cnt]=NULL;
	return cnt;
}

static const char *stdio[3]={NULL, NULL, NULL };
static int pipefd[2];

static int fredict(){
	int flag[3]={O_RDONLY, O_WRONLY, O_WRONLY};
	int cnt=0;
	for(int i=0;i<3;++i){
		if(!stdio[i])
			continue;
		int fd=open(stdio[i],flag[i]|O_CREAT);
		if(dup2(fd,i)==-1){
			exit(-1);
		}
		cnt++;
	}
	return cnt;
}

static int dowithstdio(char *argv[]){
	int id=0;
	for(int i=0;argv[i];++i){
		switch(argv[i][0]){
			case '\0':
				return -1;
			case '<':
			case '>':
				id=(argv[i][0]-'<')/2;
				switch(argv[i][1]){
					case '\0':
						if(!argv[i+1])
							return -1;
						else{
							argv[i]=NULL;
							stdio[id]=argv[++i];
							argv[i]=NULL;
						}
						break;
					default:
						stdio[id]=argv[i]+1;
						argv[i]=NULL;
						break;
				}
				break;
			case '2':
				switch(argv[i][1]){
					case '\0':
						break;
					case '>':
						if(argv[i][2]=='\0'&&argv[i+1]==NULL)
							return -1;
						if(argv[i][2]!='\0'){
							stdio[2]=argv[i]+2;
							argv[i]=NULL;
						}
						else{
							argv[i]=NULL;
							stdio[2]=argv[++i];
							argv[i]=NULL;
						}
						break;
				}
		}
	}
	return 0;
}

static int removeEmp(int cnt, char *argv[]){
	int i=0;
	for(int j=0;j<cnt;++j){
		if(!argv[j])
			continue;
		argv[i++]=argv[j];
	}
	argv[i]=NULL;
	return ++i; 
}

static void doCD(int argc, char* argv[]){
	if(argc!=2){
		fputs("The arguments # is uncorrect\n", stdout);
		exit(-1);
	}
	if(!chdir(argv[1]))
		return;
	fputs("Change working directory failed\n", stdout);
	exit(-1);
}

static int doIfBidIn(char* argv[]){
	if(!argv[0])
		return 1;
	if(!strcmp(argv[0], "exit"))
		exit(0);
	else if(!strcmp(argv[0], "cd"))
		doCD(argc, argv);
	else if(!strcmp(argv[0], "echo")){}
	else
		return 0;
	return 1;
}

static int pipeExec(char *line){
	int pid=0;
	if(pipe(pipefd)){
		fputs("Pipe Creating Error\n", stdout);
		exit(-1);
	}
	pid=fork();
	if(pid==-1){
		fputs("Trying Fork A New Process Error\n", stdout);
		exit(-1);
	}
	if(pid==0){
		close(pipefd[0]);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		return 0;
	}
	close(pipefd[1]);
	dup2(pipefd[0], 0);
	close(pipefd[0]);

	spaceignore(line, cmd);
	argc=split(cmd, argv);
	dowithstdio(argv);
	fredict();
	removeEmp(argc, argv);
	if(!doIfBidIn(argv))
		execvp(argv[0], argv);
	int status=0;
	if(wait(&status)==-1)
		fputs("Error Occur in Child Process\n", stdout);
	fflush(stdout);
	exit(0);
}

int main(){
	char linecont[LINESZ+1];
	char *line=linecont+1;
	int pipenum=0;
	while(true){
		fputs("> ", stdout);
		fgets(line, LINESZ, stdin);
		if(feof(stdin))
			break;
		pipenum=pipeignore(line);
		spaceignore(pipes[0], cmd);
		argc=split(cmd, argv);
		dowithstdio(argv);
		fredict();
		removeEmp(argc, argv);
		if(!pipenum&&doIfBidIn(argv))
			continue;

		int pid=fork();
		if(pid==-1){
			fputs("Error in Forking Child\n", stdout);
			continue;
		}
		if(pid){
			int status=0;
			wait(&status);
			continue;
		}
		for(int i=pipenum;i>0;--i)
			pipeExec(pipes[i]);
		if(pipenum)
			close(pipefd[0]), dup2(pipefd[1],1), close(pipefd[1]);
		fflush(stdout);
		execvp(argv[0], argv);
		break;
	}
	return 0;
}
