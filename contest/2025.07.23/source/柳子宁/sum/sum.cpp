#include<bits/stdc++.h>
using namespace std;
int n,m,k,mod;
long long C[110][110];
long long f[110][110];
long long pw[110][10010],V[110][110];
void Init(){
	int N=103;
	for(int i=0;i<=N;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for(int i=0;i<=N;++i){
		pw[i][0]=1;
		for(int j=1;j<=10003;++j) pw[i][j]=pw[i][j-1]*i%mod;
	}
	return;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&k,&mod);
	Init();
	f[0][0]=1;
	for(int t=1;t<=k;++t){
		for(int j=0;j<=m;++j){
			for(int a=0;a<=n;++a){
				V[j][a]=pw[k-t+1][j*a]*pw[t][(m-j)*a]%mod;
			} 
		}
		for(int i=n;i>=0;--i){
			for(int j=m;j>=0;--j){
				for(int a=1;i+a<=n;++a){
					f[i+a][j]=(f[i+a][j]+f[i][j]*C[n-i][a]%mod*V[j][a])%mod;
				}
			}
		}
		
		for(int i=0;i<=n;++i){
			for(int a=0;a<=m;++a){
				V[i][a]=pw[k-t+1][i*a]*pw[t][(n-i)*a]%mod;
			} 
		}
		for(int i=n;i>=0;--i){
			for(int j=m;j>=0;--j){
				for(int a=1;j+a<=m;++a){
					f[i][j+a]=(f[i][j+a]+f[i][j]*C[m-j][a]%mod*V[i][a])%mod;
				}
			}
		}
		
		
		for(int j=0;j<=m;++j){
			for(int a=0;a<=n;++a){
				V[j][a]=pw[k-t][j*a]*pw[t][(m-j)*a]%mod;
			} 
		}
		for(int i=n;i>=0;--i){
			for(int j=m;j>=0;--j){
				for(int a=1;i+a<=n;++a){
					if(a&1) f[i+a][j]=(f[i+a][j]-f[i][j]*C[n-i][a]%mod*V[j][a])%mod;
					else f[i+a][j]=(f[i+a][j]+f[i][j]*C[n-i][a]%mod*V[j][a])%mod;
				}
			}
		}
		
		for(int i=0;i<=n;++i){
			for(int a=0;a<=m;++a){
				V[i][a]=pw[k-t][i*a]*pw[t][(n-i)*a]%mod;
			} 
		}
		for(int i=n;i>=0;--i){
			for(int j=m;j>=0;--j){
				for(int a=1;j+a<=m;++a){
					if(a&1) f[i][j+a]=(f[i][j+a]-f[i][j]*C[m-j][a]%mod*V[i][a])%mod;
					else f[i][j+a]=(f[i][j+a]+f[i][j]*C[m-j][a]%mod*V[i][a])%mod;
				}
			}
		}
	}
	printf("%lld\n",(f[n][m]+mod)%mod);
	return 0;
}
