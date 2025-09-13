#include <bits/stdc++.h>
#define Mod 998244353
#define lim 1000000
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x; 
}
int k,T,n,i,j;
int zs[1000010],top;
int phi[1000010];
long long f[1000010],sum[1000010],dsum[1000010];
long long qpow(long long a,int p=Mod-2)
{
	long long ret=1;
	for(;p;p>>=1,(a*=a)%=Mod)
		if(p&1) (ret*=a)%=Mod;
	return ret;
}
long long F(int n)
{
	if(n>=k+1) return (f[n]+dsum[n-k-1]+sum[n-k-1]*(k-1))%Mod;
	else return 0;
}
long long G(int n)
{
	long long cnt=F(n);
	for(i=1;i*i<n;i++)
		if(n%i==0)
			(cnt+=phi[n/i]*F(i)%Mod+phi[i]*F(n/i))%=Mod;
	if(i*i==n) (cnt+=phi[i]*F(i)%Mod)%=Mod;
	return (cnt*qpow(n))%Mod;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	k=Qread(),T=Qread();
	f[0]=sum[0]=dsum[0]=1;
	for(i=1;i<=k;i++) sum[i]=1;
	for(i=1;i<=k;i++) dsum[i]=i+1;
	for(i=k+1;i<=lim;i++)
		f[i]=sum[i-k-1],sum[i]=(sum[i-1]+f[i])%Mod,dsum[i]=(dsum[i-1]+sum[i])%Mod;
	for(i=2;i<=lim;i++)
	{
		if(phi[i]==0) phi[i]=i-1,zs[++top]=i;
		for(j=1;i*zs[j]<=lim;j++)
		{
			phi[i*zs[j]]=phi[i]*(zs[j]-1);
			if(i%zs[j]==0)
			{
				phi[i*zs[j]]=phi[i]*zs[j];
				break;
			}
		}
	}
	while(T--)
	{
		n=Qread();
		printf("%lld %lld\n",F(n),G(n));
	}
	return 0;
}