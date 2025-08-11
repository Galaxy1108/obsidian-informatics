#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int n,cnt0,cnt1;
int a[1210],tag[1210];
long long INV=1,inv2=500000004;
long long c[1210][1210];
long long f[1210][1210],g[1210];
void Init(){
	int N=1203;
	for(int i=0;i<=N;++i){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;++j){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
}
long long C(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return c[n][m];
}
int main()
{
	freopen("ruin.in","r",stdin);
	freopen("ruin.out","w",stdout);
	Init();
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		tag[a[i]]=1;
		INV=INV*inv2%mod;
	}
	f[2*n+1][0]=1;
	g[0]=1;
	for(int i=1;i<=2*n;++i){
		for(int j=1;j<=i;++j){
			g[i]=(g[i]+g[j-1]*g[i-j]%mod*(i-j+2)%mod*C(i-1,j-1))%mod;
		}
	}
	for(int i=2*n;i>=1;--i){
		if(tag[i]==1){
			++cnt1;
			for(int j=0;j<=cnt1;++j){
				f[i][j]=(f[i][j]+f[i+1][j])%mod;
			}
			for(int k=1;k<=cnt1;++k){
				for(int j=0;j<k;++j){
					f[i][k]=(f[i][k]+f[i+1][j]*C(cnt1-j-1,k-j-1)%mod*g[k-j-1]%mod*(k-j+1))%mod;
				}
			}
		}
		else{
			for(int j=0;j<=cnt1;++j){
				f[i][j]=(f[i][j]+f[i+1][j]*(j-cnt0))%mod;
			}
			++cnt0;
		}
	}
	printf("%lld\n",f[1][n]*INV%mod);
	return 0;
}
