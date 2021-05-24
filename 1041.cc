#include <iostream>

using namespace std;

struct BigNum {
	int digit[1000];
	BigNum(){
		for(int i=0;i<1000;++i)
			digit[i] = 0;
	}
};

BigNum operator+ (const BigNum &lhs, const BigNum & rhs){
	BigNum r;
	for(int i=0;i<1000;++i){
		r.digit[i] += lhs.digit[i] + rhs.digit[i];
		r.digit[i+1] += r.digit[i]/10;
		r.digit[i] = r.digit[i]%10;
	}
	return r;
}

ostream& operator<<(ostream& os, BigNum r){
	int i=999;
	while(i>0  && r.digit[i]==0)
		i--;
	while(i>=0){
		os <<r.digit[i--];
	}
	return os;
}

BigNum F[1010],G[1010];

int main() {
	BigNum one;
	one.digit[0]=1;
	for (int i=1;i<1001;++i){
		if(i%2 == 0){
			F[i] = F[i-1] + G[i-1] + one;
		}else {
			F[i] = F[i-1] + G[i-1];
		}
		G[i] = F[i-1] + G[i-1];
	}
	int n;
	while(cin >> n)
		cout <<F[n] <<endl;
	return 0;
}
