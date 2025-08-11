#include <bits/stdc++.h>
#define pb emplace_back
#define si multiset<int>::iterator
using namespace std;
typedef long long ll;
constexpr int N=1e5+5;
constexpr ll inf=1e18;
int n,m[N];
vector<int>a[N];
vector<ll>f[N],sp[N];
bool sub1=1;
ll ans=inf;
inline ll pw(ll x){return x*x;}
namespace bf
{
	int p[N];
	void dfs(int x)
	{
		if(x==n+1)
		{
			ll sum=0;
			for(int i=1;i<=n;i++)
			{
				int ni=i%n+1;
				vector<int>tmp;
				tmp.pb(0),tmp.pb((int)2e6);
				for(int j=p[i];j<=m[i];j++)
					tmp.pb(a[i][j]);
				for(int j=1;j<=p[ni]-1;j++)
					tmp.pb(a[ni][j]);
				sort(tmp.begin(),tmp.end());
				for(int i=1;i<tmp.size();i++)
					sum+=pw(tmp[i]-tmp[i-1]);
			}
			ans=min(ans,sum);
			return;
		}
		for(int i=1;i<=m[x];i++)
			p[x]=i,dfs(x+1);
	}
	void solve()
	{
		dfs(1);
		cout<<ans;
	}
}
/*
3
3 1 4 2
3 9 5 8
3 6 10 7

*/
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	if(n>6)sub1=0;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
		if(m[i]>10)sub1=0;
		a[i].resize(m[i]+1);
		f[i].resize(m[i]+1);
		sp[i].resize(m[i]+1);
		f[i][0]=a[i][0]=sp[i][0]=0;
		for(int j=1;j<=m[i];j++)
			cin>>a[i][j],sp[i][j]=pw(a[i][j])+sp[i][j-1];
	}
	if(sub1)
	{
		bf::solve();
		return 0;
	}
	a[n+1]=a[1];
	f[n+1]=f[1];
	sp[n+1]=sp[1];
	m[n+1]=m[1];
	for(int st1=1;st1<=m[1];st1++)
	{
		for(int i=1;i<=n+1;i++)
			for(int j=0;j<=m[i];j++)
				f[i][j]=inf;
		multiset<int>s;
		ll val=(sp[1][m[1]]-sp[1][st1-1])*2+pw((ll)2e6);
		s.insert(0),s.insert((int)2e6);
		for(int j=st1;j<=m[1];j++)
			s.insert(a[1][j]);
		for(si i=s.begin();next(i)!=s.end();i++)
			val-=2*(*next(i))*(*i);
		for(int j=0;j<m[2];j++)
		{
			if(j)
			{
				si r=s.lower_bound(a[2][j]);
				si l=prev(r);
				val+=2*(*r)*(*l);
				val-=2*(((*r)*a[2][j])+a[2][j]*(*l));
			}
			f[2][j+1]=min(f[2][j+1],val+sp[2][j]*2);
		}
		for(int i=2;i<=n;i++)
		{
			for(int st=1;st<=m[i];st++)
			{
				s.clear();
				s.insert(0),s.insert((int)2e6);
				for(int j=st;j<=m[i];j++)
					s.insert(a[1][j]);
				val=(sp[i][m[i]]-sp[i][st-1])*2+pw((ll)2e6);
				for(si i=s.begin();next(i)!=s.end();i++)
					val-=2*(*next(i))*(*i);
				for(int j=0;j<m[i+1];j++)
				{
					if(j)
					{
						si r=s.lower_bound(a[i+1][j]);
						si l=prev(r);
						val+=2*(*r)*(*l);
						val-=2*(((*r)*a[i+1][j])+a[i+1][j]*(*l));
					}
					f[i+1][j+1]=min(f[i+1][j+1],val+sp[i+1][j]*2);
				}
			}
		}
		ans=min(ans,f[n+1][st1]);
	}
	cout<<ans;
	return 0;
}
