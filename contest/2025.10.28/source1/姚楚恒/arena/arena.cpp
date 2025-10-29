#include<bits/stdc++.h>
using namespace std;
int n,x,a[25],t,ans,b[25];
void dfs(int m){
	if(m==n+1){
		t=0;
		for(int i(1);i<=n;++i)a[i]=b[i];
		sort(a+1,a+1+n);
		for(int i(1);i<n;++i){
			while(a[i]-t<=0&&i<n-1)++i;
			a[i]-=t;
			while(a[i]>0)a[i]=a[i]-n+i,t=t+n-i;
		}
		if(a[n]-t<=0)ans=ans==998244352?0:ans+1;
		return;
	}
	for(int i(1);i<=x;++i)b[m]=i,dfs(m+1);
	return;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&x);
	dfs(1);
	printf("%d",ans);
	return 0;
}
