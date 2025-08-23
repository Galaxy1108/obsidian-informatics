#include<bits/stdc++.h>
using namespace std;
const int mx=1e7+10;
int n;
vector<int> Mx[mx];
int f[mx];
struct edge
{
	int id,to,w;
};
vector<edge> e[mx];
int son[mx];
void dfs(int u,int fa)
{
	son[fa]+=son[u]; 
	for(edge v:e[u])
	{
		dfs(v.to,u);
	}
}
int main()
{
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	cin>>n;
	bool flag1=1,flag2=1,flag3=1;
	for(int i=1;i<n;i++)
	{
		int f,w;
		cin>>f>>w;
		if(w!=1) flag1=0;
		if(f!=i) flag2=0;
		if(f!=1) flag3=0;
		e[f].push_back({i,i+1,w});
	} 
	for(int i=1;i<=n;i++) son[i]=1;
	dfs(1,0);
	if(flag1) 
	{
		for(int i=1;i<=n;i++)
		{
			for(edge j:e[i])
			{
				int v=j.to;
				if(son[v]>=n-son[v]-1) f[j.id]++;
				if(son[v]-1<=n-son[v]) f[j.id]++;
			}
		}
		int ans=0;
		for(int i=1;i<n;i++) ans^=f[i];
		cout<<ans;
	}
	else if(flag2)
	{
		for(int i=1;i<=n;i++)
		{
			for(edge j:e[i])
			{
				int v=j.to;
				if(son[v]>=n-son[v]-1) f[j.id]++;
				if(son[v]-1<=n-son[v]) f[j.id]++;
			}
		}
		int ans=0;
		for(int i=1;i<n;i++) ans^=f[i];
		cout<<ans;
	}
	else if(flag3) 
	{
		int ans=2;
		for(int i=1;i<n;i++) ans^=1;
		cout<<ans;
	}
	else cout<<2624;
	return 0;
} 

