#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,mod;
int dp[N][N*(N-1)/2];
inline void chk(int&x,const int&y){
    (x+=y)>=mod&&(x-=mod);
}
int s[N];
inline int get(int l,int r){
    l=max(l,0);
    if(l>r)return 0;
    if(!l)return s[r];
    int x=s[r];
    chk(x,mod-s[l-1]);
    return x;
}
int f[N*N];
int main(){
    freopen("pairs.in","r",stdin);
    freopen("pairs.out","w",stdout);
    scanf("%d%d",&n,&mod);
    dp[0][0]=1;
    for(int i=0;i<n;i++)for(int j=0;j<=i*(i+1)/2;j++)for(int k=1;k<=i+1;k++)
        chk(dp[i+1][j+(k-1)],dp[i][j]);
    int ans=0;
    for(int len=1;len<=n;len++){
        int res=0;
        memset(f,0,sizeof(f));
        for(int i=2;i<=len;i++){
            for(int j=0;j<=len*(len-1)/2;j++)s[j]=0;
            for(int j=0;j<=(len-1)*(len-2)/2;j++)s[j+(i-1)]=dp[len-1][j];
            for(int j=1;j<=len*(len-1)/2;j++)chk(s[j],s[j-1]);
            for(int j=1;j<=len*(len-1)/2;j++)chk(s[j],s[j-1]);
            for(int j=0;j<=(len-1)*(len-2)/2;j++)chk(f[j],get(j-1,j+i-3));
        }
        for(int j=0;j<=(len-1)*(len-2)/2;j++)chk(res,1ll*dp[len-1][j]*f[j]%mod);
        for(int j=n;j>len;j--)res=1ll*res*j%mod;
        chk(ans,res);
    }
    printf("%d\n",ans);
    return 0;
}
/*
要求第一个数不同
记dp[x][i]表示长度为x,逆序对数量为i的排列有多少个
在开头插入一个数造成的逆序对个数变化值为定值
*/