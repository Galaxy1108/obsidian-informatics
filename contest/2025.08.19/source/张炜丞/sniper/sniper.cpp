#include<bits/stdc++.h>
using namespace std;
const int N=8005,M=25005,K=23,inf=1e9,_inf=1e5;

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

int n,qw[N],qu[N],qt[N],dp[M][K][2];
int ew[25]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};

signed main(){
    freopen("sniper.in","r",stdin);
    freopen("sniper.out","w",stdout);
    n=read();
    ew[15]+=_inf;
    int cnt=0,ans=0,m;
    for(int i=1;i<=n;++i){
        qw[i]=read();qu[i]=read();qt[i]=read();if(qw[i]==15)++cnt;
    }
    m=qt[n]+1;
    for(int i=1,j=1;i<=m;++i){
        while(j<=n&&qt[j]<=i){
            dp[i][qu[j]][1]=max(dp[i][qu[j]][1],dp[i-1][qu[j]][0]+ew[qw[j]]);
            ++j;
        }
        // for(int k=1;k<=20;++k)dp[i][k][0]=max(dp[i-1][k][0],dp[i-1][k][1]);
        for(int k=1;k<=20;++k){
            for(int p=max(1,k-2);p<=min(20,k+2);++p){
                // cout<<" k:"<<k<<" p:"<<p<<endl;
                dp[i][k][0]=max(dp[i][k][0],max(dp[i-1][p][0],dp[i-1][p][1]));
            }
            // cout<<" i:"<<i<<" k:"<<k<<" dp:"<<dp[i][k]<<endl;
        }
    }
    for(int i=1;i<=20;++i)ans=max(ans,dp[m][i][0]);
    print(ans-cnt*_inf);putchar('\n');
    return 0;
}