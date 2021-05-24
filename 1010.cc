#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

int d[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1}};
string mat[8];
int visited[8][8];
int N,M,T,Sx,Sy,Ex,Ey;

int dfs(int x, int y, int t){
	if(x<0 || x>=N || y<0 || y>=M || t>T) return 0;
	if(visited[x][y] == 1 || mat[x][y] == 'X') return 0;
	if(mat[x][y] == 'D' && t==T) return 1;
	visited[x][y] = 1;
	char saved = mat[x][y];
	mat[x][y] = 'X';
	for(int i=0;i<4;++i){
		if(dfs(x+d[i][0], y+d[i][1], t+1))
			return 1;
	}
	mat[x][y] = saved;
	visited[x][y] = 0;
	return 0;
}

int main(){
	while(cin >>N >>M >>T){
		if(N==0 && M==0 && T==0)
			break;
		memset(visited, 0, sizeof(visited));
		for(int i=0;i<N;++i){
			cin >>mat[i];
			for(int j=0;j<M;++j) {
				if('S' == mat[i][j])
					Sx=i, Sy=j;
				if('D' == mat[i][j])
					Ex=i, Ey=j;
			}
		}
		if(abs(Ex+Ey-Sx-Sy-T)%2 == 0 && dfs(Sx, Sy, 0))
			cout <<"YES" <<endl;
		else
			cout <<"No" <<endl;
	}
	return 0;
}
