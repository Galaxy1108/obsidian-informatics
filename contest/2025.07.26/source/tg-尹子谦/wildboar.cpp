#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2000,L=2e5+10,INF=0x3f3f3f3f;
int n,m,t,l,x[L],fa[N],dis[N];
bool vis[N];
struct EDGE
{
	int v;
	int w;
	bool operator<(const EDGE &oth)const
	{
		return w>oth.w;
	}
};
vector<EDGE> edge[N];
priority_queue<EDGE> pq;
void dij(int st)
{
	dis[st]=0;
	pq.push({st,0});
	while(pq.size())
	{
		int u=pq.top().v;
		pq.pop();
		if(vis[u]) continue;
		//vis[u]=1;
		for(EDGE i:edge[u])
		{
			int w=i.w,v=i.v;
			if(fa[u]==v)
			{
				//cout<<u<<"不能回到他的父亲"<<v<<endl; 
				continue;
			} 
			if(dis[u]+w<dis[v]&&dis[u]!=INF)
			{
				//cout<<"从"<<u<<"到"<<v<<"的路更短，选他"<<endl; 
				fa[v]=u;
				dis[v]=dis[u]+w;
				pq.push({v,w});
			}
		}
	}
}
signed main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	cin>>n>>m>>t>>l;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		edge[u].pb({v,w});
		edge[v].pb({u,w});
	}
	for(int i=1;i<=l;i++) cin>>x[i];
	while(t--)
	{
		int p,y,f;
		cin>>p>>y;
		x[p]=y;
		int ans=0;
		for(int i=1;i<l;i++)
		{
			fa[x[i]]=f;
			memset(dis,0x3f,sizeof dis);
			memset(vis,0,sizeof vis);
			dij(x[i]);
			if(dis[x[i+1]]==INF)
			{
				ans=-1;
				break;
			}
			ans+=dis[x[i+1]];
			cout<<ans<<endl<<endl;
			f=fa[x[i+1]];
			memset(fa,0,sizeof fa);
		}
		cout<<ans<<endl;
	}
	return 0; 
}

