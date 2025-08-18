#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=107;
int n,m,K;
ll dp[maxn][maxn][3],sum[maxn][3],a[maxn][3];
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
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout); 
	n=read(); m=read(); K=read();
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j) {
			a[i][j]=read_ll();
			sum[i][j]=sum[i-1][j]+a[i][j];
		}
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=n;++j) {
			for (int k=1;k<=K;++k) {
				dp[i][j][k]=max(dp[i-1][j][k],dp[i][j-1][k]);
				for (int p=0;p<i;++p) dp[i][j][k]=max(dp[i][j][k],dp[p][j][k-1]+sum[i][1]-sum[p][1]);
				for (int p=0;p<j;++p) dp[i][j][k]=max(dp[i][j][k],dp[i][p][k-1]+sum[j][2]-sum[p][2]);
				if (i==j) {
					for (int p=0;p<i;++p) dp[i][j][k]=max(dp[i][j][k],dp[p][p][k-1]+(sum[i][1]-sum[p][1])+(sum[j][2]-sum[p][2]));
				}		
			}
		}
	}
	printf("%lld",dp[n][n][K]);
	return 0;
}
/*
3 2 2
1 -3
2 3
-2 3
*/
