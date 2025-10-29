#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int ksm(int x,int y)
{
	int base=x,ans=1;
	while(y)
	{
		if(y&1) ans=ans*base%mod;
		base=base*base%mod;
		y>>=1;
	}
	return ans%mod;
}
int f[510][510],jc[510],jcv[510];
int getf(int n,int x)
{
	if(n==1) return 0;
	if(f[n][x]) return f[n][x];
	if(n==2)
	{	
		f[n][x]=x%mod; 
		return x;	
	} 
	if(n-1>=x) 
	{
		f[n][x]=ksm(x,n)%mod;
		return 	f[n][x]; 
	}
	int res=0;
	res=res+getf(n,n-1)%mod;
	for(int i=1;i<=n-2;i++) res=(res+getf(n-i,x-n+1)*ksm(n-1,i)%mod*jc[n]%mod*jcv[n-i]%mod*jcv[i]%mod)%mod;
	res=res+getf(n,x-n+1)%mod;
	f[n][x]=res;
	return res%mod;
}
void prework(int n)
{
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	jcv[n]=ksm(jc[n],mod-2);
	for(int i=n-1;i>=0;i--) jcv[i]=jcv[i+1]*(i+1)%mod;
}
signed main()///xxx
{
	//freopen("arena.in","r",stdin);
	//freopen("arena.out","w",stdout);
	int n,x;
	scanf("%lld%lld",&n,&x);
	prework(max(n,x)+10);
	printf("%lld\n",getf(n,x));
	return 0;
}
