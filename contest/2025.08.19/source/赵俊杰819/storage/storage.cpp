#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
typedef long long ll;
ll f[N],s[N],p[N];
struct T
{
	ll c,x,w;
}a[N];
bool cmp(T a,T b)
{
	return a.c<b.c;
}
int main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n;m=100000000/n;
	for(int i=1;i<=n;i++)
		cin>>a[i].c>>a[i].x>>a[i].w;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i].c*a[i].x;
		p[i]=p[i-1]+a[i].x;
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=(1ull<<63)-1;
		for(int j=max(i-m,1);j<=i;j++)
		{
			f[i]=min(f[i],f[j-1]+a[i].w+(p[i-1]-p[j-1])*a[i].c-(s[i-1]-s[j-1]));
		}
	}
	cout<<f[n]<<'\n';
	return 0;
}
