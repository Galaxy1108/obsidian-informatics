#include <bits/stdc++.h>
using namespace std;

vector<int> p[120005];
unordered_set<int> p2[120005];
queue<int> q;
int fat[120005][20];
int s[120005], t[120005];
int ns[120005], nt[120005];
int dep[120005];
int in[120005];

void build(int idx, int fa) {
    dep[idx] = dep[fa] + 1;
    fat[idx][0] = fa;
    for (int i = 1;i < 20;i++) {
        fat[idx][i] = fat[fat[idx][i - 1]][i - 1];
    }
    for (auto v : p[idx]) {
        if (v == fa) {
            continue;
        }
        build(v, idx);
    }
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) {
        swap(a, b);
    }
    int depab = dep[a] - dep[b];
    for (int i = 0;i < 20;i++) {
        if (depab & (1 << i)) {
            a = fat[a][i];
        }
    }
    if (a == b) {
        return a;
    }
    for (int i = 19;i >= 0;i--) {
        if (fat[a][i] != fat[b][i]) {
            a = fat[a][i];
            b = fat[b][i];
        }
    }
    return fat[a][0];
}

int main(){
    freopen("jail.in", "r", stdin);
    freopen("jail.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for (int i = 1;i <= n;i++) {
            p[i].clear();
            p2[i].clear();
            s[i] = t[i] = 0;
            in[i] = 0;
        }
        for (int i = 1; i < n;i++) {
            int a, b;
            cin >> a >> b;
            p[a].emplace_back(b);
            p[b].emplace_back(a);
        }
        build(1, 0);
        int m;
        cin >> m;
        for (int i = 1;i <= m;i++) {
            cin >> ns[i] >> nt[i];
            s[ns[i]] = i, t[nt[i]] = i;
        }
        for (int i = 1;i <= m;i++) {
            int l = lca(ns[i], nt[i]);
            int its = ns[i];
            while (its != l) {
                if (s[its] && s[its] != i) {
                    if (!p2[s[its]].count(i)) {
                        in[i]++;
                    }
                    p2[s[its]].insert(i);
                }
                if (t[its] && t[its] != i) {
                    if (!p2[i].count(t[its])) {
                        in[t[its]]++;
                    }
                    p2[i].insert(t[its]);
                }
                its = fat[its][0];
            }
            its = nt[i];
            while (its != l) {
                if (s[its] && s[its]!=i) {
                    if (!p2[s[its]].count(i)) {
                        in[i]++;
                    }
                    p2[s[its]].insert(i);
                }
                if (t[its] && t[its] != i) {
                    if (!p2[i].count(t[its])) {
                        in[t[its]]++;
                    }
                    p2[i].insert(t[its]);
                }
                its = fat[its][0];
            }
            if (s[l] && s[l] != i) {
                if (!p2[s[l]].count(i)) {
                    in[i]++;
                }
                p2[s[l]].insert(i);
            }
            if (t[l] && t[l]!=i) {
                if (!p2[i].count(t[l])) {
                    in[t[l]]++;
                }
                p2[i].insert(t[l]);
            }
        }
        int cnts = m;
        for (int i = 1;i <= m;i++) {
            if (!in[i]) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cnts--;
            for (auto v : p2[u]) {
                in[v]--;
                if (!in[v]) {
                    q.push(v);
                }
            }
        }
        cout << (cnts ? "No\n" : "Yes\n");
    }
}