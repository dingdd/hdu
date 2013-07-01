#include <iostream>

using namespace std;

int a[100000];

int main(){
	int l,lh,rh,n,N,sum,ls;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>n;
		for(int j=0;j<n;j++)
			cin>>a[j];
		lh=0,rh=1;
		sum=a[0];
		ls=sum;
		l=0;
		if(ls<0)
			l=1,ls=0;
		for(int j=1;j<n;j++){
			ls+=a[j];
			if(ls>sum)
				sum=ls,lh=l,rh=j+1;
			if(ls<0)
				l=j+1,ls=0;
		}
		cout << "Case "<< i+1 << ":" << endl << sum << " " << lh+1 << " " << rh << endl ;
		if(i<N-1)
			cout << endl;
	}
	return 0;
}
			
