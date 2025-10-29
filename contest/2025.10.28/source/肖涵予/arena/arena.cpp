#include <bits/stdc++.h>
#define p(i) (i - 1)
using namespace std;
typedef long long ll;

const int N = 505;
constexpr ll Mod = 998244353;

inline ll qpow(ll base, int power) {
    ll res = 1;
    while (power) {
        if (power & 1) res = res * base % Mod;
        base = base * base % Mod, power >>= 1;
    }
    return res;
}

int n, x;
ll C[N][N], pw[N][N], f[N][N], ans;

void Init() {
    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) C[i][j] = (C[p(i)][p(j)] + C[p(i)][j]) % Mod;
    }
    for (ll base = 0; base <= (ll)n; ++base)
        for (int power = 0; power <= n; ++power)
            pw[base][power] = qpow(base, power);
    return ;
}

int main() {
    freopen("arena.in", "r", stdin), freopen("arena.out", "w", stdout);
    scanf("%d %d", &n, &x);
    Init();
    for (int i = 2; i <= n; ++i)
        for (int mx = 1; mx <= x; ++mx)
            if (mx < i)
                for (int num = 1; num <= i; ++num)
                    f[i][mx] = (f[i][mx] + C[i][num] * pw[p(mx)][i - num] % Mod) % Mod;
            else
                for (int num = 0; num < i; ++num)
                    f[i][mx] = (f[i][mx] + C[i][num] * pw[p(i)][num] % Mod * f[i - num][mx - p(i)]) % Mod;
    for (int mx = 1; mx <= x; ++mx)
        ans = (ans + f[n][mx]) % Mod;
    cout << ans;
    return 0;
}