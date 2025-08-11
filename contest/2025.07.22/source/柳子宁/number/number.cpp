#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n,m,T;
int a[300010];
vector<long long> f[300010];
long long ans;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i) scanf("%d",&a[i]);
		reverse(a+1,a+m+1);
		ans=-1e18;
		f[0].resize(n+1);
		for(int j=0;j<=n;++j) f[0][j]=-inf;
		f[0][0]=0;
		for(int i=1;i<=m;++i){
			f[i].resize(n+1);
			for(int j=0;j<=n;++j){
				f[i][j]=-inf;
				if(j>0) f[i][j]=max(f[i][j],f[i-1][j-1]+a[i]);
				if(j<n) f[i][j]=max(f[i][j],f[i-1][j+1]-a[i]);
			}
		}
		for(int j=0;j<=n;++j) ans=max(ans,f[m][j]);
		printf("%lld\n",ans);
	}
	return 0;
}