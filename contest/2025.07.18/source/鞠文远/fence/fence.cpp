#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,mod=1e9+7;
int n,inv4,h[N],w[N],dp[N],qzh[N];
int ftpow(int a,int b)
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
int cnt(int x,int y){return (x+1)%mod*(y+1)%mod*x%mod*y%mod*inv4%mod; }
signed main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	inv4=ftpow(4,mod-2);	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>h[i];
	for(int i=1;i<=n;i++)cin>>w[i];
	dp[1]=cnt(h[1],w[1])%mod;
	for(int i=2;i<=n;i++)
	{
		dp[i]=(dp[i-1]+cnt(h[i],w[i]))%mod;
		//int nh=min(h[i],h[i-1]);
		//int cng=((cnt(nh,w[i]+w[i-1])-cnt(nh,w[i-1])-cnt(nh,w[i]))%mod+mod)%mod;
		//dp[i]=(dp[i]+cng+mod)%mod;
		int ltmi=0;
		for(int j=1;j<i;j++)
		{ 
			int mi=0x3f3f3f3f;
			for(int k=j;k<=i;k++)mi=min(mi,h[k]);
			int nh=mi-ltmi;
			int nw=0;
			for(int k=j;k<i;k++)nw+=w[k];
			dp[i]=(dp[i]+(cnt(nh,nw+w[i])-cnt(nh,nw)-cnt(nh,w[i]))%mod+mod)%mod;
			ltmi=mi;
		}
	}
	cout<<dp[n];
	
	return 0;	
} 
