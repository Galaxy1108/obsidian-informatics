#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
constexpr int N=15;
int n,a[N],na[N];
bool vis[N];
map<vi,bool>mp;
void dfs(int x)
{
	if(x==n*2+1)
	{
		vi b(n+1);
		for(int i=1;i<=n;i++)
			b[i]=min(na[(i<<1)-1],na[i<<1]);
		// for(int i=1;i<=n;i++)cout<<b[i]<<(i==n?'\n':' ');
		if(!mp.count(b))mp[b]=1;
		return;
	}
	if(~a[x])
	{
		na[x]=a[x];
		dfs(x+1);
		return;
	}
	for(int i=1;i<=n*2;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			na[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n*2;i++)
	{
		cin>>a[i];
		if(~a[i])vis[a[i]]=1;
	}
	dfs(1);
	cout<<mp.size();
	// for(int _=1;_<=5;_++)
	// {
	// 	n=_;
	// 	for(int i=1;i<=_*2;i++)a[i]=-1;
	// 	mp.clear();
	// 	dfs(1);
	// 	cerr<<_<<":"<<mp.size()<<'\n';
	// }
	return 0;
}