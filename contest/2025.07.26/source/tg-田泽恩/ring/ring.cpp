#include <bits/stdc++.h>
using namespace std;
long long n,m[229028],lft[229028],rit[229028],a[229028],b[229028],ans=0x3f3f3f3f3f3f3f3f,x[229028];
void dfs(int now){
	if(now>n){
		x[n+1]=x[1];
		long long res=0;
		for(int i=0;i<=rit[n+1]+1;++i) b[i]=a[i];
		for(int i=1;i<=n;++i){
			sort(b+x[i]+lft[i]-1,b+x[i+1]+lft[i+1]-1);
			for(int j=x[i]+lft[i]-1;j<x[i+1]+lft[i+1]-2;++j){
				res+=(b[j+1]-b[j])*(b[j+1]-b[j]);
			}
		}
		ans=min(ans,res);
		return;
	}
	for(int i=1;i<=m[now];++i){
		x[now]=i;
		dfs(now+1);
	}
}
int main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>m[i];
		lft[i]=rit[i-1]+3;
		rit[i]=lft[i]+m[i]-1;
		a[lft[i]-1]=0;
		a[rit[i]+1]=2e6;
		for(int j=lft[i];j<=rit[i];++j){
			cin>>a[j];
		}
	}
	m[n+1]=m[1];
	lft[n+1]=rit[n]+3;
	rit[n+1]=lft[n+1]+m[1]-1;
	a[lft[n+1]-1]=0;
	a[rit[n+1]+1]=2e6;
	for(int i=1;i<=m[1];++i) a[lft[n+1]+i-1]=a[lft[1]+i-1];
	dfs(1);
	cout<<ans;
	return 0;
}
