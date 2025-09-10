#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair 
#define vi vector<int>
#define pb emplace_back
#define ps emplace
using namespace std;
constexpr int N=1e5+5,M=3e5+5,inf=1e9;
bool m1;
int n,m;
pii e[M];
vi g[N];
int d[N];
struct node{
	int val,id;
	node(){}
	node(int val,int id):val(val),id(id){}
};
bool operator<(node x,node y){return x.val<y.val;}
priority_queue<node>q;
int ans;
map<pii,bool>mp;
bool m2;
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
//	cerr<<1.0*fabs(&m1-&m2)/1024.0/1024.0<<"MB\n";
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>e[i].fi>>e[i].se,g[e[i].fi].pb(e[i].se),g[e[i].se].pb(e[i].fi),d[e[i].fi]++,d[e[i].se]++;
	for(int i=1;i<=n;i++)
		if(d[i]>=2)
			q.ps(d[i],i);
	while(!q.empty())
	{
		int u=q.top().id;
		q.pop();
		while(1)
		{
			int mx1=0,id1=-1;
			int mx2=0,id2=-1;
			for(auto v:g[u])
				if(!mp[mkp(u,v)])
				{
					if(mx1<d[v])
						mx2=mx1,id2=id1,mx1=d[v],id1=v;
					else if(mx2<d[v])
						mx2=d[v],id2=v;
				}
			if(~id2)
				ans++,mp[mkp(id1,u)]=mp[mkp(id2,u)]=mp[mkp(u,id1)]=mp[mkp(u,id2)]=1;
			else
				break;
		}
	}
	cout<<ans;
	return 0;
}
