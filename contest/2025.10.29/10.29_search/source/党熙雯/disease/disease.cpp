#include<bits/stdc++.h>
using namespace std;
const int mx=320;
int n,p;
int fa[mx],vis[mx],g[mx];
struct edge
{
	int to,nxt;
}e[2*mx];
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
int h[mx],cnt;
void build(int u,int v)
{
	 e[++cnt].to=v;
	 e[cnt].nxt=h[u];
	 h[u]=cnt;
}
void getfather(int u,int f)
{
	fa[u]=f;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==f) continue;
		getfather(v,u);
	}
}//O(n)
void bj(int u)
{
	vis[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa[u]) continue;
		bj(v); 
	}
}//O(n)
void jbj(int u)
{
	vis[u]=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa[u]) continue;
		jbj(v);
	}
}//O(n)
void gr(int u)
{
	if(vis[u]==1) return ;
	if(g[u]==0)
	{
		g[u]=1;
		return ;
	}
	g[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(vis[v]||v==fa[u]) continue;
		gr(v);
	}
}//O(n)
void jgr(int u)
{
	if(g[u]==0) return ;
	int flag=0;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa[u]) continue;
		flag+=g[v];
		jgr(v);
	}
	if(flag==0) g[u]=0;
}//O(n)
bool comp()
{
	for(int i=2;i<=n;i++)
	{
		if(vis[i]==0&&g[i]==0) return 0;
	}
	return 1;
}//O(n)
int geta(int u)
{
	int ans=0;
	ans+=g[u];
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa[u]) continue;
		ans+=geta(v);
	}
	return ans;
}//O(n)
int ans;
void dfs(int k)
{
//		for(int i=1;i<=n;i++)
//		{
//			cout<<vis[i]<<' '<<g[i]<<endl;
//		}
//		cout<<endl;
	if(comp())
	{
		ans=min(ans,geta(1));
//		cout<<geta(1)<<endl;
		return ;
	 } 
	for(int i=2;i<=n;i++)
	{
		if(g[fa[i]]==1&&g[i]==0&&vis[i]==0)
		{
//			cout<<i<<endl;
			bj(i);
			gr(1);
			dfs(k+1);
			jbj(i);
			jgr(1);
		}
	}
}
int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	n=fread(),p=fread();
	ans=n;
	for(int i=1;i<=p;i++)
	{
		int u=fread(),v=fread();
		build(u,v);
		build(v,u);
	}
	g[1]=1;
	getfather(1,0);
//	for(int i=1;i<=n;i++)
//	cout<<fa[i]<<' ';cout<<endl;
	dfs(1);
	cout<<ans;
	return 0;
}

/*
9 8
1 2 
1 3 
1 4 
2 5 
2 6 
5 8 
5 9
3 7
*/
