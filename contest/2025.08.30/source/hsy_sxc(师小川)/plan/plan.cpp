#include<bits/stdc++.h>
#define rr register
#define pb push_back
using namespace std;
inline int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x;
}
void write(int x) {if(x>9) write(x/10);putchar(x%10+'0');}
const int N=503,inf=2e9;
int n,k,a[N],dp[N][N],gd[N][N];
vector<int> e[N];
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	n=read(),k=read();
	for(rr int i=1;i<n;++i) 
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	e[1].pb(0);
	for(rr int i=1;i<=n;++i) a[i]=read();
	for(rr int i=1;i<=n;++i)
	{
		gd[i][i]=a[i];
		for(rr int j=i+1;j<=n;++j) gd[i][j]=__gcd(gd[i][j-1],a[j]);
	}
	for(rr int i=1;i<=n;++i) dp[i][0]=gd[1][i];
	for(rr int i=1;i<=n;++i)
		for(rr int j=1;j<=k;++j) dp[i][j]=-inf;
	for(rr int i=1;i<=n;++i)
		for(rr int j=1;j<=min(k,i-1);++j)
			for(rr int s=i;s>j;--s) dp[i][j]=max(dp[i][j],dp[s-1][j-1]+gd[s][i]);
	write(dp[n][k]);
	return 0;
}