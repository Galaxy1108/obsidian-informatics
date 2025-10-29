#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1005;
int a[N],b[N],n,ans,vis[N],t[N];
unordered_map<ll,int>mp;
void dfs(int k)
{
	if(k>2*n)
	{
		for(int i=1;i<=n;i++)
			b[i]=min(a[i*2],a[i*2-1]);
		ll sum=0;
		for(int i=1;i<=n;i++)
			sum=(sum*11+b[i])%1000000000000000;
		if(!mp[sum])ans++;
		mp[sum]=1;
		return;
	}
	if(t[k])
	{
		dfs(k+1);
		return;
	}
	for(int i=1;i<=2*n;i++)
	{
		if(vis[i])continue;
		a[k]=i;
		vis[i]=1;
		dfs(k+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=2*n;i++)cin>>a[i];
	for(int i=1;i<=2*n;i++)
		if(a[i]!=-1)vis[a[i]]=1,t[i]=1;
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}
