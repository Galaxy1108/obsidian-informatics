#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
struct Martix{
	int a[10][10];
	int*operator[](int x){return a[x];}
	void clear(){
		memset(a,0,sizeof(a));
	}
}Bas,dp;
Martix operator*(Martix x,Martix y){
	Martix res;res.clear();
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)for(int k=0;k<10;k++)
		res[i][j]=(res[i][j]+1ll*x[i][k]*y[k][j])%mod;
	return res;
}
long long k;
int ans;
int main(){
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	scanf("%lld",&k);k--;
	Bas.clear(),dp.clear();
	for(int i=0;i<10;i++)Bas[i][i]=1;
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)if(abs(i-j)<=2)dp[i][j]=1;
	while(k){
		if(k&1)Bas=Bas*dp;
		k>>=1;dp=dp*dp;
	}
	for(int i=0;i<10;i++)for(int j=1;j<10;j++)ans=(ans+Bas[i][j])%mod;
	printf("%d\n",ans);
	return 0;
}
