#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int n,i,j,k,l,r,g,mid=20000;
long long f[210][40010],jc,Mod,ans;
int main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	n=Qread(),Mod=Qread();
	jc=1;
	l=r=mid;
	for(i=1;i<=n;++i)
	{
		g=n-i+1;
		for(j=1;j<g;++j)
			(f[i][mid-j]+=jc*(g-j)%Mod)%=Mod;
		l-=g,r+=g; 
		for(j=l;j<=r;++j)
		{
			(f[i][j]+=f[i-1][j]*g)%=Mod;
			for(k=1;k<g;++k)
				(f[i][j]+=(f[i-1][j+k]+f[i-1][j-k])%Mod*(g-k)%Mod)%=Mod;
		}
		(jc*=g)%=Mod;
	}
	for(i=mid+1;i<=r;++i)
		(ans+=f[n][i])%=Mod;
	printf("%lld\n",ans);
	return 0;
}
