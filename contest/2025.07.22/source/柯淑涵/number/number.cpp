#include <bits/stdc++.h>
using namespace std;
int T,n,m,f[2001][2001],a[2001],ans=-1e9;
void dfs(int x,int b,int c){
	if(x==m+1){
		ans=max(ans,b+c);
		return;
	}
	dfs(x+1,a[x]-b,c);
	dfs(x+1,b,a[x]-c);
}
void dfs(int x,int b){
	if(x==m+1){
		ans=max(ans,b);
		return;
	}
	dfs(x+1,a[x]-b);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		if(m<=20){
			int b,c;
			if(m==2) dfs(1,0,0);
			else dfs(1,0);
			cout<<ans<<endl;
			continue;
		}
		int b[2001];
		for(int i=1;i<=m;i++){
			sort(b+1,b+1+n);
			b[1]=a[i]-b[1];
		}
		for(int i=1;i<=n;i++){
			ans+=b[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
