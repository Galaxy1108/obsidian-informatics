#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=20010;
int n,mod;
int f[N],g[N];
int inv[N],fac[N];
int qpow(int d,int z){
	int res=1,now=d;
	while(z){
		if(z&1) res=res*now%mod;
		now=now*now%mod; z>>=1;
	}
	return res;
}
void init(){
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
} 
int C(int x,int y){
	return fac[x]*inv[x-y]%mod*inv[y]%mod;
}
signed main(){
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	cin>>n>>mod;
	init();
	int ans=0;
	for(int i=1;i<=n;i++){
		f[i]=1;
		for(int j=0;j<=i;j++){
			f[i]=f[i]*C(i,j);
		}
		for(int j=1;j<=sqrt(f[i]);j++){
			if(f[i]%j==0){
				if(j*j==f[i]) g[i]=(g[i]+j)%mod;
				else g[i]=(g[i]+j+f[i]/j)%mod;
			} 
		}
		ans=(ans+g[i])%mod;
	}
	cout<<ans;
	return 0;
}

