#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=3005; 
int n,m,mod;
int f[N][N][4];
int g[N][4];
int main(){
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mod); 
	g[0][0]=1;
	for(register int i=0;i<=n;i++) f[0][0][i]=1;
	for(register int i=1;i<=m;i++){
		for(register int s=0;s<4;s++){
			if(s<2){
				for(register int t=0;t<4;t++){
					int can=0;
					for(register int j=1;j<=n;j++) can|=f[i-1][t][j];
					if(can){
						g[i][s]=(g[i][s]+g[i-1][t])%mod;
						for(register int j=1;j<=n;j++){
							if(t==0) f[i][s][j]|=f[i-1][t][j];
							else f[i][s][j-1]|=f[i-1][t][j];
						}
					}
				}
			}
			else{
				for(register int t=0;t<4;t++){
					int can=0;
					for(register int j=0;j<n;j++) can|=f[i-1][t][j];
					if(can){
						g[i][s]=(g[i][s]+g[i-1][t])%mod;
						for(register int j=0;j<n;j++){
							if(t==2) f[i][s][j]|=f[i-1][t][j];
							else f[i][s][j+1]|=f[i-1][t][j];
						}
					}
				}
			}
		}
	} 
	int sum=0;
	for(register int i=0;i<4;i++) sum=(sum+g[m][i])%mod;
	printf("%d",sum);
	return 0;
}
