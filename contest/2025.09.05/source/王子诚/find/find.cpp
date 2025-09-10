#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mod 1000000007

unordered_map<ll, ll> ni;
ll in[20005];
ll dp[20][20005][2], c[200005], n_num[20];
ll n_tops, tops, anss;

struct s{
    ll first, second;
    friend bool operator<(s a, s b){
        return c[a.first] * c[a.second] < c[b.first] * c[b.second];
    }
};

priority_queue<s> p;


int main() {
    freopen("find.in", "r", stdin);
    freopen("find.out", "w", stdout);
    ll n, k;
    cin >> n >> k;
    ll this_num = 1;
    for (ll num_2 = 1;num_2 <= n;num_2 *= 2) {
        for (ll num_3 = 1;num_2 * num_3 <= n;num_3 *= 3) {
            for (ll num_5 = 1;num_2 * num_3 * num_5 <= n;num_5 *= 5) {
                for (ll num_7 = 1;num_2 * num_3 * num_5 * num_7 <= n;num_7 *= 7) {
                    this_num = num_2 * num_3 * num_5 * num_7;
                    in[++tops] = this_num;
                }
            }
        }
    }
    while (n) {
        n_num[++n_tops] = n % 10;
        n /= 10;
    }
    k = min(k, tops * tops);
    sort(in + 1, in + 1 + tops);
    for (int i = 1;i <= tops;i++) {
        ni[in[i]] = i;
    }
    for (int dig = 1;dig <= 9;dig++) {
        dp[1][ni[dig]][dig > n_num[1]] = 1;
    }
    for (int i = 2;i <= n_tops;i++) {
        for (int j = 1;j <= tops;j++) {
            for (int dig = 1;dig <= 9;dig++) {
                if (in[j] % dig) {
                    continue;
                }
                ll last_idx = ni[in[j] / dig];
                if (dig < n_num[i]) {
                    dp[i][j][0] += dp[i - 1][last_idx][0] + dp[i - 1][last_idx][1];
                    continue;
                }
                if (dig > n_num[i]) {
                    dp[i][j][1] += dp[i - 1][last_idx][0] + dp[i - 1][last_idx][1];
                    continue;
                }
                dp[i][j][0] += dp[i - 1][last_idx][0];
                dp[i][j][1] += dp[i - 1][last_idx][1];
            }
        }
    }
    for (int i = 1;i <= n_tops;i++) {
        for (int j = 1;j <= tops;j++) {
            c[j] += dp[i][j][0] + (i != n_tops) * dp[i][j][1];
        }
    }
    sort(c + 1, c + 1 + tops);
    for (int i = 1;i <= tops;i++) {
        p.push({ i,tops });
    }
    for (int i = 1;i <= k;i++) {
        auto u = p.top();
        p.pop();
        anss = (anss + c[u.first] * c[u.second] % mod) % mod;
        if (u.second != 1){
            p.push({ u.first,u.second - 1 });
        }
    }
    cout << anss;
    return 0;
}