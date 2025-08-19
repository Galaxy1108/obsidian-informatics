#include <bits/stdc++.h>
using namespace std;

int w[8005], u[8005], t[8005];
int c[22] = {0, 100, 100, 97, 96, 95, 90, 85, 80, 82, 78, 75, 70, 65, 55, 50, 15, 12, 10, 8, 5, 2};
int dp[25000][21][2];
int g[25000][21];

int main(){
    freopen("sniper.in", "r", stdin);
    freopen("sniper.out", "w", stdout);
    int n;
    cin >> n;
    int max_t = 0;
    for (int i = 1; i <= n;i++){
        cin >> w[i] >> u[i] >> t[i];
        max_t = max(max_t, t[i]);
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 20;i++){
        dp[0][i][0] = dp[0][i][1] = 0;
    }
    int this_idx = 1;
    for (int i = 0; i <= max_t;i++){
        for (int j = 1; j <= 20;j++){      
            if(i != 0){      
                dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1]);
            }
            if(i != 0 && dp[i - 1][j][0]!=-1){
                int mmin = max(1, j - 2), mmax = min(20, j + 2);
                for (int k = mmin; k <= mmax;k++){
                    dp[i][k][0] = max(dp[i][k][0], dp[i - 1][j][0]);
                    dp[i][k][1] = max(dp[i][k][1], dp[i - 1][j][0]);
                }
            }
        }
        
        for (int j = 1; j <= 20;j++){
            g[i][j] = dp[i][j][1];
            dp[i][j][1] = -1;
        }
        
        bool is_clean = false;
        while(i==t[this_idx]){
            if(g[i][u[this_idx]]!=-1 && !is_clean){
                dp[i][u[this_idx]][1] = max(g[i][u[this_idx]] + c[w[this_idx]], dp[i][u[this_idx]][1]);
            }
            if(w[this_idx]==15){
                is_clean = true;
                dp[i][u[this_idx]][1] = g[i][u[this_idx]] + c[w[this_idx]];
                for (int j = 1; j <= 20;j++){
                    if(j==u[this_idx]){
                        dp[i][j][0] = -1;
                        continue;
                    }
                    dp[i][j][0] = -1;
                    dp[i][j][1] = -1;
                }
            }
            this_idx++;
        }
    }
    int anss = -1;
    for (int j = 1; j <= 20;j++){
        anss = max({anss, dp[max_t][j][0], dp[max_t][j][1]});
    }
    cout << anss;
}