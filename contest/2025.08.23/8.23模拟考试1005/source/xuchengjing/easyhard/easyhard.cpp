#include <cstdio>
long long dp[2][3001];
int main(){
  freopen("easyhard.in","r",stdin);
  freopen("easyhard.out","w",stdout);
  int n,m,p;
  scanf("%d%d%d",&n,&m,&p);
  for(int i=0;i<=n;i++) dp[1][i]=1;
  for(int i=0;i<m;i++){
    dp[i&1][0]=(dp[!(i&1)][0]+dp[!(i&1)][1])%p;
    for(int j=1;j<n;j++){
      dp[i&1][j]=((dp[!(i&1)][j]<<1)+dp[!(i&1)][j-1]+dp[!(i&1)][j+1])%p;
    }
    dp[i&1][n]=(dp[!(i&1)][n-1]+dp[!(i&1)][n])%p;
    // for(int j=0;j<=n;j++) printf("%6lld",dp[i&1][j]);printf("\n");
  }
  int ans=0;
  for(int i=0;i<=n;i++){
    ans=(ans+dp[!(m&1)][i])%p;
  }
  printf("%d\n",ans);
}
