#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,x;
long long pw[510][510],C[510][510],f[510][510];
long long F(int n,int x){
	if(n==0) return 1;
	if(n==1||x<=0) return 0;
	if(n==2) return x;
	
	if(x<n) return pw[x][n];
	if(f[n][x]!=-1) return f[n][x];
	long long ans=0;
	for(int i=0;i<=n;++i){
		ans=(ans+F(n-i,x-(n-1))%mod*C[n][i]%mod*pw[n-1][i])%mod;
	}
	f[n][x]=ans;
	return ans;
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	
	scanf("%d%d",&n,&x);
	for(int i=0;i<=503;++i){
		pw[i][0]=1;
		C[i][i]=C[i][0]=1;
		for(int j=1;j<=503;++j){
			pw[i][j]=pw[i][j-1]*i%mod;
		}
		for(int j=1;j<i;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	
	memset(f,-1,sizeof(f));
	
	printf("%lld\n",F(n,x));
	return 0;
} 
