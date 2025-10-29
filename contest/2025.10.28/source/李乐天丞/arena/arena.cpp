#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=550;
inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=x*10+(c^48);c=getchar();}
	return x*f;
}
int dp[maxn][maxn],n,x;
int C[maxn][maxn];
int mi[maxn][maxn];
inline int ksm(int w,int k)
{
	int ans=1;
	while(k)
	{
		if(k%2==1) {ans=ans*w;ans%=mod;}
		w=w*w;w=w%mod;
		k=k>>1ll;
	}
	return ans%mod;
}
inline void prework()
{
	for(int i=0;i<=500;i++)
	for(int j=0;j<=500;j++)
	{
		if(i>j) {C[i][j]=1;continue ;}
		if(i==j||i==0||j==0) {C[i][j]=1;continue ;}
		C[i][j]=(C[i-1][j-1]+C[i][j-1])%mod;
	}
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read();x=read();
	prework();
	for(int i=0;i<=n;i++)
	for(int j=0;j<=x;j++)
	{
		if(i>j) {dp[i][j]=ksm(j,i);continue ;}
		if(i==0) {dp[i][j]=1;continue ;}
		if(i==1) {dp[i][j]=0;continue ;}
		if(i==2) {dp[i][j]=j;continue ;}
		for(int k=0;k<=i;k++) dp[i][j]=(dp[i][j]+(C[k][i]*ksm(i-1,k))%mod*dp[i-k][j-i+1]%mod)%mod;
	}
	printf("%lld",dp[n][x]%mod); 
	return 0;
}
