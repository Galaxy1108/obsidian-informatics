#include<bits/stdc++.h>
using namespace std;
int n,a[105],m,b[105];
string s,t;
set<string> st;
bool c[105];
void dfs(int nx){
	if(nx==n+1){
		string A="";
		for(int i=1;i<=n;i++){
			if(c[i]) A+=s[i-1];
		}
		if(A!="") st.insert(A); 
		return;
	}
	for(int i=0;i<=1;i++) c[nx]=i,dfs(nx+1);
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s+=to_string(a[i]);
	cin>>m;
	for(int i=1;i<=m;i++) cin>>b[i],t+=to_string(b[i]);
	dfs(1);
	int cnt=0;
	for(auto i:st){
		cnt++;
		if(i==t){
			cout<<cnt;
			return 0;
		}
	}
	return 0;
}
//4 
//1 2 4 1 
//1 
//2
