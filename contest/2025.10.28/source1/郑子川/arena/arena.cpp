#include<iostream>
#include<algorithm>
#include<cstring>
#define mn 510
#define mod 998244353
#define ll long long
#define FOR(i,x,y) for(int i=x;i<=y;++i)
#define ROF(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
int n,x;
ll f[mn][mn];
ll c[mn][mn];
ll ans;
inline ll fpow(ll a,int k)
{
	ll base(1);
	while(k)
	{
		if(k&1)base=(base*a)%mod;
		a=(a*a)%mod;
		k>>=1;
	}
	return base%mod;
}
inline int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),x=read();
	FOR(i,0,n)c[i][0]=1;
	FOR(i,1,n)FOR(j,1,n)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	FOR(i,2,n)FOR(j,1,x)
	{
		if(i>j)f[i][j]=(fpow(j,i)-fpow(j-1,i)+mod)%mod;
		else FOR(k,1,i)f[i][j]=(f[i][j]+c[i][k]*fpow(i-1,i-k)%mod*f[k][j-i+1]%mod+mod)%mod;
	}
	FOR(i,1,x)ans=(ans+f[n][i])%mod;
	cout<<ans<<endl;
	return 0;
}
