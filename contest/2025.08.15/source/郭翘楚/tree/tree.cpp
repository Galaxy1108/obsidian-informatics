#include <bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+5;
int fa[MAXN],g[MAXN];
int w[MAXN];
int a[MAXN];
vector <int> p[MAXN];
int ans=-1;
void dfs(int x,int sum)
{
	if(p[x].empty()) return;
	ans=max(ans,sum);
	for(auto i:p[x])
	{
		dfs(i,w[i]+sum+a[i]);
	}
	return;
}
int main()
{
	freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
	int n;
	cin>>n;
	for(int i=2;i<n;i++)
	{
		cin>>fa[i];
		p[fa[i]].push_back(i);
	}
	w[1]=1;
	for(int i=2;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<n;i++)
	{
		cin>>g[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
//		ans=-1;
//		dfs(i,a[i]);
//		cout<<ans<<" ";
		cout<<0<<" ";
	}
}
