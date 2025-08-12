#include <bits/stdc++.h>
using namespace std;

vector<int> a[100];
vector<int> anss[100];
int is_can[100][100];
int cntt[100][100];

int a1, a2, k, id;
bool dfs(int u, int cnt) {
    if (u == a2) {
        if (cnt == k) {
            return true;
        }
        if (dfs(a1, cnt + 1)) {
            return true;
        } else {
            return false;
        }
    }
    anss[cnt].emplace_back(u);
    for (int i = 0;i < a[u].size();i++) {
        int v = a[u][i];
        if (is_can[u][v] == cntt[u][v]) {
            continue;
        }
        is_can[v][u]++;
        is_can[u][v]++;
        if (dfs(v, cnt)) {
            is_can[v][u]--;
            is_can[u][v]--;
            return true;
        }
        is_can[v][u]--;
        is_can[u][v]--;
    }
    anss[cnt].pop_back();
    return false;
}

int main() {
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        id = 0;
        for (int i = 1;i <= n;i++) {
            a[i].clear();
            anss[i].clear();
        }
        for (int i = 0;i <= n;i++) {
            for (int j = 0;j <= n;j++) {
                is_can[i][j] = 0;
                cntt[i][j] = 0;
            }
        }
        for (int i = 1;i <= m;i++) {
            int u, v;
            cin >> u >> v;
            a[u].emplace_back(v);
            a[v].emplace_back(u);
            cntt[u][v]++;
            cntt[v][u]++;
        }
        k = (m / (n - 1) + (m % (n - 1)));
        bool flag = true;
        for (int i = 1;i <= n && flag;i++) {
            for (int j = i + 1;j <= n;j++) {
                a1 = i, a2 = j;
                id++;
                if (dfs(a1, 1)) {
                    cout << i << ' ' << j << '\n';
                    for (int l = 1;l <= k;l++) {
                        cout << anss[l].size() + 1 << ' ';
                        for (auto its : anss[l]) {
                            cout << its << ' ';
                        }
                        cout << j << '\n';
                    }
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            cout << -1 << '\n';
        }
    }
}