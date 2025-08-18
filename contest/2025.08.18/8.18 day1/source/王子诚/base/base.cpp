#include <bits/stdc++.h>
using namespace std;

int a[2005], b[2005];
int dp[2005][3];

#define inf 2000000005

int main(){
    freopen("base.in", "r", stdin);
    freopen("base.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        cin >> b[i];
    }
    dp[0][1] = dp[0][2] = dp[0][3] = -inf;
    int anss = INT_MIN;
    for (int i = 1; i <= n;i++){
        dp[i][0] = max(dp[i - 1][0] + a[i] + b[i], a[i] + b[i]);
        dp[i][1] = max(dp[i - 1][0] + b[i], dp[i - 1][1] + b[i]);
        dp[i][2] = max(dp[i - 1][1] + a[i] + b[i], dp[i - 1][2] + a[i] + b[i]);
        anss = max(anss, dp[i][2]);
    }
    cout << anss;
    return 0;
}