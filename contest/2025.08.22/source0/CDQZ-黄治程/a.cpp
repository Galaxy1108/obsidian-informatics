#include<bits/stdc++.h>
using namespace std;
const int N=10000010;
int n,m,mod,f[2][N];
void adc(int &x,int y){
	x+=y;
	if(x>=mod){
		x-=mod;
	}
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int ans=0,summ,sum1;
	scanf("%d%d%d",&n,&m,&mod);
	for(int i=1;i<=m;i++){
		f[0][i]=m-i+1;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			adc(f[1][1],1ll*f[0][j]*(m-j+1)%mod);
		}
		summ=sum1=0;
		for(int j=2;j<=m;j++){
			adc(sum1,f[0][j-1]);
			f[1][j]=(f[1][j-1]-1ll*f[0][m-j+2]*(m-j+1)%mod+mod-sum1+mod+summ)%mod;
			adc(summ,f[0][m-j+2]);
		}
		for(int j=1;j<=m;j++){
			f[0][j]=f[1][j];
			f[1][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		adc(ans,f[0][i]);
	}
	printf("%d",ans);
}