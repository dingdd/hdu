#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int bugs[101], scores[101];
int visited[101];
int F[101][101] = {0};
int maxArray[101] = {0};

int initMaxArray(vector<vector<int> > &edges, int idx){
	int sum = 0;
	visited[idx] = 1;
	vector<int> neighbors = edges[idx];
	for(int i=0;i<neighbors.size();++i){
		if (visited[neighbors[i]])
			continue;
		sum += initMaxArray(edges, neighbors[i]);
	}
	maxArray[idx] = sum + bugs[idx];
	return maxArray[idx];
}

int dfs0(vector<int> &children, int idx, int n, int bug, int score){
	if (n == children.size()){
		F[idx][bug+bugs[idx]] = max(F[idx][bug+bugs[idx]], scores[idx]+score);
		if (bugs[idx]>0)
			F[idx][0] = 0;
		return 0;
	}
	for(int i=0;i<=maxArray[children[n]];++i){
		if (F[children[n]][i] == -1)
			continue;
		dfs0(children, idx, n+1, bug+i, score+F[children[n]][i]);
	}
	return 0;
}

int dfs(vector<vector<int> > &edges, int idx){
	visited[idx] = 1;
	vector<int> neighbors = edges[idx];
	vector<int> children;
	for(int i=0;i<neighbors.size();++i){
		if (visited[neighbors[i]])
			continue;
		children.push_back(neighbors[i]);
		dfs(edges, neighbors[i]);
	}
	if (children.size() == 0){
		F[idx][0] = 0;
		F[idx][bugs[idx]]=scores[idx];
		return 0;
	}
	dfs0(children, idx, 0, 0, 0);
	return 0;
}

int main(){
	int n, m;
	while(cin >>n >>m){
		if (n == -1 && m == -1)
			break;
		for(int i=0;i<n;++i)
			cin >>bugs[i] >>scores[i];
		vector<vector<int> > edges(n,vector<int>());
		for(int i=0;i<n-1;++i){
			int p, q;
			cin >>p >>q;
			edges[p-1].push_back(q-1);
			edges[q-1].push_back(p-1);
		}
		for(int i=0;i<n;++i)
			bugs[i] = (bugs[i] + 19)/20;
		memset(visited, 0, sizeof(visited));
		memset(F, -1, sizeof(F));
		initMaxArray(edges, 0);
		memset(visited, 0, sizeof(visited));
		dfs(edges, 0);
		int maxScore = 0;
		for(int i=0;i<=m;++i)
			maxScore = max(maxScore, F[0][i]);
		cout <<maxScore<<endl;
	}
	return 0;
}
