#include <bits/stdc++.h>
using namespace std;
struct Val{
	long long sum;
	int cnt,id;
};
bool operator<(Val a,Val b)
{
	if((__int128)a.sum*b.cnt!=(__int128)b.sum*a.cnt)
		return (__int128)a.sum*b.cnt<(__int128)b.sum*a.cnt;
	return a.id<b.id;
}
int fa[1000010];
int get_fa(int a){return a==fa[a]?a:fa[a]=get_fa(fa[a]);}
int n,u,v;
bool vis[1000010];
Val a[1000010];
int p[1000010],w[1000010];
priority_queue<Val> Q;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>n;
	for(int i=2;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		a[i].cnt=1,fa[i]=a[i].id=i,a[i].sum=w[i];
		Q.push(a[i]);
	}

	while(!Q.empty())
	{
		u=Q.top().id;Q.pop();
		if(vis[u]) continue;vis[u]=true;
		if(u==1) continue;
		v=get_fa(p[u]);
		if(!vis[v])
		{
			a[v].cnt+=a[u].cnt;
			a[v].sum+=a[u].sum;
			fa[u]=v;
			Q.push(a[v]);
		}
	}

	for(int i=1;i<=n;i++)
		printf("%.6lf\n",1.*a[i].sum/a[i].cnt);
	return 0;
}