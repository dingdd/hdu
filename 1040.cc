#include <iostream>
#include <algorithm>

using namespace std;

int arr[1010];

int main(){
	int T;
	cin >>T;
	while(T--){
		int N;
		cin >>N;
		for(int i=0;i<N;++i)
			cin >>arr[i];
		sort(arr, arr+N);
		for(int i=0;i<N;++i){
			if (i)
				cout <<" ";
			cout <<arr[i];
		}
		cout <<endl;
	}
	return 0;
}
