#include<cstdio>
#include<algorithm>
#define ll long long
#define INF 1000000000000000000
using namespace std;
const int N=2005;
bool st; 
int n,m;
ll f[N][N],a[N];
namespace solve1{
	ll f[300005][3];
	void solve(){
		for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) f[i][j]=-INF;
		f[m][1]=a[m];
		for(int i=m-1;i;i--){
			f[i][0]=f[i+1][1]-a[i];
			f[i][n]=f[i+1][n-1]+a[i];
			for(int j=1;j<n;j++) f[i][j]=max(f[i+1][j+1]-a[i],f[i+1][j-1]+a[i]);
		}
		ll mx=-INF;
		for(int i=0;i<=n;i++) mx=max(mx,f[1][i]);
		printf("%lld\n",mx);
	}
}
bool ed;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	printf("%d",(&ed-&st)/1024/1024); 
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
		if(n<=2){
			solve1::solve();			
			continue;
		}
		for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) f[i][j]=-INF;
		f[m][1]=a[m];
		for(int i=m-1;i;i--){
			f[i][0]=f[i+1][1]-a[i];
			f[i][n]=f[i+1][n-1]+a[i];
			for(int j=1;j<n;j++) f[i][j]=max(f[i+1][j+1]-a[i],f[i+1][j-1]+a[i]);
		}
		ll mx=-INF;
		for(int i=0;i<=n;i++) mx=max(mx,f[1][i]);
		printf("%lld\n",mx);
	}
	return 0;
} 
