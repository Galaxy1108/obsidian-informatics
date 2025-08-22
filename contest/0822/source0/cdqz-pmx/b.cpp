#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=2003,INF=(ll)1e18;
ll n,val[N],ans[N],dis[N],a[N][N];
bool vis[N];
struct Nod
{
	ll x,z;
	friend bool operator <(Nod A,Nod B){return A.z>B.z;}
};
void Dij(int st)
{
	memset(dis,0x3f,sizeof(dis));memset(vis,0,sizeof(vis));
	priority_queue<Nod>q;
	for(int i=1;i<=n;i++)if(i!=st)q.push({i,dis[i]=min(a[st][i]-val[st],2*(val[i]-val[st]))});
	while(q.size())
	{
		int x=q.top().x;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=1;i<=n;i++)if(i!=x&&a[x][i]>val[st]&&dis[x]+a[x][i]-val[st]<dis[i])
		    dis[i]=dis[x]+a[x][i]-val[st],q.push({i,dis[i]});
	}
	for(int i=1;i<=n;i++)ans[i]=min(ans[i],(n-1)*val[st]+dis[i]);
}
void SA()
{
	int nb=0;ll V=1e9; 
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if(a[i][j]==1)nb=1;
	if(!nb)
	{
		for(int i=1;i<=n;i++)cout<<V*(n-1)<<endl;
		return; 
	}
	for(int i=1;i<=n;i++)if(val[i]==1)cout<<n-1<<endl;else cout<<V+(n-2)<<endl;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;int fl=1,V=1e9;
	for(int i=1;i<=n;i++)val[i]=ans[i]=INF;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)cin>>a[i][j],a[j][i]=a[i][j],fl&=a[i][j]==1||a[i][j]==V;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(j!=i)val[i]=min(val[i],a[i][j]);
	if(fl){SA();return 0;}
	for(int i=1;i<=n;i++)Dij(i);
	for(int i=1;i<=n;i++)cout<<ans[i]<<"\n";
}
