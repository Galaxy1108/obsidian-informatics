#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back
using namespace std;
typedef long long ll;
constexpr int N=2e5+5,inf=1e9;
constexpr ll Inf=1e18;
int n,m;
int a[N];
pii ln[N];
vector<pii>nln;
ll f[2][N];
void minn(ll& x,ll y){if(x>y)x=y;}
int main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[n+1]=inf;
	for(int i=1;i<=m;i++)
		cin>>ln[i].fi>>ln[i].se;
	sort(ln+1,ln+1+m,[&](pii x,pii y){return x.fi==y.fi?x.se>y.se:x.fi<y.fi;});
	sort(a+1,a+1+n);
	for(int i=m,ri=inf;i;i--)
	{
		// bool fl=0;
		// if(ln[i]==mkp(3,5))fl=1;
		int pos=lower_bound(a+1,a+n+1,ln[i].fi)-a;
		if(a[pos]<=ln[i].se || ln[i].se>=ri)continue;
		nln.pb(ln[i]),ri=min(ri,ln[i].se);
	}
	if(!nln.size())return cout<<"0",0;
	reverse(nln.begin(),nln.end());
	fill(f[0],f[0]+n+1,Inf);
	fill(f[1],f[1]+n+1,Inf);
	// for(auto x:nln)
	// {
	// 	cout<<x.fi<<' '<<x.se<<'\n';
	// }
	// for(int i=1;i<=n;i++)
	// {
	// 	cerr<<f[0][i]<<' '<<f[1][i]<<'\n';
	// }
	ll le=0,ri=0;
	if(nln[0].se<a[1])le=a[1]-nln[0].se;
	f[0][1]=2ll*le,f[1][1]=le;
	int i=0,j=0;
	while(j<nln.size() && nln[j].se<a[1])j++;i=j;
	for(int k=2;k<=n;k++,i=j)
	{
		while(j<nln.size() && nln[j].se<a[k])j++;
		for(int kk=i;kk<=j;kk++)
		{
			le=ri=0;
			if(kk^i)le=nln[kk-1].fi-a[k-1];
			if(kk^j)ri=a[k]-nln[kk].se;
			minn(f[0][k],f[0][k-1]+le+2ll*ri);
			minn(f[0][k],f[1][k-1]+le*2+ri*2);
			minn(f[1][k],f[0][k-1]+le+ri);
			minn(f[1][k],f[1][k-1]+le*2+ri);
		}
	}
	ri=0;
	if(nln.back().fi>a[n])
		ri=nln.back().fi-a[n];
	ll ans=min(f[0][n]+ri,f[1][n]+ri*2);
	// for(int i=1;i<=n;i++)
	// {
	// 	cerr<<f[0][i]<<' '<<f[1][i]<<'\n';
	// }
	cout<<ans;
	return 0;
}