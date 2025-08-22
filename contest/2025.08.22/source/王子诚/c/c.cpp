#include <bits/stdc++.h>
using namespace std;

int dp[20][185540];
int a[20][20];

void gen(int n, int seed) {
    std::mt19937 rng(seed);
    for (int i = 1;i <= n;++i) {
        for (int j = 1;j <= n + 1;++j) {
            a[i][j] = j;
            std::swap(a[i][j], a[i][rng() % j + 1]);
        }
    }
}


int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    int n, seed;
    cin >> n >> seed;
    int p = n;
    n = n + 1;
    if (seed == 0) {
        for (int i = 1;i <= p;i++) {
            for (int j = 1;j <= n;j++) {
                cin >> a[i][j];
            }
        }
    } else {
        gen(n, seed);
    }
    for (int s = 1;s <= p;s++) {
        for (int j = 0;j < n;j++) {
            dp[p + 1][(1 << j)] = j + 1;
        }
        for (int k = p;k >= 1;k--) {
            int kp = ((s + k - 2) % p) + 1;
            for (int r = 1;r < (1 << n);r++) {
                if (__builtin_popcount(r) != n - k + 1) {
                    continue;
                }
                int res = INT_MAX, sre = -1;
                for (int t = 0;t < n;t++) {
                    if (r & (1 << t)) {
                        if (sre == -1 || a[kp][dp[k + 1][r - (1 << t)]] > sre) {
                            res = dp[k + 1][r - (1 << t)];
                            sre = a[kp][dp[k + 1][r - (1 << t)]];
                        }
                    }
                }
                dp[k][r] = res;
            }
        }
        cout << dp[1][(1 << n) - 1] << ' ';
    }
}