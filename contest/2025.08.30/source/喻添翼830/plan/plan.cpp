#include<bits/stdc++.h>
using namespace std;
const int mx=510;
int n,k;
vector<int> e[mx];
int a[mx];
int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
int f[mx][mx],siz[mx],Gcd[mx];
bool vis[mx];
void dfs0(int u,int fa)
{
	siz[u]=1,Gcd[u]=a[u];
	for(int v:e[u])
	{
		if(v!=fa) 
		{
			dfs0(v,u);
			siz[u]+=siz[v];
		}
	}
}
void dfs(int u,int fa)
{
	vis[u]=1;
	for(int i=0;i<=min(k,siz[u]-1);i++)
	{
		for(int v:e[u])
		{
			if(v!=fa)
			{
				for(int j=0;j<=min(i-1,siz[v]-1);j++)
				{
					if(!vis[v]) dfs(v,u);
					f[u][i]=max(f[u][i],f[v][j]+f[u][i-j-1]);
				}
			}
			Gcd[u]=gcd(Gcd[v],Gcd[u]);
			f[u][0]=Gcd[u];
		}
	} 
}
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs0(1,0);
	for(int i=1;i<=n;i++) f[i][0]=Gcd[i];
	dfs(1,0);
	cout<<f[1][k];
	return 0;
} 

