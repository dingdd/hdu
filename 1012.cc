#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	cout <<"n e" <<endl;
	cout <<"- -----------" <<endl;
	cout <<"0 1" <<endl;
	cout <<"1 2" <<endl;
	cout <<"2 2.5" <<endl;
	double epison = 2.5;
	int ibang = 2;
	for(int i=3;i<10;++i){
		ibang *= i;
		epison += 1.0/ibang;
		cout <<i <<" " <<fixed <<setprecision(9) <<epison <<endl;
	}
	return 0;
}
