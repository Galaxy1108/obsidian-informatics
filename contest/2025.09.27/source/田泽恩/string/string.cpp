#include <bits/stdc++.h>
using namespace std;
string s;
int n;
bool check(){
	for(int i=1;i<s.size();++i){
		if(s[i]==s[i-1]) return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	/*n=s.size();
	s=" "+s;*/
	if(check()) cout<<0;
	else cout<<-1;
	return 0;
}
