#include<bits/stdc++.h>
using namespace std;
int n,m,ans,mod=998244353;
int a[1000010],b[1000010],f[1000010];
void dfs1(int flag,int to){
	if(to==n){
		return;
	}
	for(int i=to+1;i<=n;i++){
		if(f[i]==1&&flag==1) return;
		else{
			ans++;
			dfs1(0,i);
		}
	}
}
void dfs(int x){
	if(x-1==m){
		dfs1(1,0);
	} 
	for(int i=1;i<=n;i++){
		if(f[i]==0&&a[i]==b[x]){
			f[i]=1;
			dfs(x+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	dfs(1);
	ans%=mod;
	printf("%d",ans);
	return 0;
}
