#include <cstdio>
#include <queue>
#include <iostream>
#include <map>
using namespace std;
const int MAXN = 2000 + 12;
int head[MAXN],to[MAXN<<1],nxt[MAXN<<1],len[MAXN<<1],idx[MAXN<<1],cnt;
int n,m;
void add(int u,int v,int w,int id)
{
	cnt++;
	to[cnt] = v;
	nxt[cnt] = head[u];
	len[cnt] = w;
	idx[cnt] = id;
	head[u] = cnt;
}
struct Vertex{
	int u,lst;
	long long dis;
	bool vis;
	bool operator<(const Vertex&rhs) const{
		return dis > rhs.dis;
	}
}V[MAXN*3];
int num[MAXN][MAXN],tlen;
long long dis[MAXN*3][MAXN*3];
priority_queue<Vertex> q;
void di(int s)
{
	for (int i=1;i<=m*2+n;i++)
		V[i].dis = 1e18,V[i].vis = 0;
	V[s].dis = 0;
	q.push(V[s]);
	while (!q.empty())
	{
		int u = q.top().u,lst = q.top().lst;
		q.pop();
		if (V[num[u][lst]].vis) continue ;
		V[num[u][lst]].vis = 1;
		for (int i=head[u];i;i=nxt[i])
		{
			if (idx[i]==lst) continue ;
			int v = to[i],w = len[i],id = idx[i];
			if (V[num[v][id]].dis > V[num[u][lst]].dis + w)
			{
				V[num[v][id]].dis = V[num[u][lst]].dis + w;
				q.push(V[num[v][id]]);
			}
		}
	}
	for (int i=1;i<=m*2+n;i++)
		dis[s][i] = V[i].dis;
}
int t,l,x[100000+12];
map<int,long long> f,g;
long long cal()
{
	f.clear(),g.clear();
	f[0] = 0;
	for (int i=2;i<=l;i++)
	{
		for (map<int,long long>::iterator it=f.begin();it!=f.end();it++)
		{
			for (int j=head[x[i]];j;j=nxt[j])
			{
				int id = idx[j];
				if (g.count(id)==0) g[id] = (it->second) + dis[num[x[i-1]][it->first]][num[x[i]][id]];
				else g[id] = min((it->second) + dis[num[x[i-1]][it->first]][num[x[i]][id]],g[id]);
			}
		}
		swap(f,g);
		g.clear();
	}
	long long ans = 1e18;
	for (map<int,long long>::iterator it=f.begin();it!=f.end();it++)
		ans = min(ans,it->second);
	return ans;
}
int main()
{
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&t,&l);
	for (int i=1,u,v,w;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w,i),add(v,u,w,i);
	}
	for (int u=1;u<=n;u++)
	{
		for (int i=head[u];i;i=nxt[i])
		{
			num[u][idx[i]] = ++tlen;
			V[tlen].u = u;
			V[tlen].lst = idx[i];
		}
		num[u][0] = ++tlen;
		V[tlen].u = u;
		V[tlen].lst = 0;
	}
	for (int i=1;i<=m*2+n;i++)
		di(i);
	for (int i=1;i<=l;i++) scanf("%d",x+i);
	for (int i=1;i<=t;i++)
	{
		int pos,val;
		scanf("%d%d",&pos,&val);
		x[pos] = val;
		long long ans = cal();
		if (ans>=1e18) printf("-1\n");
		else printf("%lld\n",ans);
	}
	return 0;
}
