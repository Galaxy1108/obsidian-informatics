#include <bits/stdc++.h>
using namespace std;

struct s {
    int v, idx;
};

struct e {
    int u, v;
};

vector<s> a[15];
e aes[35];
e bes[55];
bool vis[35][35];
bool vis2[35];

int main() {
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if (n > 10 || m > 30) {
        cout << m / 2;
        return 0;
    }
    for (int i = 1;i <= m;i++) {
        int u, v;
        cin >> u >> v;
        a[u].emplace_back((s){ v,i });
        a[v].emplace_back((s) { u, i });
        aes[i] = { u,v };
    }
    int cnts = 0;
    for (int i = 1;i <= m;i++) {
        for (auto its : a[aes[i].u]) {
            if (its.idx == i || vis[its.idx][i] || vis[i][its.idx]) {
                continue;
            }
            bes[++cnts] = { i,its.idx };
            vis[i][its.idx] = true;
        }
        for (auto its : a[aes[i].v]) {
            if (its.idx == i || vis[its.idx][i] || vis[i][its.idx]) {
                continue;
            }
            bes[++cnts] = { i,its.idx };
            vis[i][its.idx] = true;
        }
        if (cnts > 22) {
            cout << m / 2;
            return 0;
        }
    }
    int anss = 0;
    for (int i = 0;i < (1 << cnts);i++) {
        int res = __builtin_popcount(i);
        if (res <= anss) {
            continue;
        }
        for (int j = 1;j <= m;j++) {
            vis2[j] = false;
        }
        bool flag = true;
        for (int j = 1;j <= cnts;j++) {
            if (!(i & (1 << (j - 1)))) {
                continue;
            }
            if (vis2[bes[j].u] || vis2[bes[j].v]) {
                flag = false;
                break;
            }
            vis2[bes[j].u] = true;
            vis2[bes[j].v] = true;
        }
        if (flag) {
            anss = res;
        }
    }
    cout << anss;
}