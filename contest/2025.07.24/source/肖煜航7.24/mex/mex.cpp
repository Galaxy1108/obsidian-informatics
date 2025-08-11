#include<cstdio>
#include<algorithm>
using namespace std;
const int mod=998244353;
const int N=5005;
int qpow(int x,int y){
	int ans=1;
	while(y){
		if(y&1) ans=1ll*ans*x%mod;
		y>>=1;
		x=1ll*x*x%mod;
	}
	return ans;
}
int n,m;
int s[N];
int f[N][N];
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	scanf("%d%d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		if(s[i]==0) cnt++;
	}
	if(m>=n) printf("%d",qpow(m,cnt));
	else{
		m++;
		f[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i]==1) f[i][j]=f[i-1][j-1];
				else{
					f[i][j]=((1ll*f[i-1][j]*j%mod+1ll*f[i-1][j-1]*(m-j)%mod)%mod+f[i][j])%mod;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++) ans=(ans+f[n][i])%mod;
		printf("%d",ans);
	}
	return 0;
}

