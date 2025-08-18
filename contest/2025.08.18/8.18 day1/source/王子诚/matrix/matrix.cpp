#include <bits/stdc++.h>
using namespace std;

int a[105][2];
int dp[105][15][5];

int main(){
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    int n, m, K;
    cin >> n >> m >> K;
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            cin >> a[i][j];
        }
        if(m==1){
            a[i][2] = -0x3f;
        }
    }
    memset(dp, -0x7f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n;i++){
        dp[i][0][0] = 0;
        for (int k = 1; k <= K;k++){
            dp[i][k][0] = max({dp[i - 1][k][0], dp[i - 1][k][1], dp[i - 1][k][2], dp[i - 1][k][3], dp[i - 1][k][4]});
            dp[i][k][1] = max({dp[i - 1][k - 1][0], dp[i - 1][k][1], dp[i - 1][k - 1][2], dp[i - 1][k - 1][3], dp[i - 1][k][4]}) + a[i][1];
            dp[i][k][2] = max({dp[i - 1][k - 1][0], dp[i - 1][k - 1][1], dp[i - 1][k][2], dp[i - 1][k - 1][3], dp[i - 1][k][4]}) + a[i][2];
            dp[i][k][3] = max({dp[i - 1][k - 1][0], dp[i - 1][k - 1][1], dp[i - 1][k - 1][2], dp[i - 1][k][3], dp[i - 1][k - 1][4]}) + a[i][1] + a[i][2];
            if(k>1){
                dp[i][k][4] = max({dp[i - 1][k - 2][0], dp[i - 1][k - 1][1], dp[i - 1][k - 1][2], dp[i - 1][k - 1][3], dp[i - 1][k][4]}) + a[i][1] + a[i][2];
            }
        }
    }
    cout << max({dp[n][K][0], dp[n][K][1], dp[n][K][2], dp[n][K][3], dp[n][K][4]});
    return 0;
}