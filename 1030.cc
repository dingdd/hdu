#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N,M;
	int Fn,Rn,Cn,Fm,Rm,Cm;
	while(cin >>N >>M){
		Fn = sqrt(N-1);
		Cn = (N-Fn*Fn-1)/2;
		Rn = Fn-(N-Fn*Fn)/2;
		Fm = sqrt(M-1);
		Cm = (M-Fm*Fm-1)/2;
		Rm = Fm-(M-Fm*Fm)/2;
		cout << abs(Fm-Fn)+abs(Cm-Cn)+abs(Rm-Rn) <<endl;
	}
	return 0;
}
