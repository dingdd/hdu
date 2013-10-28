#include <iostream>
#include <string>
#include <vector>

using namespace std;
class BinaryCode
{
  public:
    vector<string> decode(string);
};

vector<string> BinaryCode::decode(string m){
  vector<string> codes;
  int n=m.size();
	string s(n+2, '0');
	for(int i=0,j;i<2;i++){
		s[1]='0'+i;
		for(j=2;j<n+2;j++){
			s[j]=m[j-2]-s[j-1]-s[j-2]+'0'+'0';
			if(s[j]!='0'&&s[j]!='1')
				break;
		}
		if(j==(n+2)&&s[j-1]=='0')
			codes.push_back(string(s.begin()+1, s.begin()+n+1));
		else
			codes.push_back("None");
	}
	return codes;
}
		
int main(void)
{
  BinaryCode b;
  vector<string> svec;
	string s;
	while(cin>>s){
		svec=b.decode(s);
		cout<<svec[0]<<"\t"<<svec[1]<<endl;
	}
  return(0);
}
