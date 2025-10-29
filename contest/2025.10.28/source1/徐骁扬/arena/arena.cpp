#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
const long long Mod=998244353;
long long Qpow(long long a,long long p)
{
	long long ret=1;
	for(;p;p>>=1,(a*=a)%=Mod)
		if(p&1) (ret*=a)%=Mod;
	return ret;
}
long long qpow[510][510];
long long f[510][510],ans;
long long jc[510],ny[510];
long long C(int n,int m){return jc[n]*ny[m]%Mod*ny[n-m]%Mod;}
int n,x,i,j,k;
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	jc[0]=ny[0]=1;
	for(i=1;i<=500;i++)
	{
		for(qpow[i][0]=1,j=1;j<=500;j++)
			qpow[i][j]=qpow[i][j-1]*i%Mod;
		jc[i]=jc[i-1]*i%Mod;
		ny[i]=Qpow(jc[i],Mod-2);
	}
	n=Qread(),x=Qread();
	if(n>x)
	{
		printf("%lld\n",qpow[x][n]);
		return 0;
	}
	for(i=2;i<=n;i++)
	{
		for(j=1;j<i;j++)
			f[i][j]=(qpow[j][i]+Mod-qpow[j-1][i])%Mod;
		for(j=i;j<=x;j++)
			for(k=1;k<=i;k++)
				(f[i][j]+=f[k][j-i+1]*qpow[i-1][i-k]%Mod*C(i,k)%Mod)%=Mod;
	}
	ans=qpow[n-1][n];
	for(i=n;i<=x;i++)
		(ans+=f[n][i])%=Mod;
	printf("%lld\n",ans);
	return 0;
}
