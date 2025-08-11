#include <bits/stdc++.h>
using namespace std;

int sn[200005];
long long dp[200005][5];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> sn[i];
    }
    for (int i = 1; i <= n;i++){
        dp[i][0] = dp[i - 1][0] + sn[i];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][2] = min(dp[i][1], dp[i - 1][2]);
        dp[i][3] = min(dp[i][2], dp[i - 1][3]);
        dp[i][4] = min(dp[i][3], dp[i - 1][4]) + sn[i];
        if (sn[i] == 0){
            dp[i][1] += 2; //一来一回
            dp[i][2] += !(sn[i] % 2);
            dp[i][3] += 2;
        }else{
            dp[i][1] += sn[i] & 1;
            dp[i][2] += !(sn[i] % 2);
            dp[i][3] += sn[i] & 1;
        }
    }
    long long anss = dp[n][0];
    for (int i = 1; i <= 4; i++){
        anss = min(anss, dp[n][i]);
    }
    cout << anss;
    return 0;
}

