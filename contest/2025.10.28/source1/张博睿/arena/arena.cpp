#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int qread()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
#define re register
const int N=500+10;
int a[N];
int n,x;
const int mod=998244353 ;
int ans=0;
inline bool chk()
{
	int x=n;
	int cnt=0;
	while(x>0)
	{
		cnt+=x-1;
		x=0;
		for(re int i=1; i<=n; i++)if(a[i]-cnt>=1)x++;
		if(x==1)return 0;
	}
	return 1;
}
inline void dfs(int stp)
{
	if(stp>n)
	{
		if(chk())
		{
			ans++;
			if(ans>=mod)ans-=mod;
		}
		return ;
	}
	for(re int i=1; i<=x; i++)
	{
		a[stp]=i;
		dfs(stp+1);
	}
}
int qpow(int base,int o)
{
	int res=1,tmp=base;
	while(o!=0)
	{
		if(o%2==1)
		{
			res=(res%mod*tmp%mod)%mod;
		}
		tmp=(tmp%mod*tmp%mod)%mod;
		o=o>>1;
	}
	res=res%mod;
	return res;
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=qread();
	x=qread();
	if(n-1>=x)
	{
		ans=qpow(x,n);
		ans%=mod;
	}
	else dfs(1);
	cout<<ans%mod<<endl;
	return 0;
}
