#include <bits/stdc++.h>
using namespace std;
constexpr int N=5005,mod=1e9+7;
int n,a[N];
int b[N];
int s[N];
int sum,p=1;
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
int fs[N],inv[N];
int sm[N];
int S[N][N];
void init()
{
	fs[0]=1;
	for(int i=1;i<=4000;i++)
		fs[i]=1ll*fs[i-1]*i%mod;
	inv[4000]=qpow(fs[4000],mod-2);
	for(int i=3999;~i;i--)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
	for(int i=0;i<=n;i++)
	{
		S[i][0]=bool(i);
		for(int j=1;j<=i;j++)
			S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j]%mod)%mod; 
	}
//	for(int i=0;i<=n;i++)
//	{
//		for(int i=)
//	}
}
int C(int n,int m)
{
	if(n<0 || m<0 || n<m)return 0;
	return 1ll*fs[n]*inv[m]%mod*inv[n-m]%mod;
}
int ans=0;
int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	init();
	s[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],p=1ll*p*a[i]%mod,b[i]=a[i];
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
		s[i]=1ll*s[i-1]*b[i]%mod;
	p=qpow(p,mod-2);
	for(int i=1;i<=n;i++)
		if(b[i]!=b[i-1])
		{
			int pr=s[i-1],sum=0;
			for(int j=1;j<=n-i+1;j++)
			{
				int sm=0;
				for(int k=b[i-1]+1;k<=b[i];k++)
					sm=(sm+k*qpow(k-1,n-i+1-j)%mod)%mod;
				sum=(sum+C(n-i+1,j)*sm%mod)%mod;
			}
			ans=(ans+pr*sum%mod)%mod;
		}
	cout<<(1ll*ans*p%mod);
	return 0;
}
