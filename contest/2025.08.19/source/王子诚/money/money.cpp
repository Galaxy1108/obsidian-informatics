#include <bits/stdc++.h>
using namespace std;

int w[2005];
long double c[2005], d[2005];
struct s{
    long double m, r;
};
s dp[2005][4];

int main(){
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    int n, cost;
    cin >> n >> cost;
    for (int i = 1; i <= n;i++){
        cin >> w[i] >> c[i] >> d[i];
    }
    for (int i = 1; i <= n;i++){
        dp[i][0].r = max({dp[i-1][0].r + w[i], dp[i-1][1].r + dp[i-1][1].m * d[i] - cost + w[i], dp[i-1][2].r + dp[i-1][2].m * d[i] - cost + w[i], dp[i-1][3].m * d[i] - cost + w[i]});
        dp[i][1].r = max({dp[i-1][0].r, dp[i-1][1].r + dp[i-1][1].m * d[i] - cost, dp[i-1][2].r + dp[i-1][2].m * d[i] - cost, dp[i-1][3].m * d[i] - cost});
        dp[i][1].m = w[i] * c[i];
        dp[i][2].m = max({dp[i-1][0].r * c[i], dp[i-1][1].m + dp[i-1][1].r * c[i], dp[i-1][2].r * c[i] + dp[i-1][2].m, dp[i-1][3].m});
        dp[i][2].r = w[i];
        dp[i][3].m = max({(dp[i-1][0].r + w[i]) * c[i], (dp[i-1][1].r + w[i]) * c[i] + dp[i-1][1].m, (dp[i-1][2].r + w[i]) * c[i] + dp[i-1][2].m, dp[i-1][3].m + w[i] * c[i]});
    }
    printf("%.4Lf", max({dp[n][0].r, dp[n][1].m * d[n] - cost + dp[n][1].r, dp[n][2].m * d[n] - cost + dp[n][2].r, dp[n][3].m * d[n] - cost}));
}
