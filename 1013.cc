#include <iostream>
#include <string>

using namespace std;

int digitRoot(int n){
	if(n <10)
		return n;
	int sum=0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	return digitRoot(sum);
}

int digitRoot(string &s){
	int sum = 0;
	for(int i=0;i<s.size();++i){
		sum+=s[i]-'0';
	}
	return digitRoot(sum);
}

int main(){
	string s;
	while(cin >>s) {
		if (s == "0")
			break;
		cout <<digitRoot(s) <<endl;
	}
	return 0;
}
