#include <iostream>

using namespace std;

int a[10000],b[10000];
int n;

bool allSame(){
	if (n<2)
		return true;
	for(int i=1;i<n;++i)
		if(a[i]!=a[0])
			return false;
	return true;
}

int main(){
	while(cin >>n) {
		if (!n)
			return 0;
		for(int i=0;i<n;++i){
			cin >>a[i];
		}
		int t=0;
		while(!allSame()){
			t++;
			for(int i=0;i<n;++i){
				b[i]=a[i]/2;
				a[i]=b[i];
			}
			for(int i=0;i<n;++i){
				a[i]=a[i]+b[(i+1)%n];
				if (a[i]%2)
					a[i]++;
			}
		}
		cout <<t <<" " <<a[0] <<endl;
	}
	return 0;
}

