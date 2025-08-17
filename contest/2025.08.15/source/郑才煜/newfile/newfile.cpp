#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
	ll sum=0;
	char c=getchar();
	while(c>'9'||c<'0') c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
const int N=5e3+3;
const ll mod=1e9+9;
ll a[N][N];
int main()
{
    freopen("newfile.in","r",stdin);
    freopen("newfile.out","w",stdout);
    ll n=read(),m=read(),q=read(),i,j,u,d,l,r,x;
    for(i=1;i<=m;++i)
    {
    	l=read();
    	r=read();
    	x=read();
    	if(i!=1) for(j=1;j<=n;++j) a[i][j]=a[i-1][j];
    	for(j=l;j<=r;++j) a[i][j]=a[i][j]+(j-l+1)*x;
    	for(j=r+1;j<=n;++j) a[i][j]=a[i][j]+(r-l+1)*x;
	}
	while(q--)
	{
		u=read();
		d=read();
		l=read();
    	r=read();
    	ll ans=0;
    	for(i=u;i<=d;++i) ans=(ans+a[i][r]-a[i][l-1])%mod;
    	printf("%lld\n",ans%mod);
	}
}
