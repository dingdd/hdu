#include <iostream>
#include <string>

using namespace std;
bool isVowel(char c) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			return true;
		return false;
}

bool containsVowel(const string& s){
	for(int i=0;i<s.length();++i){
		if (isVowel(s[i]))
			return true;
	}
	return false;
}

bool containsThreeConsecutive(const string& s){
	int l = s.length() - 2;
	for(int i=0;i<l;++i){
		if(isVowel(s[i]) && isVowel(s[i+1]) && isVowel(s[i+2]))
			return true;
		if(!isVowel(s[i]) && !isVowel(s[i+1]) && !isVowel(s[i+2]))
			return true;
	}
	return false;
}

bool containsTwoSameLetter(const string& s){
	int l = s.length() - 1;
	for(int i=0; i<l;++i){
		if (s[i] == s[i+1]){
			if (s[i] == 'e' || s[i] == 'o')
				continue;
			return true;
		}
	}
	return false;
}

int main(){
	string s,end("end");
	while(cin >>s) {
		if (end == s)
			break;
		if (!containsVowel(s) || containsThreeConsecutive(s) 
				|| containsTwoSameLetter(s))
			cout <<"<" <<s <<"> is not acceptable." <<endl;
		else
			cout <<"<" <<s <<"> is acceptable." <<endl;
	}
	return 0;
}
