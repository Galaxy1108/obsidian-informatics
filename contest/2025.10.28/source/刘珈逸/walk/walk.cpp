#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N],n;
long long dp[N][5];
int calc1(int x){
    return 1-(x&1);
}
int calc2(int x){
    if(!x)return 2;
    return x&1;
}
int main(){
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i);
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+a[i];
        dp[i][1]=dp[i-1][1]+calc2(a[i]);
        dp[i][2]=dp[i-1][2]+calc1(a[i]);
        dp[i][3]=dp[i-1][3]+calc2(a[i]);
        dp[i][4]=dp[i-1][4]+a[i];
        for(int j=1;j<=4;j++)dp[i][j]=min(dp[i][j],dp[i][j-1]);
    }
    printf("%lld\n",dp[n][4]);
    return 0;
}
/*
考虑判断一组序列最后能否合法
起点到终点为奇数
不妨设s<=t
设最左到l，最右到r，则[l,s)与(t,r]为>=2的偶数
对着做dp即可
*/