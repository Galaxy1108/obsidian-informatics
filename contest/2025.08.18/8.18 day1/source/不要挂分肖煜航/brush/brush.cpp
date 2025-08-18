#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1e4+5;
int n,m;
ll a[N],f[N][105],s[N][105]; 
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
	for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) f[i][j]=1e18;
	for(int i=1;i<=min(n,m-1);i++){
		f[i][0]=a[i];
		for(int j=i-1;j>=max(1,i-m+1);j--){
			for(int k=0;k<=min(m-1,m-i+j);k++){
				if(k==0){
					f[i][i-j]=min(f[i][i-j],f[j][k]+a[i]);
				}
				else{
					f[i][i-j]=min(f[i][i-j],f[j][k]+a[i]);
				}
			}
		}
	}
	for(int i=m;i<=n;i++){
		for(int j=i-1;j>=max(1,i-m+1);j--){
			for(int k=0;k<=min(m-1,m-i+j);k++){
				if(k==0){
					if(i<=m){
						f[i][i-j]=min(f[i][i-j],f[j][k]+a[i]);
					}
				}
				else{
					f[i][i-j]=min(f[i][i-j],f[j][k]+a[i]);
				}
			}
		}
	}
	ll ans=1e18;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i-j+m-1>=n) ans=min(ans,f[i][j]);
		}
	}
	printf("%lld",ans);
	return 0;
}
