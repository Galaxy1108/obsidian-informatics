#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
inline int read(){
	int first=0,f=1;char ch=getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){first=(first<<3)+(first<<1)+(ch^48);ch=getchar();}
	return first*f;
}
typedef long long ll;
const int N=2005;
typedef pair<ll,ll>ttfa;
int n,m;ll a[N];
ttfa lin[N];
inline bool cmp(ttfa x,ttfa y){
	return x.second<y.second;
}
ll dp[N][N];
ttfa g[N][N];
int c[N];
inline ll getit(int loc,ttfa x){
	if(x.first<=loc&&loc<=x.second)return 0;
	return min(abs(x.first-loc),abs(x.second-loc));
}
int main(){
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout); 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;++i)
		scanf("%lld %lld",&lin[i].first,&lin[i].second);
	sort(a+1,a+1+n);
	sort(lin+1,lin+1+m,cmp);
	
//	for(int i=1;i<=m;++i)
//		printf("%d %d %d\n",i,lin[i].first,lin[i].second);

	for(int i=1;i<=m;++i){
		for(int k=1;k<=i;++k){
			if(lin[k].second>=lin[i].first){
				g[i][i-k+1].first=max(lin[i].first,lin[k].first);
				g[i][i-k+1].second=lin[k].second;
				c[i]=max(c[i],i-k+1);
			}
		}
	}
//	for(int i=1;i<=m;++i){
//		for(int k=1;k<=c[i];++k)
//			printf("g[%d][%d]=%d ;",i,k,g[i][k]);
//		putchar('\n'); 
//	}
	
	memset(dp,0x3f,sizeof(dp));
	for(int j=0;j<=n;++j)
		dp[0][j]=0;
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=c[i];++k)
				dp[i][j]=min(dp[i][j],dp[i-k][j-1]+getit(a[j],g[i][k]));
		}
	}
//	for(int i=0;i<=m;++i){
//		for(int j=0;j<=n;++j){
//			printf("dp[%d][%d]=%d; ",i,j,dp[i][j]);
//		}putchar('\n');
//	}
	
	printf("%lld\n",dp[m][n]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
4 11
2 6 14 18
0 3
1 4
4 5
3 5
8 12
10 13
7 13
11 15
16 16
17 19
14 19
*/
