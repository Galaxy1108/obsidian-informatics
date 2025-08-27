#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> a[300005];
int l[25][25];

int q[2000000], top, beg;
bool r[2000000];

ll f[50005];

#define mod 998244353

ll fast_pow(ll a, ll b) {
    ll anss = 1;
    while (b) {
        if (b & 1) {
            anss = (anss * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return anss;
}

ll c(ll n, ll m) {
    return f[n] * fast_pow((f[m] * f[n - m]) % mod, mod - 2) % mod;
}

int s;
void dfs(int cnt, int u, int f) {
    for (auto v : a[u]) {
        if (v == f) {
            continue;
        }
        l[s][v] = cnt + 1;
        dfs(cnt + 1, v, u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("youup.in", "r", stdin);
    freopen("youup.out", "w", stdout);
    int num;
    cin >> num;
    int n, x;
    cin >> n >> x;
    for (int i = 1;i < n;i++) {
        int x, y;
        cin >> x >> y;
        a[x].emplace_back(y);
        a[y].emplace_back(x);
    }
    if (x == 0) {
        cout << n << ' ';
        for (int i = 2;i <= n;i++) {
            cout << 0 << ' ';
        }
        return 0;
    }
    if (num == 4) {
        cout << n << ' ';
        if (x == 1) {
            cout << n - 1 << ' ';
            for (int i = 3;i <= n;i++) {
                cout << 0 << ' ';
            }
            return 0;
        }
        f[0] = 1;
        for (int i = 1;i <= n;i++) {
            f[i] = (i * f[i - 1]) % mod;
        }
        for (int i = 2;i <= n;i++) {
            cout << c(n, i) << ' ';
        }
        return 0;
    }
    if (num == 5) {
        cout << n << ' ';
        for (int i = 2;i <= min(x + 1, n);i++) {
            cout << n - i + 1 << ' ';
        }
        for (int i = min(x + 1, n) + 1;i <= n;i++) {
            cout << 0 << ' ';
        }
        return 0;
    }
    beg = 1;
    for (int i = 1;i <= n;i++) {
        l[i][i] = 0;
        s = i;
        dfs(0, i, 0);
        q[++top] = (1 << i);
        r[(1 << i)] = true;
    }
    cout << n << ' ';
    for (int i = 2;i <= n;i++) {
        int cnts = 0;
        while (__builtin_popcount(q[beg]) == i - 1 && top >= beg) {
            for (int j = 1;j <= n;j++) {
                if ((q[beg] & (1 << j)) || (r[q[beg] | (1 << j)])) {
                    continue;
                }
                bool flag = true;
                for (int k = 1;k <= n && flag;k++) {
                    if ((q[beg] & (1 << k)) && l[j][k] > x) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cnts++;
                    q[++top] = (q[beg] | (1 << j));
                    r[q[beg] | (1 << j)] = true;
                }
            }
            beg++;
        }
        cout << cnts << ' ';
    }
    return 0;
}