#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	double d,s,distance,speed;
	int r;
	int n=0;

	while(cin >>d >>r >>s){
		if (r == 0)
			break;
		distance = 3.1415927*d/12/5280*r;
		speed = distance/s*3600;
		cout <<"Trip #" <<++n <<": " <<fixed <<setprecision(2) <<distance
			<<" " <<speed <<endl;
	}
	return 0;
}
