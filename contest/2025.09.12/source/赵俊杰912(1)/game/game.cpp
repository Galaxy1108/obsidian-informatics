#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
typedef long long ll;
struct T
{
	ll ne,to,v;
}e[2*N];
struct P
{
	ll x,k;
}a[N];
int he[N],idx,vis[N];
void add(int x,int y,int z)
{
	e[++idx].ne=he[x];
	e[idx].to=y;
	e[idx].v=z;
	he[x]=idx;
}
bool cmp(P a,P b)
{
	return a.k>b.k;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			a[i].x=i;a[i].k=0;
			vis[i]=0;he[i]=0;
		}
		idx=0;
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
			a[x].k+=z;
			a[y].k+=z;
			if(x==y)continue;
			add(y,x,z);
		}
		sort(a+1,a+n+1,cmp);
		ll x=0,y=0;
		for(int i=1;i<=n;i++)
		{
			int u=a[i].x;
			vis[u]=(i&1)+1;
			for(int j=he[u];j;j=e[j].ne)
			{
				int t=e[j].to;
				if(vis[t]==(i&1)+1)
				{
					if(i&1)x+=e[j].v;
					else y+=e[j].v;
				}
			}
			//cout<<a[i].x<<' '<<x<<' '<<y<<'\n';
		}
		cout<<x-y<<'\n';
	}
	return 0;
}
