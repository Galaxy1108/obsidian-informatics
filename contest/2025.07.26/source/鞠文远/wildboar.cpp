#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005,INF=0x3f3f3f3f3f3f3f3f;
struct Edge{int v,w;};
struct dfspos{int u,fr,pos;};
vector<Edge>vec[N];
map<pair<int,pair<int,int>>,int>mp;
map<pair<int,pair<int,int>>,int>sp;
int n,m,t,l,x[N],dg[N];
#define mk make_pair
void bfs(int xr)
{
	pair<int,pair<int,int>> zt;
	zt=make_pair(xr,make_pair(0,2));
	mp[zt]=0;
	queue<pair<int,pair<int,int>>>vb;
	vb.push(zt);
	while(!vb.empty())
	{
		pair<int,pair<int,int>> u=vb.front();
		vb.pop();
		for(int i=0;i<vec[u.first].size();i++)
		{
			int v=vec[u.first][i].v,w=vec[u.first][i].w;
			if(v==u.second.first)continue;
			if(!mp.count(mk(v,mk(u.first,v==x[u.second.second]+u.second.second)))||mp[mk(v,mk(u.first,v==x[u.second.second]+u.second.second))]>mp[u]+w)
			{
				mp[mk(v,mk(u.first,v==x[u.second.second]+u.second.second))]=mp[u]+w,vb.push(mk(v,mk(u.first,v==x[u.second.second]+u.second.second)));
			}
		}
	}
}
int dfs(int pos,int frm,int av)
{
	
	pair<int,pair<int,int>>zt=make_pair(pos,make_pair(frm,av));
	sp[zt]=true;
	if(mp.count(zt))return mp[zt];
	if(av==l+1)return mp[zt]=0;
	int res=INF;
	for(int i=0;i<vec[pos].size();i++)
	{
		int nv=vec[pos][i].v,nw=vec[pos][i].w;
		if(nv==frm)continue;
		if(!sp.count(make_pair(nv,make_pair(pos,av+(nv==x[av])))))res=min(res,nw+dfs(nv,pos,av+(nv==x[av])));
	}
	return mp[zt]=res;
}
signed main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	cin>>n>>m>>t>>l;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		vec[a].push_back({b,c});
		vec[b].push_back({a,c});
	}
	for(int i=1;i<=l;i++)cin>>x[i];
	while(t--)
	{
		mp.clear();
		sp.clear();
		int a,b;
		cin>>a>>b;
		x[a]=b;
		int anslt=dfs(x[1],0,2);
		cout<<(anslt==INF?-1:anslt)<<"\n";
		//bfs(x[1]);
		//int anslt=INF;
		//for(int i=1;i<=n;i++)
		//	for(int j=1;j<=n;j++)
		//		if(mp.count(mk(i,mk(j,l+1))))anslt=min(anslt,mp[mk(i,mk(j,l+1))]);
		//cout<<anslt;
	}
	
	return 0;
} 
