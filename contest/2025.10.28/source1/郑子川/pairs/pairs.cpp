#include<iostream>
#include<algorithm>
#include<cstring>
#define mn 100010
#define ll long long
#define FOR(i,x,y) for(ll i=x;i<=y;++i)
#define ROF(i,x,y) for(ll i=x;i>=y;--i)
using namespace std;
ll n,mod;
ll dp[2][mn];
ll sum[2][mn];
ll sum2[2][mn];
ll f[510];
inline ll read()
{
	ll s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}
inline ll c2(int x)
{
	return x*(x-1)/2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	n=read(),mod=read();
	dp[1][0]=1;sum[1][0]=1,sum2[1][0]=1;
	FOR(i,2,n)
	{
		memset(dp[i&1],0,sizeof(dp[i&1]));
		memset(sum[i&1],0,sizeof(sum[i&1]));
		memset(sum2[i&1],0,sizeof(sum2[i&1]));
		FOR(j,0,c2(i))
		{
			if(j<i)dp[i&1][j]=sum[(i-1)&1][min(c2(i-1),j)];
			else dp[i&1][j]=(sum[(i-1)&1][min(c2(i-1),j)]-sum[(i-1)&1][j-i]+mod)%mod;
			sum[i&1][j]=(sum[i&1][j==0?0:j-1]+dp[i&1][j])%mod;
			sum2[i&1][j]=(sum2[i&1][j==0?0:j-1]+sum[i&1][j])%mod;
		}
		f[i]=i*f[i-1]%mod;
		ll x=0;
		FOR(p1,2,c2(i-1))
		{
			ll cnt;
			if(p1>i)cnt=sum2[(i-1)&1][p1-2]-sum2[(i-1)&1][p1-i-1];
			else cnt=sum2[(i-1)&1][p1-2];
			cnt=(cnt+mod)%mod,x=(x+cnt)%mod,cnt=cnt*i%mod;
			if(p1>=i+1)x=(x-sum[(i-1)&1][p1-1-i]*(i-1)%mod+mod)%mod;
			cnt=(cnt-x+mod)%mod;
			f[i]=(f[i]+dp[(i-1)&1][p1]*cnt)%mod;
		}
	}
	cout<<f[n];
	return 0;
}
