#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int power(int x,int y){
    int res=1;
    while(y){
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
int n,k; 
int dp[505][505],init[1005];
int c(int x,int y){return init[y]*power(init[x]*init[y-x]%mod,mod-2)%mod;}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>k;
    init[0]=init[1]=1;
    for(int i=2;i<=1000;i++)init[i]=init[i-1]*i%mod;
    for(int i=1;i<=k;i++)dp[1][i]=1;
    for(int i=2;i<=n;i++)for(int j=i;j<=k;j++){dp[i][j]=(dp[i][j]+dp[i][j-i+1])%mod;for(int l=1;l<i;l++)dp[i][j]=(dp[i][j]+dp[l][j-i+1]*c(l,i)%mod*power(i-1,i-l)%mod)%mod;}
    int ans=0;
    for(int i=n;i<=k;i++)ans=(ans+dp[n][i])%mod;
    cout<<(power(k,n)+mod-ans)%mod;
    return 0;
}