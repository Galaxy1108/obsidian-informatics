#include <algorithm>
#include <cstdio>
#include <cstring>
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
signed main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	int fee[101][101],n,m;
	int mn[101],inp;
	memset(fee, 0x3f, sizeof(fee));
	scanf("%lld%lld",&n,&m);m--;
	for(int i=0;i<n;i++){
		memset(mn, 0x3f, sizeof(mn));
		scanf("%lld",&inp);
		for(int j=0;j<m;j++)
			for(int k=0;k+j<m;k++)
				mn[j]=std::min(mn[j],fee[k][j]);
		for(int j=0;j<m;j++)
			for(int k=m-1-j;k;k--)
				fee[j][k]=fee[j][k-1];
		if(i<m) mn[i]=0;	
		for(int j=0;j<m;j++) fee[j][0]=std::min(INF,mn[j]+inp);
	}
	int ans=INF;
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			ans=std::min(ans, fee[i][j]);
		}
	}
	printf("%lld\n",ans);
}