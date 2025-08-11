#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,sum=0,ans=0;
string s;
void dfs(int x,string s1){
	if(x==3*n){
		int t=0;
		for(int i=2;i<3*n;i++){
			if(s1[i-2]=='A'&&s1[i-1]=='B'&&s1[i]=='C'||s1[i-2]=='B'&&s1[i-1]=='C'&&s1[i]=='A'||s1[i-2]=='C'&&s1[i-1]=='B'&&s1[i]=='A')t++;
		}
		if(t==n){
			cout<<s1<<endl;
			ans++;
		} 
		ans%=mod;
		return;
	}
	if(s[x]!='?') {
		s1+=s[x];
		dfs(x+1,s1);
		return;
	}
	s1+="A";
	dfs(x+1,s1);
	s1[x]='B';
	dfs(x+1,s1);
	s1[x]='C';
	dfs(x+1,s1); 
}
int main(){
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=0;i<3*n;i++){
		if(s[i]!='?'){
			sum++;
		}
	}
	if(n<=60){
		string s1;
		dfs(0,s1);
		cout<<ans<<endl;
	} 
	return 0;
} 
