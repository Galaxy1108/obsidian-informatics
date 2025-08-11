#include<bits/stdc++.h>
using namespace std;
const int N=2005;
struct T
{
	int ne,to,v;
}e[2*N];
int he[N],idx,x[N],d[N],f[N],vis[N],q[N*N];
void add(int x,int y,int z)
{
	e[++idx].ne=he[x];
	e[idx].to=y;
	e[idx].v=z;
	he[x]=idx;
}
void spfa(int u,int v,int lst)
{
	//cout<<u<<' '<<v<<' '<<lst<<'\n';
	int l=1,r=0;
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[u]=0;
	q[++r]=u;
	while(r>=l)
	{
		int x=q[l];l++;
		//cout<<"___"<<x<<' '<<d[x]<<'\n';
		vis[x]=0;
		for(int i=he[x];i;i=e[i].ne)
		{
			int y=e[i].to;
			if(x==v&&y==lst)continue;
			//	cout<<x<<' '<<y<<'\n';
			if(d[y]>d[x]+e[i].v)
			{
				d[y]=d[x]+e[i].v;
				if(!vis[y])
				{
					vis[y]=1;
					q[++r]=y;
				}
			}
		}
	}
}
int dfs(int x,int u,int lst,int k)
{
	if(f[x]!=-1)return f[x];
	if(k!=d[x])return 0;
	if(!d[x])return 1;
	f[x]=0;
	for(int i=he[x];i;i=e[i].ne)
	{
		int y=e[i].to;
		if(x==u&&y==lst)continue;
		f[x]+=dfs(y,u,lst,k-e[i].v);
	}
	return f[x];
}
int main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,T,p;
	cin>>n>>m>>T>>p;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=p;i++)cin>>x[i];
	while(T--)
	{
		int u,v;
		cin>>u>>v;
		int t=x[u],lst=0,ans=0,flag=0;
		x[u]=v;
		for(int i=2;i<=p;i++)
		{
			spfa(x[i-1],x[i-1],lst);
			//cout<<d[x[i]]<<'\n';
			if(d[x[i]]>1e9)
			{
				flag=1;
				break;
			}
			ans+=d[x[i]];
			memset(f,-1,sizeof(f));
			dfs(x[i],x[i-1],lst,d[x[i]]);
			//cout<<"---"<<f[x[i]]<<'\n';
			if(f[x[i]]>1)lst=0;
			else
			{
				//cout<<x[i]<<' '<<he[x[i]]<<' '<<"!\n";
				for(int j=he[x[i]];j;j=e[j].ne)
				{
					int y=e[j].to;
					//cout<<i<<' '<<y<<' '<<f[y]<<'\n';
					if(x[i]==lst&&y==x[i-1])continue;
					if(f[y]==1||y==x[i-1])
					{
						lst=y;
						//cout<<lst<<"!!!!\n";
						break;
					}
				}
			}
		}
		x[u]=t;
		if(flag)ans=-1;
		cout<<ans<<'\n';
	}
	return 0;
}
