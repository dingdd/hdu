#include <iostream>
#include <iomanip>
#include <algorithm>

struct Trade{
	int J,F;
};

bool compare(struct Trade t1, struct Trade t2){
	if (t1.F == 0){
		return true;
	}
	if (t2.F == 0){
		return false;
	}
	if ( t1.J * t2.F - t2.J * t1.F > 0)
		return true;
	return false;
}

int main(){
	using namespace std;
	int M,N;
	struct Trade trades[1000];

	while(cin >>M >>N && M != -1 && N != -1){
		for(int i=0;i<N;++i){
			cin >> trades[i].J >> trades[i].F;
		}
		sort(trades,trades+N,compare);
		double sum = 0.0;
		for(int i=0;i<N&&M>=0;++i){
			if (M >= trades[i].F){
				sum += trades[i].J;
				M -= trades[i].F;
			}else {
				sum += 1.0 * trades[i].J * M / trades[i].F;
				M = 0;
			}
		}
		cout <<fixed <<setprecision(3) <<sum <<endl;
	}
	return 0;
}
