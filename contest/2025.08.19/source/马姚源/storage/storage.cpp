#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int dis[N],c[N],p[N];
int dp[N][2];
signed main(){
    freopen("storage.in","r",stdin);
    freopen("storage.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> dis[i] >> p[i] >> c[i];
    }for(int i=1;i<=n;i++)dp[i][0]=dp[i][1]=9e18;
    dp[n][0]=dp[n][1]=c[n];
    for(int i=n-1;i>=1;i--){
        for(int j=n;j>i;j--){
            dp[i][0]=min(dp[j][1]+p[i]*(dis[j]-dis[i]),dp[i][0]);
            dp[i][1]=min(dp[j][0],dp[j][1])+c[i];
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << dp[i][0] << " ";
    // }
    // cout << endl;
    // for(int i=1;i<=n;i++){
    //     cout << dp[i][1] << " ";
    // }
    // cout << endl;
    cout  << min(dp[1][0],dp[1][1]);
    return 0;
}