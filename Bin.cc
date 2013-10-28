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
    int n=m.size(),i;
    string s1(n+2,'0');
    string s2(n+2,'0');
    s2[1]='1';
    for( i=2;i<n+1;i++){
        s1[i]=m[i-2]-s1[i-1]+'0'-s1[i-2]+'0';
        if(s1[i]!='0'&&s1[i]!='1'){
            codes.push_back("None");
            break;
        }
    }
    if(s1[i]=='0'||s1[i]=='1'){
        string s(s1.begin()+1,s1.begin()+n+1);
        codes.push_back(s);
    }
    for(i=2;i<n+1;i++){
        s2[i]=m[i-2]-s2[i-1]+'0'-s2[i-2]+'0';
        if(s2[i]!='0'&&s2[i]!='1'){
            codes.push_back("None");
            break;
        }
    }
    if(s2[i]=='0'||s2[i]=='1'){
        string s(s2.begin()+1,s2.begin()+n+1);
        codes.push_back(s);
    }
    return codes;
}

int main(void)
{
  BinaryCode b;
  vector<string> svec;
  svec=b.decode("123210120");
  cout<<svec[0]<<endl;
  cout<<svec[1]<<endl;
  return(0);
}
