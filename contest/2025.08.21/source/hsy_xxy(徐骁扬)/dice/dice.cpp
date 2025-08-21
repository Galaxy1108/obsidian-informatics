#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
const long long Mod=1e9+7;
long long qpow(long long a,long long p)
{
	long long ret=1;
	for(;p;p>>=1,(a*=a)%=Mod)
		if(p&1) (ret*=a)%=Mod;
	return ret;
}
int n,i,j,k;
long long ny;
//long long C(int n,int m){return jc[n]*ny[m]%Mod*ny[n-m]%Mod;}
//long long S(long long n,int m)
//{
//	long long ret=1;
//	for(int i=m+1;i;i--)
//		(ret+=dxs[m][i]*qpow(n,i))%=Mod;
//	return ret;
//}
inline long long Sum(long long sta,long long en,int pow)
{
	if(pow==0) return (sta+en)*(sta-en+1)%Mod*ny%Mod;
	long long ret=0;
	for(long long i=sta;i<=en;i++)
		(ret+=qpow(i,pow))%=Mod;
	return ret;
}
long long a[5010];
long long mul[5010],ds,ans;
int main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	ny=qpow(2,Mod-2);
	n=Qread();
	a[0]=1;
	for(i=1;i<=n;i++)
		a[i]=Qread();
	sort(a+1,a+n+1);
	mul[n+1]=1;
	for(i=n;i>=1;i--)
		mul[i]=(mul[i+1]*qpow(a[i],Mod-2))%Mod;
	for(i=n;i;i--)
		(ds+=Sum(a[i-1],a[i]-1,n-i+1)*mul[i]%Mod)%=Mod;
	ans=(a[n]+Mod-ds)%Mod;
	printf("%lld\n",ans);
	return 0;
 } 