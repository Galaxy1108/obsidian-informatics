#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,V=1e6+5,mod=1e9+7;
int n,mx,anslt,zs=1,ary[N],num[V],mup[V];
int fp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;	
	}
	return res;
}
signed main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ary[i];
		zs=zs*fp(ary[i],mod-2)%mod;
		mx=max(mx,ary[i]);
	}
	for(int i=1;i<V;i++)mup[i]=1;
	for(int i=1;i<=n;i++)
	{
		num[ary[i]+1]++;
		mup[ary[i]+1]=mup[ary[i]+1]*ary[i]%mod;
	}
	for(int i=1;i<=mx+1;i++)num[i]=num[i-1]+num[i];
	for(int i=2;i<=mx+1;i++)mup[i]=mup[i-1]*mup[i]%mod;
	for(int i=1;i<=mx;i++)anslt=(anslt+((fp(i,n-num[i])%mod-fp(i-1,n-num[i])%mod)%mod+mod)%mod*mup[i]%mod*i%mod)%mod;
	anslt=anslt*zs%mod;
	cout<<anslt;
	
	return 0;
} 
