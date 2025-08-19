#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,x,mod,m,a[N],b[N];
int S[N][N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%mod;
		b>>=1;a=1ll*a*a%mod;
	}return ans;
}
int main(){
	freopen("combination.in","r",stdin);
	freopen("combination.out","w",stdout);
	scanf("%d%d%d%d",&n,&x,&mod,&m);
	for(int i=0;i<=m;i++)scanf("%d",a+i);
	S[0][0]=1;
	for(int i=1;i<=m;i++)for(int j=1;j<=i;j++)
		S[i][j]=(S[i-1][j-1]+1ll*j*S[i-1][j])%mod;
	for(int i=0;i<=m;i++)for(int j=0;j<=i;j++)
		b[j]=(b[j]+1ll*S[i][j]*a[i])%mod;
	int ans=0;
	for(int i=0,vnow=1;i<=m;i++){
		b[i]=1ll*b[i]*vnow%mod;
		ans=(ans+1ll*b[i]*qpow(x,i)%mod*qpow(x+1,n-i))%mod;
		vnow=1ll*vnow*(n-i)%mod;
	}printf("%d\n",ans);
	return 0;
}
