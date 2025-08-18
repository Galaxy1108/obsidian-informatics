#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int n;
ll a[5][2005];
ll b[2005][3];
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=2;i++){
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	} 
	for(int i=0;i<=n;i++) b[i][0]=b[i][1]=b[i][2]=-1e15;
	ll ans=-1e18;
	for(int i=1;i<=n;i++){
		ll sum1=0,sum2=0;
		for(int j=i;j;j--){
			sum1+=a[1][j];
			sum1+=a[2][j];
			sum2+=a[2][j];
			b[i][0]=max(b[i][0],sum1);
			if(j>1) b[i][1]=max(b[i][1],b[j-1][0]+sum2);
			if(j>2) b[i][2]=max(b[i][2],b[j-1][1]+sum1);
		}
		ans=max(ans,b[i][2]);
	}
	printf("%lld",ans);
	return 0;
}
