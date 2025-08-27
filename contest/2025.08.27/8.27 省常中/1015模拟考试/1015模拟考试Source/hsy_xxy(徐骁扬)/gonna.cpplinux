#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
long long Mod;
long long qpow(long long a,long long p)
{
	long long ret=1;
	while(p)
	{
		if(p&1) (ret*=a)%=Mod;
		p>>=1,(a*=a)%=Mod;
	}
	return ret;
}
long long get_sum(long long p,long long len)//p^0 + p^1 + ...... + p^(len-1)
{
	if(len==1) return 1;
	long long ret=get_sum(p,len>>1);
	if(len&1) return (1+(p+qpow(p,(len>>1)+1))*ret%Mod)%Mod;
	else return ret*(1+qpow(p,len>>1))%Mod;
}
int n,i,j,ch;
bool vis[20010];
int prim[20010],top;
int jc[20010],divn[20010];
int rem[20010];
long long num[20010],tot,ans;
int main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	n=Qread(),Mod=Qread();
	for(i=2;i<=n;i++)
	{
		if(!vis[i]) prim[++top]=i;
		for(j=1;i*prim[j]<=n;j++)
		{
			vis[i*prim[j]]=true;
			if(i%prim[j]==0) break;
		}
	}
	for(i=1;i<=top;i++)
		num[i]=1;
	for(i=1;i<=n;i++)
	{
		ch=i;
		for(j=1;divn[j]=0,j<=top;j++)
			while(ch%prim[j]==0)
				ch/=prim[j],divn[j]++;
		for(j=1;j<=top;j++)
		{
			jc[j]+=divn[j];
			if(divn[j]*i!=jc[j])
			{
				rem[j]+=divn[j]*i-jc[j];
				num[j]=get_sum(prim[j],rem[j]+1);
			}
		}
		tot=1;
		for(j=1;j<=top;j++)
			(tot*=num[j])%=Mod;
		(ans+=tot)%=Mod;
	}
	printf("%lld\n",ans);
	return 0;
}