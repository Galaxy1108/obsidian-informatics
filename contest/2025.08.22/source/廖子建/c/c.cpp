#include<bits/stdc++.h>
#include <random>
#include <algorithm>
#define int long long
#define N 5000
#define M 1000000
#define R ((i+x-1)%n+1)
using namespace std;
int a[N+5][N+5];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
    return;
}
int n,seed,m,dp[2][M+5];
int read(){
    int f=1,g=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        g=g*10+ch-'0';
        ch=getchar();
    }
    return f*g;
}
void print(int x){
    if(x<0){
        putchar('-');
        x*=-1;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
    return;
}
int cnt(int x){
    int sum=0;
    while(x)sum+=x&1,x>>=1;
    return sum;
}
int solve(int x){
    for(int i=0;i<m;i++)dp[n&1][i]=0;
    for(int i=1;i<=n+1;i++)dp[n&1][1<<(i-1)]=i;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<m;j++){
            if(cnt(j)!=n-i+1)continue;
            dp[i&1][j]=0;
            for(int k=1;k<=n+1;k++){
                if(((j>>(k-1))&1)==0)continue;
                if(a[R][dp[i&1][j]]<a[R][dp[i&1^1][j^(1<<(k-1))]]){
                    dp[i&1][j]=dp[i&1^1][j^(1<<(k-1))];
                }
            }
        }
    }
    return dp[0][m-1];
}
main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    n=read(),seed=read(),m=1<<(n+1);
    if(seed)gen(n,seed);
    else for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)a[i][j]=read();
    for(int i=1;i<=n;i++)print(solve(i)),putchar(' ');
    return 0;
}
