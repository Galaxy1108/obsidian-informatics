#include <bits/stdc++.h>
using namespace std;
int a[55][55];
int dp[55][55][505];
int book[55][55];
int n,m;
int ans;
int main(){
    // memset(dp,0x8f,sizeof(dp));
    freopen("brike.in","r",stdin);
    freopen("brike.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            for(int k=1;k<=m;k++){
                dp[i][j][k]=max(dp[i-1][j+1][k],dp[i-1][j][k])+a[i][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            ans=max(ans,dp[i][j][m]);
        }
    }
    cout << ans+1;
    return 0;
}