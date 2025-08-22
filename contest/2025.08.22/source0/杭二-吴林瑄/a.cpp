#include<bits/stdc++.h>
using namespace std;
int n, m, mod;
vector<int> dp[2];
vector<int> pre[2], suf[2], ssuf[2];
void clear(int op){
    for(int i = 0; i <= m + 1; i++){
        pre[op][i] = suf[op][i] = ssuf[op][i] = 0;
        dp[op][i] = 0;
    }
}
void calc(int op){
    for(int i = 1; i <= m; i++){
        pre[op][i] += dp[op][i];
        pre[op][i] %= mod;
        suf[op][i] += dp[op][i];
        suf[op][i] %= mod;
    }
    for(int i = 1; i <= m + 1; i++){
        pre[op][i] = (pre[op][i - 1] + pre[op][i]) % mod;
    }
    for(int i = m; i >= 0; i--){
        suf[op][i] = (suf[op][i] + suf[op][i + 1]) % mod;
        ssuf[op][i] = suf[op][i];
    }
    for(int i = m; i >= 0; i--){
        ssuf[op][i] = (ssuf[op][i] + ssuf[op][i + 1]) % mod;
    }
}
signed main(){
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> n >> m >> mod;
    int ans;
    if(n == 1){
        ans = 1ll * (m + 1) * m / 2 % mod;
    }else{
        dp[0].resize(m + 2);
        dp[1].resize(m + 2);
        pre[0].resize(m + 2);
        pre[1].resize(m + 2);
        suf[0].resize(m + 2);
        suf[1].resize(m + 2);
        ssuf[0].resize(m + 2);
        ssuf[1].resize(m + 2);
        for(int i = 1; i <= m; i++){
            dp[1][i] = m - i + 1;
        }
        calc(1);
        for(int i = 2; i <= n; i++){
            clear(i&1);
            for(int l = 1; l <= m; l++){
                dp[i&1][l] = ((1ll * pre[(i&1)^1][m] * (m - l + 1) % mod - 1ll * suf[(i&1)^1][m - l + 2] * (m - l + 1) % mod + mod) % mod - ssuf[(i&1)^1][l + 1] + mod) % mod;
            }
            calc(i&1);
        }
        ans = pre[n & 1][m];
    }
    cout << ans << endl;
    return 0;
}