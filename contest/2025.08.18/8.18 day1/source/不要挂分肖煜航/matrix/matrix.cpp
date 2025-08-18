#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long 
using namespace std;
int n,m,K;
ll a[105][15];
namespace solve1{
	ll f[105][15];
	void solve(){
		for(int i=0;i<=n;i++) for(int j=0;j<=K;j++) f[i][j]=-1e18;
		f[0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=K;j++) f[i][j]=max(f[i][j],f[i-1][j]);
			for(int j=1;j<=K;j++){
				ll sum=0;
				for(int l=i;l;l--){
					sum+=a[l][1];
					f[i][j]=max(f[i][j],f[l-1][j-1]+sum);
				}
			}
		}
		printf("%lld",max(0ll,f[n][K]));
	}
}
namespace solve2{
	ll f[105][15][5];
	ll sum[105][3];
	ll s[105][15];
	void solve(){
		for(int i=0;i<=n;i++) for(int j=0;j<=K;j++) for(int op=0;op<5;op++) f[i][j][op]=-1e18; 
		f[0][0][4]=0;
		for(int i=1;i<=n;i++){
			sum[i][0]=a[i][1]+sum[i-1][0];
			sum[i][1]=a[i][2]+sum[i-1][1];
			sum[i][2]=sum[i][0]+sum[i][1];
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=K;j++) for(int op=0;op<5;op++) f[i][j][0]=max(f[i][j][0],f[i-1][j][op]);
			for(int j=1;j<=K;j++){//接 
				for(int k=i;k;k--){
					f[i][j][1]=max(f[i][j][1],max(f[k-1][j][1],f[k-1][j][3])+sum[i][0]-sum[k-1][0]);
					f[i][j][2]=max(f[i][j][2],max(f[k-1][j][2],f[k-1][j][3])+sum[i][1]-sum[k-1][1]);
					if(j>1) f[i][j][3]=max(f[i][j][3],f[k-1][j][3]+sum[i][2]-sum[k-1][2]);
					f[i][j][4]=max(f[i][j][4],f[k-1][j][4]+sum[i][2]-sum[k-1][2]);
					if(j>1) f[i][j][3]=max(f[i][j][3],max(f[k-1][j-1][1],f[k-1][j-1][2])+sum[i][2]-sum[k-1][2]);
				}
			}
			for(int j=1;j<=K;j++){//自己建 
				for(int k=i;k;k--){
					f[i][j][1]=max(f[i][j][1],s[k-1][j-1]+sum[i][0]-sum[k-1][0]);
					f[i][j][2]=max(f[i][j][2],s[k-1][j-1]+sum[i][1]-sum[k-1][1]);
					f[i][j][4]=max(f[i][j][4],s[k-1][j-1]+sum[i][2]-sum[k-1][2]);
					if(j>1) f[i][j][3]=max(f[i][j][3],s[k-1][j-2]+sum[i][2]-sum[k-1][2]);
				}
			}
			for(int j=0;j<=K;j++) s[i][j]=max(f[i][j][0],max(f[i][j][1],max(f[i][j][2],max(f[i][j][3],f[i][j][4]))));
		}
		ll ans=0;
		for(int i=0;i<5;i++) ans=max(ans,f[n][K][i]);
		printf("%lld",ans);
	}
}
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d%d",&n,&m,&K);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%lld",&a[i][j]);
	if(m==1) solve1::solve();
	else solve2::solve();
	return 0;
}
