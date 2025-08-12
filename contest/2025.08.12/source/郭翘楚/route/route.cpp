#include <bits/stdc++.h>
using namespace std;
const int MAXN=5000;
int a[5000],b[5000],l[5000],c[5000];
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    { 
        if (ch == '-') w = -1; 
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0'); 
        ch = getchar();
    }
    return x * w; 
}
struct edge {
  int v, w;
};

struct node {
  int dis, u;
  bool operator>(const node& a) const { return dis > a.dis; }
};
vector<edge> e[MAXN];
int dis[MAXN], vis[MAXN];
priority_queue<node, vector<node>, greater<node>> q;

void dijkstra(int n, int s) {
  memset(dis, 0x3f, (n + 1) * sizeof(int));
  memset(vis, 0, (n + 1) * sizeof(int));
  dis[s] = 0;
  q.push({0, s});
  while (!q.empty()) {
    int u = q.top().u;
    q.pop();
    if (vis[u]) continue;
    vis[u] = 1;
    for (auto ed : e[u]) {
      int v = ed.v, w = ed.w;
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}
int main()
{
	freopen("route.in","r",stdin);
    freopen("route.out","w",stdout);
	int n,m,s,q;
	cin>>n>>m>>s>>q;
	for(int i=1;i<=m;i++)
	{
		a[i]=read();
		b[i]=read();
		l[i]=read();
		c[i]=read();
		e[a[i]].push_back({a[i],l[i]});
		e[b[i]].push_back({a[i],l[i]});
	}
	for(int i=1;i<=q;i++)
	{
		int u,v,t;
		u=read();
		v=read();
		t=read();
		dijkstra(u,v);
		cout<<dis[v]<<endl;
	}
	return 0;
}
