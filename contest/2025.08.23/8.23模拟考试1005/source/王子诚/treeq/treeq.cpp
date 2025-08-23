#include <bits/stdc++.h>
using namespace std;

using ll = long long;
struct s {
    ll v, idx;
};
vector<s> a[10005];
ll r[10005][10005];
ll w[10005], f[10005];

ll its_node, max_r;

ll get_ans(int u, int f) {
    int sums = 1;
    for (auto its : a[u]) {
        int v = its.v, idx = its.idx;
        if (v == f) {
            continue;
        }
        int cnt = get_ans(v, u);
        r[its_node][idx] = cnt * w[idx];
        sums += cnt;
        max_r = max(max_r, r[its_node][idx]);
    }
    return sums;
}

int main() {
    freopen("treeq.in", "r", stdin);
    freopen("treeq.out", "w", stdout);
    ll n;
    cin >> n;
    for (int i = 1;i < n;i++) {
        ll f, W;
        cin >> f >> W;
        a[f].push_back({ i + 1,i });
        a[i + 1].push_back({ f,i });
        w[i] = W;
    }
    for (int i = 1;i <= n;i++) {
        its_node = i, max_r = 0;
        get_ans(i, 0);
        for (int j = 1;j < n;j++) {
            if (r[i][j] == max_r) {
                f[j]++;
            }
        }
    }
    int sums = 0;
    for (int i = 1;i < n;i++) {
        sums ^= f[i];
    }
    cout << sums;
    return 0;
}
