#include <bits/stdc++.h>
using namespace std;

long long dp[55][55][505];
int a[55][55];

int main(){
    freopen("brike.in", "r", stdin);
    freopen("brike.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = n; i >= 1;i--){
        for (int j = 1; j <= i;j++){
            cin >> a[j][n - i + 1];
        }
    }
    long long anss = LLONG_MIN;
    memset(dp, -0x7f, sizeof(dp));
    for (int i = 0; i <= n + 1;i++){
        dp[i][0][0] = 0;
    }
    for (int i = n; i >= 1;i--){
        long long sum = 0;
        for (int j = 1; j <= i;j++){
            sum += a[n - i + 1][j];
            for (int k = j; k <= m;k++){
                for (int lj = j + 1;lj >= 0; lj--){
                    dp[i][j][k] = max(dp[i][j][k], dp[i + 1][lj][k - j] + sum);
                }
            }
        }
        anss = max(anss, dp[i][1][m]);
    }
    cout << anss;
    return 0;
}