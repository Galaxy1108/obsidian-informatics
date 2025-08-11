#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll x[2500];
ll dp[2][4000005];
ll n, m;

int main(){
//     freopen("number.in", "r", stdin);
//     freopen("number.out", "w", stdout);
    ll T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for (ll i = 1; i <= m;i++){
            cin >> x[i];
        }
        dp[0][0] = 0;
        for (int j = 1; j <= n;j++){
            dp[0][j] = LLONG_MIN;
        }
        bool I = 1;
        for (int i = 1; i <= m; i++, I^=1){
            for (int j = 0; j <= n;j++){
                if(j==0){
                    if(i==1){
                        
                    }
                    dp[I][j] = ((dp[I ^ 1][j + 1] != LLONG_MIN ? dp[I ^ 1][j + 1] - x[i] : LLONG_MIN));
                    continue;
                }
                if(j==n){
                    dp[I][j] = ((dp[I ^ 1][j - 1] != LLONG_MIN ? dp[I ^ 1][j - 1] + x[i] : LLONG_MIN));
                    continue;
                }
                dp[I][j] = max(((dp[I ^ 1][j + 1] != LLONG_MIN ? dp[I ^ 1][j + 1] - x[i] : LLONG_MIN)), ((dp[I ^ 1][j - 1] != LLONG_MIN ? dp[I ^ 1][j - 1] + x[i] : LLONG_MIN)));
            }
        }
        ll anss = LLONG_MIN;
        I ^= 1;
        for (int j = 0; j <= n;j++){
            anss = max(anss, dp[I][j]);
        }
        cout << anss << '\n';
    }
}