#include <iostream>
#include <string>
#include <vector>

using namespace std;

int next(int &i, int &j, vector<string> &vs){
	if ('S' == vs[i][j])
		++i;
	else if ('N' == vs[i][j])
		--i;
	else if ('W' == vs[i][j])
		--j;
	else if ('E' == vs[i][j])
		++j;
	return 0;
}

int main(){
	int L,C,X;
	while(cin >>L >>C >>X){
		vector<string> vs(L);
		for(int i=0;i<L;++i)
			cin >>vs[i];
		vector<int> sample(C,0);
		vector<vector<int> > visited(L, sample);
		int i=0,j=X-1,step=0;
		while(i>=0 && i<L && j>=0 && j<C){
			if (!visited[i][j]){
				step++;
				visited[i][j] = 1;
				next(i,j,vs);
			}
			else {
				int loopstep=0;
				int u=i,v=j;
				while(true){
					loopstep++;
					next(u,v,vs);
					if (u==i && v==j){
						cout << step-loopstep <<" step(s) before a loop of "
							<<loopstep <<" step(s)" <<endl;
						break;
					}
				}
				break;
			}
		}
		if (i<0 || i>=L || j<0 || j>=C){
			cout <<step <<" step(s) to exit" <<endl;
		}
	}
	return 0;
}
