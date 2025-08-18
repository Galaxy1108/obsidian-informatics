#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=105,M=13,inf=1e9;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int a[N][2],s[N][2],f[N][N][3],dp[N][N][M];
int n,m,k,g[N][M];

void work1(){
    memset(g,-0x3F,sizeof(g));
    g[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            f[i][j][0]=-inf;
            for(int kd=i;kd<=j;++kd){
                f[i][j][0]=max(f[i][j][0],s[j][0]-s[kd-1][0]);
            }
        }
    }
    for(int i=1;i<=k;++i){
        for(int j=1;j<=n;++j){
            for(int kd=0;kd<j;++kd){
                g[j][i]=max(g[j][i],g[kd][i-1]+f[kd+1][j][0]);
            }
        }
    }
    int ans=-inf;
    for(int i=1;i<=n;++i){
        ans=max(ans,g[i][k]);
        // cout<<" i:"<<i<<" g:"<<g[i][k]<<endl;
    }
    print(ans);putchar('\n');
}

void work2(){
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            f[i][j][0]=f[i][j][1]=f[i][j][2]=-inf;
            for(int kd=i;kd<=j;++kd){
                f[i][j][0]=max(f[i][j][0],s[j][0]-s[kd-1][0]);
                f[i][j][1]=max(f[i][j][1],s[j][1]-s[kd-1][1]);
                f[i][j][2]=max(f[i][j][2],s[j][0]-s[kd-1][0]+s[j][1]-s[kd-1][1]);
            }
        }
    }
    memset(dp,-0x3F,sizeof(dp));
    dp[0][0][0]=0;
    for(int i=1;i<=k;++i){
        for(int j=0;j<=n;++j){
            for(int p=0;p<=n;++p){
                for(int l=j+1;l<=n;++l)dp[l][p][i]=max(dp[l][p][i],dp[j][p][i-1]+f[j+1][l][0]);
                for(int l=p+1;l<=n;++l)dp[j][l][i]=max(dp[j][l][i],dp[j][p][i-1]+f[p+1][l][1]);
                for(int l=max(j,p)+1;l<=n;++l)dp[l][l][i]=max(dp[l][l][i],dp[j][p][i-1]+f[max(j,p)+1][l][2]);
            }
        }
    }
    int ans=-inf;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            ans=max(ans,dp[i][j][k]);
        }
    }
    print(ans);putchar('\n');
}

signed main(){
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    n=read();m=read();k=read();
    for(int i=1;i<=n;++i){
        for(int j=0;j<m;++j){
            a[i][j]=read();
            s[i][j]=s[i-1][j]+a[i][j];
        }
    }
    if(m==1)work1();
    else work2();
    return 0;
}