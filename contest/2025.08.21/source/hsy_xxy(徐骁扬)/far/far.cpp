#include <bits/stdc++.h>
using namespace std;
long long Qread()
{
	long long x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
const long long Mod=998244353;
int n,m,lim,i,j;
long long l[50],r[50];
long long Tong[33010],Tong_[33010],ans;
bool abl[33010];
bool check(int num)
{
	for(int l=1,r=m;l<=r;l++,r--)
		if(((num&(1<<l-1))==0)^((num&(1<<r-1))==0))
			return false;
	return true;
}
int main()
{
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	n=Qread(),m=Qread();
	for(i=1;i<=n;i++)
		l[i]=Qread(),r[i]=Qread();
	if(m<=15)
	{
		lim=(1<<m);
		for(i=0;i<lim;i++)
			abl[i]=check(i);
		Tong[0]=1;
		for(int zsh=1;zsh<=n;zsh++)
		{
			memset(Tong_,0,sizeof(Tong_));
			for(i=l[zsh];i<=r[zsh];i++)
			for(j=0;j<lim;j++)
				(Tong_[j^i]+=Tong[j])%=Mod;
			memcpy(Tong,Tong_,sizeof(Tong_));
			for(j=0,ans=0;j<lim;j++)
				if(abl[j])
					(ans+=Tong[j])%=Mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
 } 