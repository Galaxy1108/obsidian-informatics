#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],b[N],n,vis[N];
struct MX
{
	int id;
	bool operator <(const MX a)const
	{
		if(b[id]==b[a.id])return id<a.id;
		return b[id]<b[a.id];
	}
};
struct MN
{
	int id;
	bool operator <(const MN a)const
	{
		if(b[id]==b[a.id])return id>a.id;
		return b[id]>b[a.id];
	}
};
void solve()
{
	for(int i=1;i<=n;i++)b[i]=a[i];
//	int ans=n,r=n,l=1;
//	while(ans>1)
//	{
//		b[r]-=b[l];
//		l++;
//		if(b[r]<b[l]||l==r)break;
//		if(b[r]<b[r-1])r--;
//		if(r<=l||b[r]<b[n])r=n;
//		ans--;
//	}
//	if(ans==2)ans--;
//	cout<<ans<<'\n';
	priority_queue<MX>p;
	priority_queue<MN>q;
	for(int i=1;i<=n;i++)
	{
		p.push({i});
		q.push({i});
		vis[i]=0;
	}
	int ans=n;
	while(ans>1)
	{
		int x=p.top().id,y=q.top().id;
		//cout<<x<<' '<<y<<' '<<b[x]<<' '<<b[y]<<'\n';
		vis[y]=1;
		p.pop();
		while(!p.empty()&&vis[p.top().id])p.pop();
		while(!q.empty()&&vis[q.top().id])q.pop();
		if(b[x]-b[y]<b[q.top().id]||(b[x]-b[y]==b[q.top().id]&&x<q.top().id))
		{
			//cout<<x<<' '<<y<<' '<<b[x]<<' '<<b[y]<<' '<<b[x]-b[y]<<' '<<q.top().id<<' '<<b[q.top().id]<<' '<<p.top().id<<' '<<b[p.top().id]<<'\n';
			break;
		}
		b[x]-=b[y];
		q.push({x});p.push({x});
		ans--;
	}
	if(!(ans&1))ans--;
	cout<<ans<<'\n';
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	T--;
	solve();
	while(T--)
	{
		int k;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int t,x;
			cin>>t>>x;
			a[t]=x;
		}
		solve();
	}
	return 0;
}
