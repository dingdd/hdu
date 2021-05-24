#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	int n,id;
	double d;
	cin >>n >>d;
	vector<string> vs(n);
	while(cin >>id){
		bool invalid = false;
		int seconds = 0;
		for(int i=0;i<n;++i){
			cin >>vs[i];
			if (vs[i][0]=='-')
				invalid = true;
			else {
				vs[i][1] = ' ';
				vs[i][4] = ' ';
				stringstream ss(vs[i]);
				int H,MM,SS;
				ss >>H >>MM >>SS;
				seconds += H*3600 + MM*60 + SS;
			}
		}
		if (invalid) {
			cout <<setfill(' ') <<setw(3) <<id <<": -" <<endl;
		}else {
			seconds = round(seconds/d);
			cout <<setfill(' ') <<setw(3) <<right <<id <<": " 
				<<seconds/60 <<":"
			  <<setfill('0') <<setw(2) <<seconds%60 <<" min/km" <<endl;
		}
	}
	return 0;
}
