#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
using namespace std;
constexpr int N=2e5+5,M=3e5+5;
typedef long long ll;
int T;
int n,m;
struct edge{
	int u,v,w;
}ed[M];
int vis[N],p[N];
ll ans[3],d[N];
void init()
{
	ans[1]=ans[2]=0;
	for(int i=1;i<=n;i++)
		d[i]=0,p[i]=i;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		init();
		for(int i=1;i<=m;i++)
			cin>>ed[i].u>>ed[i].v>>ed[i].w,d[ed[i].u]+=ed[i].w,d[ed[i].v]+=ed[i].w;
		sort(p+1,p+1+n,[](int x,int y){return d[x]>d[y];});
		int id=1;
		for(int i=1;i<=n;i++)
			vis[p[i]]=id,id=(id==1?2:1);
		for(int i=1;i<=m;i++)
			if(vis[ed[i].u]==vis[ed[i].v])
				ans[vis[ed[i].u]]+=ed[i].w;
		cout<<ans[1]-ans[2]<<'\n';
	}
	return 0;
}
