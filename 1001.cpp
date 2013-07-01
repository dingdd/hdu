#include <iostream>

using namespace std;

int main(){
	int n;
	while(cin>>n){
		n=(n%2)?(n+1)/2*n:n/2*(n+1);
		cout << n << endl << endl;
	}
	return 0;
}
