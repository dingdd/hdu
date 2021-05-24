#include <iostream>

using namespace std;

int F[121][121] = {0};

int main(){
	for(int i=1;i<121;++i)
		F[i][1]=1;
	F[0][0]=1;
	for(int i=1;i<121;++i){
		for(int j=2;j<=i;++j){
			for(int k=0;k<=j;++k){
				F[i][j]+=F[i-j][k];
			}
		}
	}
	int n;
	while(cin >>n){
		int sum=0;
		for(int i=0;i<=n;++i){
			sum += F[n][i];
		}
		cout <<sum <<endl;
	}
	return 0;
}

