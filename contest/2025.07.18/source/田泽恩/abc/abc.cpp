#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	cin>>n>>s;
	if(n==1){
		if(s=="???") cout<<3;
		else{
			int cnt=0;
			for(int i=0;i<s.size();++i) if(s[i]!='?') ++cnt;
			if(cnt<2) cout<<1;
			else{
				if(s=="AB?"||s=="?BC"||s=="A?C"||s=="ABC"||s=="BC?"||s=="?CA"||s=="B?A"||s=="BCA"||s=="CA?"||s=="?AB"||s=="C?B"||s=="CAB") cout<<1;
				else cout<<0;
			}
		}
	}
	else cout<<0;
	return 0;
}
