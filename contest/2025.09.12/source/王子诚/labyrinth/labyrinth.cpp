/*
Try
找到最浅树根
对于子树来说，依然需要...吗？
*/

#include <bits/stdc++.h>
using namespace std;

int dep_nf[200005];
int mdep[200005];
vector<int> a[200005];

void dfs1(int u, int f) {
    dep_nf[u] = 1;
    for (auto v : a[u]) {
        if (v == f) {
            continue;
        }
        dfs1(v, u);
        dep_nf[u] = max(dep_nf[u], dep_nf[v] + 1);
    }
}

void dfsm(int u, int f, int fdep) {
    mdep[u] = fdep + 1;
    int maxdep = fdep + 1, lmaxdep = 0;
    for (auto v : a[u]) {
        if (v == f) {
            continue;
        }
        mdep[u] = max(mdep[u], dep_nf[v] + 1);
        if (dep_nf[v] + 1 > maxdep) {
            lmaxdep = maxdep;
            maxdep = dep_nf[v] + 1;
        } else if (dep_nf[v] + 1 > lmaxdep) {
            lmaxdep = dep_nf[v] + 1;
        }
    }
    for (auto v : a[u]) {
        if (v == f) {
            continue;
        }
        if (dep_nf[v] + 1 == maxdep) {
            dfsm(v, u, lmaxdep);
        } else {
            dfsm(v, u, maxdep);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("labyrinth.in", "r", stdin);
    freopen("labyrinth.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            dep_nf[i] = mdep[i] = 0;
            a[i].clear();
        }
        for (int i = 1;i < n;i++) {
            int u, v;
            cin >> u >> v;
            a[u].emplace_back(v);
            a[v].emplace_back(u);
        }
        dfs1(1, 0);
        dfsm(1, 0, 0);
        int mins = INT_MAX;
        for (int i = 1;i <= n;i++) {
            mins = min(mins, mdep[i]);
            // cout << mdep[i] << ' ';
        }
        // cout << '\n';
        mins--;
        int anss;
        for (anss = 1;(1 << anss) - 1 < mins;anss++);
        cout << anss + 1 << '\n';
    }
}
