#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5,mod=998244353;
int dp[N][N],pw[N][N],C[N][N];
int n,m;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    for(int i=1;i<=500;i++){
        pw[i][0]=1;
        for(int j=1;j<=500;j++)pw[i][j]=1ll*pw[i][j-1]*i%mod;
    }
    C[0][0]=1;
    for(int i=1;i<=500;i++){
        C[i][0]=1;
        for(int j=1;j<=500;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)dp[1][i]=i;
    for(int i=2;i<=n;i++)for(int j=1;j<=m;j++){
        for(int k=i-1;k<j;k+=i-1)for(int l=1;l<i;l++)
            dp[i][j]=(dp[i][j]+1ll*dp[i-l][j-k]*pw[i-1][l]%mod*C[i][l])%mod;
    }
    printf("%d\n",(pw[m][n]+mod-dp[n][m])%mod);
    return 0;
}
/*
容斥为计算最后存在胜利者的方案数
设dp[i][j]表示还存在i个人，生命最大值为j且存在最后胜利者的方案数
dp[1][x]=x
枚举最后死了几个人，是在第几波后死的
*/