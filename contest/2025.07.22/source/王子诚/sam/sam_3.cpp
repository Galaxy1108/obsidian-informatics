#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
using ll = long long;

ll dp[1000005][10];
ll dig_a[1000005], dig_b[1000005], a_cnt, b_cnt;

int main(){
    for (ll i = 1; i <= 1000005;i++){
        for (ll num = 0; num <= 9;num++){
            if(i==1){
                dp[i][num] = 1;
                continue;
            }
            for (ll last_num = max(0ll, num - 2); last_num <= min(9ll, num+2); last_num++){
                dp[i][num] = (dp[i][num] + dp[i - 1][last_num]) % mod;
            }
        }
    }
    ll k;
    cin >> k;
    a_cnt = 0, b_cnt = 0;
    for (int i = 1; i < k;i++){
        dig_a[++a_cnt] = 0;
        dig_b[++b_cnt] = 0;
    }
    dig_a[++a_cnt] = 1, dig_b[++b_cnt] = 0;
    dig_b[++b_cnt] = 1;
    ll anss1 = 0;
    ll anss2 = 0;
    for (ll i = b_cnt; i >= max(1ll,a_cnt);i--){
        for (ll num = (i == b_cnt);num < dig_b[i];num++){
            if(i!=b_cnt && abs(num-dig_b[i+1])>2){
                continue;
            }
            cout << "hhh";
            anss2 = (anss2 + dp[i][num]) % mod;
        }
        if(i==b_cnt){
            continue;
        }
        for (ll num = 1; num <= 9;num++){
            anss2 = (anss2 + dp[i][num]) % mod;
        }
    }
    cout << (anss2 - 0 + mod) % mod << '\n';
    return 0;
}