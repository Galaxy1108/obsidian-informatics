#include <bits/stdc++.h>
using namespace std;
constexpr int N=505,mod=998244353;
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
int fact[N],inv[N]; 
int f[N][N];
int C(int x,int y){
	return 1ll*fact[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	fact[0]=1;
	for(int i=1;i<=500;i++) fact[i]=1ll*fact[i-1]*i%mod;
	inv[500]=qpow(fact[500],mod-2);inv[0]=1;
	for(int i=499;i;i--){
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i>j){
				f[i][j]=((qpow(j,i)-qpow(j-1,i))%mod+mod)%mod;
			}
			else{
				for(int l=1;l<=i;l++){
					f[i][j]=(f[i][j]+1ll*C(i,l)*qpow(i-1,i-l)%mod*f[l][j-i+1]%mod)%mod;
				}
			}
		}
	}
	int sum=0;
	for(int i=1;i<=m;i++){
		sum=(sum+f[n][i])%mod;
	}
	printf("%d",sum);
	return 0;
}
