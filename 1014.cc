#include <iostream>
#include <utility>

using namespace std;

int gcd(int s, int m){
	if (m > s)
		swap(m, s);
	if (m==0)
		return s;
	return gcd(m, s%m);
}

int main(){
	int step, module;
	while(cin >>step >>module){
		cout.width(10);
		cout <<step;
		cout.width(10);
		cout <<module;
		cout <<"    ";
		if (gcd(step, module) >1)
			cout <<"Bad Choice" <<endl;
		else 
			cout <<"Good Choice" <<endl;
		cout <<endl;
	}
	return 0;
}
