#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int t;

using namespace std;

bool dfs(string &s, vector<int> &visited, string &vwxyz){
	if(vwxyz.size() == 5){
		int v = vwxyz[0] - 'A' + 1;
		int w = vwxyz[1] - 'A' + 1;
		int x = vwxyz[2] - 'A' + 1;
		int y = vwxyz[3] - 'A' + 1;
		int z = vwxyz[4] - 'A' + 1;
		if (t == v-w*w+x*x*x-y*y*y*y+z*z*z*z*z)
			return true;
		return false;
	}
	for(int i=s.size()-1;i>=0;--i){
		if(visited[i])
			continue;
		visited[i] = 1;
		vwxyz.push_back(s[i]);
		if (dfs(s, visited, vwxyz))
			return true;
		vwxyz.pop_back();
		visited[i] = 0;
	}
	return false;
}

int main(){
	string s;
	while(cin >>t >>s){
		if (t==0 && s=="END")
			break;
		sort(s.begin(),s.end());
		vector<int> visited(s.size(), 0);
		string vwxyz;
		if (dfs(s, visited, vwxyz))
			cout <<vwxyz <<endl;
		else
			cout <<"no solution" <<endl;
	}
	return 0;
}
