#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Sum{
	int id;
	double sum;
	Sum():id(0),sum(.0){}
};

bool operator< (const Sum &lhs, const Sum &rhs){
	if (lhs.sum > rhs.sum)
		return false;
	else if(lhs.sum < rhs.sum)
		return true;
	if (lhs.id > rhs.id)
		return true;
	else
		return false;
}

int main(){
	int N,M,K;
	double v;
	while(cin >>N >>M >>K){
		vector<Sum> vs(M);
		for(int i=0;i<M;++i)
			vs[i].id = i+1;
		for(int i=0;i<N;++i){
			for(int j=0;j<M;++j){
				cin >> v;
				vs[j].sum += v;
			}
		}
		sort(vs.begin(),vs.end());
		vector<int> res;
		for (int i=0;i<K;++i){
			res.push_back(vs[M-1-i].id);
		}
		sort(res.begin(), res.end());
		for (int i=K-1;i>0;--i)
			cout << res[i] <<" ";
		if (res.size() >0)
			cout << res[0];
		cout <<endl;
	}
	return 0;
}
