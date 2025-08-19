#include <bits/stdc++.h>
using namespace std;
typedef long double db;
constexpr int N=2005;
constexpr db eps=1e-12;
int n,cst;
db w[N];
db s[N];
db c[N],d[N];
double f[N];//全部换成￥ 
double g[N];//全部换成$ 
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>cst;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>c[i]>>d[i];
		s[i]=s[i-1]+w[i]*c[i],w[i]+=w[i-1];
		f[i]=f[i-1]+w[i]-w[i-1];
		g[i]=g[i-1]+s[i]-s[i-1];
		for(int j=1;j<i;j++)
		{
			f[i]=max(f[i],(double)(g[j]*d[i]-cst+w[i]-w[j]));
			g[i]=max(g[i],(double)(f[j]*c[i]+s[i]-s[j]));
		}
	}
	cout<<fixed<<setprecision(4)<<f[n];
	return 0;
}
