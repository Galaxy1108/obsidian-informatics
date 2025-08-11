#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005,L=20;
struct T
{
	int ne,to,v;
}e[2*N];
vector<int>v[2*N];
int he[N],idx,fa[N][L+2],d[N],id[N],f[N],c[N],up[N];
int vis[N];
void add(int x,int y)
{
	e[++idx].ne=he[x];
	e[idx].to=y;
	he[x]=idx;
}
void dfs(int x,int fat)
{
	fa[x][0]=fat;
	d[x]=d[fat]+1;
	for(int i=he[x];i;i=e[i].ne)
	{
		int y=e[i].to;
		if(y==fat)continue;
		f[y]=f[x]+e[i].v;
		up[y]=i;
		dfs(y,x);
	}
}
int lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	for(int i=L;i>=0;i--)
		if(d[fa[x][i]]>=d[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=L;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
signed main()
{
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,T;
	cin>>n>>m>>T;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		id[i]=idx;
		add(y,x);
	}
	bool flag=1;
	int lst=0;
	for(int i=1;i<=m;i++)
	{
		int t,u;
		cin>>t>>u;
		if(lst==0)lst=u;
		else if(lst!=u)flag=0;
		e[id[t]].v+=u;
		e[id[t]+1].v+=u;
		v[id[t]].push_back(u);
		v[id[t]+1].push_back(u);
	}
	dfs(1,0);
	fa[1][0]=1;
	for(int j=1;j<=L;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	while(T--)
	{
		int s,t,x,y;
		cin>>s>>t>>x>>y;
		if(flag)
		{
			int sum=f[s]+f[t]-2*f[lca(s,t)];
			sum/=lst;
			y/=lst;
			int ans=x-max(0ll,sum-y);
			if(ans<0)cout<<-1<<'\n';
			else cout<<ans<<'\n';
		}
		else
		{
			int top=0,u=lca(s,t);
			while(s!=u)
			{
				int p=up[s];
				for(int j=0;j<v[p].size();j++)
					c[++top]=v[p][j];
				s=fa[s][0];
			}
			while(t!=u)
			{
				int p=up[t];
				for(int j=0;j<v[p].size();j++)
					c[++top]=v[p][j];
				t=fa[t][0];
			}
			sort(c+1,c+top+1);
			for(int i=1;i<=top;i++)
			{
				if(c[i]<=y)y-=c[i];
				else x--;
			}
			if(x<0)cout<<"-1\n";
			else cout<<x<<'\n';
		}
	}
	return 0;
}
/*
10 10 100
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
1 2
1 2
1 2
1 2
2 2
5 2
9 2
9 2
9 2
6 2
*/
