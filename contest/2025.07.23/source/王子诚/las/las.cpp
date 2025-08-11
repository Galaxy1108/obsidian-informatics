#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll c[1000006];
ll dp[1000005][2][2];
ll anss[1000005], tops, n;

void out_anss(ll a,ll b){
    for (int i = n + 1; i >= 2;i--){
        if(a==0 && b==0){
            if(dp[i - 1][1][1] && c[i] >= 2 * c[i + 1]){
                a = 1, b = 1;
                if(i==n+1){
                    anss[++tops] = 1;
                }else{
                    anss[++tops] = i;
                }
                continue;
            }else{
                a = 0, b = 1;
                anss[++tops] = i - 1;
                continue;
            }
        }
        if(a==0 && b==1){
            if(dp[i - 1][0][1] && 2 * c[i] >= c[i + 1]){
                a = 0, b = 1;
                anss[++tops] = i - 1;
                continue;
            }else{
                a = 1, b = 1;
                if(i==n+1){
                    anss[++tops] = 1;
                }else{
                    anss[++tops] = i;
                }
                continue;
            }
        }
        if(a==1 && b==0){
            if(dp[i - 1][1][0] && 2 * c[i + 1] >= c[i]){
                a = 1, b = 0;
                if(i==n+1){
                    anss[++tops] = 1;
                }else{
                    anss[++tops] = i;
                }
                continue;
            }else{
                a = 0, b = 0;
                anss[++tops] = i - 1;
                continue;
            }
        }
        if(a==1 && b==1){
            if(dp[i - 1][0][0] && c[i + 1] >= 2 * c[i]){
                a = 0, b = 0;
                anss[++tops] = i - 1;
                continue;
            }else{
                a = 1, b = 0;
                if(i==n+1){
                    anss[++tops] = 1;
                }else{
                    anss[++tops] = i;
                }
                continue;
            }
        }
    }
    for (int i = tops; i >= 1;i--){
        cout << anss[i] <<' ';
    }
}

int main(){
    freopen("las.in", "r", stdin);
    freopen("las.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> c[i];
    }
    dp[1][0][0] = ((c[1] >= 2 * c[2]) || (c[1] >= c[2]));
    dp[1][0][1] = ((2 * c[1] >= c[2]) || (c[1] >= c[2]));
    if(dp[1][0][0] || dp[1][0][1]){
        c[n + 1] = c[1];
        c[n + 2] = c[2];
        for (int i = 2; i <= n + 1;i++){
            dp[i][0][0] = ((dp[i - 1][1][1] && c[i] >= 2 * c[i + 1]) || (dp[i - 1][0][1] && c[i] >= c[i + 1]));
            dp[i][0][1] = ((dp[i - 1][0][1] && 2 * c[i] >= c[i + 1]) || (dp[i - 1][1][1] && c[i] >= c[i + 1]));
            dp[i][1][0] = ((dp[i - 1][1][0] && 2 * c[i + 1] >= c[i]) || (dp[i - 1][0][0] && c[i + 1] >= c[i]));
            dp[i][1][1] = ((dp[i - 1][0][0] && c[i + 1] >= 2 * c[i]) || (dp[i - 1][1][0] && c[i + 1] >= c[i]));
        }
        if(dp[n+1][0][0] && dp[1][0][0]){
            out_anss(0, 0);
            return 0;
        }
        if(dp[n+1][0][1] && dp[1][0][1]){
            out_anss(0, 1);
            return 0;
        }
    }
    dp[1][0][0] = dp[1][0][1] = false;
    dp[1][1][0] = ((2 * c[2] >= c[1]) || (c[2] >= c[1]));
    dp[1][1][1] = ((c[2] >= 2 * c[1]) || (c[2] >= c[1]));
    if(dp[1][1][0] || dp[1][1][1]){
        c[n + 1] = c[1];
        c[n + 2] = c[2];
        for (int i = 2; i <= n + 1;i++){
            dp[i][0][0] = ((dp[i - 1][1][1] && c[i] >= 2 * c[i + 1]) || (dp[i - 1][0][1] && c[i] >= c[i + 1]));
            dp[i][0][1] = ((dp[i - 1][0][1] && 2 * c[i] >= c[i + 1]) || (dp[i - 1][1][1] && c[i] >= c[i + 1]));
            dp[i][1][0] = ((dp[i - 1][1][0] && 2 * c[i + 1] >= c[i]) || (dp[i - 1][0][0] && c[i + 1] >= c[i]));
            dp[i][1][1] = ((dp[i - 1][0][0] && c[i + 1] >= 2 * c[i]) || (dp[i - 1][1][0] && c[i + 1] >= c[i]));
        }
        if(dp[n+1][1][0] && dp[1][1][0]){
            out_anss(1, 0);
            return 0;
        }
        if(dp[n+1][1][1] && dp[1][1][1]){
            out_anss(1, 1);
            return 0;
        }
    }
    cout << "NIE";
    return 0;
}