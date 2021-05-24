#include <iostream>

using namespace std;

int main(){
	int n,t;
	int ans,cnt;
	while(cin >>n){
		cnt=0;
		while(n--){
			cin >>t;
			if (cnt==0)
				ans=t,cnt++;
			else if (ans==t)
				cnt++;
			else 
				cnt--;
		}
		cout <<ans <<endl;
	}
	return 0;
}
