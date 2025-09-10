#include <cstdio>
#define mod 9999973
int dp[2][100][100];
int main(){
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    dp[0][n][0]=1;
    for(int i=1;i<=m;i++)
	for(int j=0;j<=n;j++)
	    for(int k=0;k<=n-j;k++){
#define mv(x,y,val)\
		dp[i&1][j][k]=(dp[i&1][j][k]+\
		    (((j+x>=0&&j+x<=n)&&(k+y>=0&&k+y<=n))?\
		     ((1ll*dp[!(i&1)][j+x][k+y]*(val))%mod):0))%mod
		dp[i&1][j][k]=0;
		mv(0,0,1);
		mv(1,-1,j+1);
		mv(2,-2,(j+2)*(j+1)>>1);
		mv(0,1,k+1);
		mv(1,0,(j+1)*k);
		mv(0,2,(k+2)*(k+1)>>1);
	    }
    int ans=0;
    for(int j=0;j<=n;j++){
	for(int k=0;k<=n-j;k++){
	    ans=(ans+dp[m&1][j][k])%mod;
	}
    }
    printf("%d\n",ans);
}
