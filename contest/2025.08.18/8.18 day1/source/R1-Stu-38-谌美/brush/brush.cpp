#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=10007;
const int maxm=107;
const ll inf=1e18;
int n,m;
ll dp[maxn][maxm],a[maxn],ans=inf;
inline int read() {
	int s=0,w=1; char ch=getchar();
	while (ch<'0' || ch>'9') w=(ch=='-')?-1:1, ch=getchar();
	while (ch>='0' && ch<='9') s=(s<<1)+(s<<3)+(ch^48), ch=getchar();
	return s*w;
}
inline ll read_ll() {
	ll s=0,w=1; char ch=getchar();
	while (ch<'0' || ch>'9') w=(ch=='-')?-1:1, ch=getchar();
	while (ch>='0' && ch<='9') s=(s<<1)+(s<<3)+(ch^48), ch=getchar();
	return s*w;
}
int main() {
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout); 
	n=read(); m=read();
	for (int i=1;i<=n;++i) {
		a[i]=read_ll();
	}
	dp[1][0]=a[1];
	for (int i=1;i<=n;++i) {
		if (i>1) for (int j=0;j<=m;++j) dp[i][j]=inf;
		else for (int j=1;j<=m;++j) dp[i][j]=inf;
//		for (int j=0;j<=m-1;++j) dp[i][0]=min(dp[i][0],dp[i-1][j]+a[i]);
		for (int j=1;j<=m-1;++j) 
			dp[i][j]=min(dp[i-1][j-1],dp[i-1][j]+a[i]);
	}
//	for (int i=1;i<=n;++i) {
//		for (int j=0;j<=m-1;++j) {
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	for (int j=0;j<=m-1;++j) ans=min(ans,dp[n][j]);
	printf("%lld",ans); 
 	return 0; 
}
/*
8 3
6 7 10 1 7 8 5 6
*/
