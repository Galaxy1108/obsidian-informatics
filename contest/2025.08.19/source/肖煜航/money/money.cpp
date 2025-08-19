#include<cstdio>
#include<algorithm>
#define db double 
using namespace std;
const int N=2005;
int n;
db c,w[N],a[N],b[N];
db f[N],g[N];
int main(){
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d%lf",&n,&c);
	for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&w[i],&a[i],&b[i]);
	f[0]=g[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1]+w[i],g[i-1]*b[i]+w[i]-c);
		g[i]=max(g[i-1]+w[i]*a[i],f[i]*a[i]); 
		db sum=0;
		for(int j=i;j;j--){
			sum+=w[j];
//			g[i]=max(g[i],g[j-1]+sum*a[i]);
			g[i]=max(g[i],(f[j-1]+sum)*a[i]);
			f[i]=max(f[i],sum+g[j-1]*b[i]-c);
		}
	}
	printf("%.4lf",f[n]);
	return 0;
}
