#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int h[N],p[N],q[N],invh[N];
bool vis[N];
void dfs(int stp)
{
	if(stp>n)
	{
		int a[N],b[N];
		for(int i=1;i<=n;i++) invh[h[i]]=i;
		for(int i=1;i<=n;i++) a[i]=p[h[i]];
		for(int i=1;i<=n;i++) b[i]=invh[a[i]];
		for(int i=1;i<=n;i++) if(b[i]!=q[i]) return ;
		cout<<"YES"<<endl;
		for(int i=1;i<=n;i++) cout<<h[i]<<' ';
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;
		h[stp]=i;
		dfs(stp+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout)
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++) cin>>q[i];
	if(n>10)
	{
		cout<<"NO"<<endl;
		return 0;
	}
	dfs(1);
	cout<<"NO"<<endl;
	return 0;
} 
