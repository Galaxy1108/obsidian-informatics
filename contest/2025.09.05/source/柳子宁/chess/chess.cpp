#include<bits/stdc++.h>
#define mod 9999973
using namespace std;
int n,m;
long long f[2][110][110],ans;
int main()
{
	freopen("chess.in","r",stdin); 
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	f[0][0][m]=1;
	for(int i=1;i<=n;++i){
		int o=i&1;
		memset(f[o],0,sizeof(f[o]));
		for(int j=0;j<=m;++j){
			for(int k=0;k<=m;++k){
				f[o][j][k]=(f[o^1][j][k]+f[o][j][k])%mod; 
				if(j) f[o][j-1][k]=(f[o^1][j][k]*j+f[o][j-1][k])%mod; 
				if(k) f[o][j+1][k-1]=(f[o^1][j][k]*k+f[o][j+1][k-1])%mod; 
				if(j>=2) f[o][j-2][k]=(f[o^1][j][k]*j*(j-1)/2+f[o][j-2][k])%mod; 
				if(k) f[o][j][k-1]=(f[o^1][j][k]*j*k+f[o][j][k-1])%mod;
				if(k>=2) f[o][j+2][k-2]=(f[o^1][j][k]*k*(k-1)/2+f[o][j+2][k-2])%mod; 
			}
		}
	}
	for(int j=0;j<=m;++j){
		for(int k=0;k<=m;++k){
			ans=(ans+f[n&1][j][k])%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
