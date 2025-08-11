#include <bits/stdc++.h>
using namespace std;

using ll = long long;
vector<int> a[500005];
ll w[500005];
ll sum[500005], cnt[500005];
struct s {
    ll sum, cnt;
}son[500005];
ll scnt;

void DP(int u) {
    cnt[u] = 1, sum[u] = w[u];
    ll begins = scnt + 1;
    for (auto v : a[u]) {
        DP(v);
        scnt++;
        son[scnt].cnt = cnt[v];
        son[scnt].sum = sum[v];
    }
    sort(son + begins, son + scnt + 1, [](s a, s b) {
        return (a.sum / (1.0 * a.cnt)) > (b.sum / (1.0 * b.cnt));
        });
    for (int i = begins;i <= scnt;i++) {
        ll ncnt = cnt[u] + son[i].cnt;
        ll nsum = sum[u] + son[i].sum;
        if ((nsum / (1.0 * ncnt)) > (sum[u] / (1.0 * cnt[u]))) {
            cnt[u] = ncnt;
            sum[u] = nsum;
        } else {
            break;
        }
    }
    scnt = begins - 1;
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 2;i <= n;i++) {
        int f;
        cin >> f;
        a[f].emplace_back(i);
    }
    for (int i = 1;i <= n;i++) {
        cin >> w[i];
    }
    DP(1);
    for (int i = 1;i <= n;i++) {
        printf("%.9lf\n", (sum[i] / (1.0 * cnt[i])));
    }
}