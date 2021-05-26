#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int n){
	if(n < 2)
		return false;
	for(int i=2;i<n;++i)
		if (n%i == 0)
			return false;
	return true;
}

int primeArray[41] = { 0 };

int dfs(int &n, vector<int> &visited, vector<int> &chain){
	if(chain.size()==n){
		if(primeArray[chain[0]+chain[chain.size()-1]]==0)
			return 0;
		for(int i=0;i<chain.size();++i){
			cout <<chain[i];
			if (i!=chain.size()-1)
				cout <<" "; 
		}
		cout <<endl;
		return 0;
	}
	for(int i=1;i<=n;++i){
		if(visited[i])
			continue;
		if(chain.size()>0 && primeArray[chain[chain.size()-1]+i]==0)
			continue;
		visited[i]=1;
		chain.push_back(i);
		dfs(n,visited,chain);
		chain.pop_back();
		visited[i]=0;
	}
	return 0;
}
		

int main(){
	for(int i=0;i<41;++i)
		if (isPrime(i))
			primeArray[i] = 1;

	int n,t=1;
	while(cin >>n){
		cout <<"Case " <<t++ <<":" <<endl;
		if(n%2==0){
			vector<int> visited(n+1, 0);
			vector<int> chain(1, 1);
			visited[1]=1;
			dfs(n, visited, chain);
		}
		cout <<endl;
	}
	return 0;
} 
