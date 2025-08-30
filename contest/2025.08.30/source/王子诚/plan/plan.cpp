/*
最大公约数之和？
长得像树状 DP，但是还是太过于诡异了

*/
#include <bits/stdc++.h>
using namespace std;

struct s {
    int num, idx;
};
vector<s> a[505];
int w[505];

bool vis[505];

int calc(int u, int f, int& s) {
    int sizes = a[u].size();
    vis[u] = true;
    int gcds = w[u];
    for (int i = 0;i < sizes;i++) {
        if (s & (1 << (a[u][i].idx - 1)) || a[u][i].num == f) {
            continue;
        }
        gcds = __gcd(gcds, calc(a[u][i].num, u, s));
    }
    return gcds;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("plan.in", "r", stdin);
    freopen("plan.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 1;i < n;i++) {
        int x, y;
        cin >> x >> y;
        a[x].emplace_back((s) { y, i });
        a[y].emplace_back((s) { x, i });
    }
    for (int i = 1;i <= n;i++) {
        cin >> w[i];
    }
    int anss = 0;
    for (int i = 0;i < (1 << n);i++) {
        if (__builtin_popcount(i) != k) {
            continue;
        }
        for (int j = 1;j <= n;j++) {
            vis[j] = false;
        }
        int res = 0;
        for (int j = 1;j <= n;j++) {
            if (vis[j]) {
                continue;
            }
            res += calc(j, 0, i);
        }
        anss = max(anss, res);
    }
    cout << anss << '\n';
}
