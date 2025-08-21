#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5005;
const int mod=1e9+7;
int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
int f[N][N];
int query(int x,int n){
	int op=1;//x+1µÄÏÂ½µÃİ 
	int now=(x+1)%mod;
	int sum=0;
	for(int i=0;i<=n;i++){
		op=1ll*op*now%mod;
		now=((now-1)%mod+mod)%mod;
		sum=(sum+1ll*f[n][i]*op%mod*qpow(i+1,mod-2)%mod)%mod;
	}
	return sum;
}
int get(int l,int r,int n){
	return ((query(r,n)-query(l-1,n))%mod+mod)%mod;
}
int n,a[N];
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	scanf("%d",&n);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		f[i][0]=0;
		for(int j=1;j<=i;j++){
			f[i][j]=(f[i-1][j-1]+1ll*j*f[i-1][j]%mod)%mod;
		}
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){// t= a[i-1]+1 ~ a[i]
			int op=1;
			for(int j=i;j<=n;j++) op=1ll*op*qpow(a[j],mod-2)%mod;
			int sum=get(a[i-1],a[i]-1,n-i+1);
			int asd=a[i]-a[i-1];
			asd%=mod;
			sum=(asd-1ll*sum*op%mod)%mod;;
			sum=(sum%mod+mod)%mod;
			ans=(ans+sum)%mod;
		}
	}
	printf("%d",ans);
	return 0;
}
