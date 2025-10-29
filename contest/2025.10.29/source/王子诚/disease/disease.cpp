#include <bits/stdc++.h>
using namespace std;

vector<int> sn[305];
queue<int> que;

int top, sns[305], thisc;
int c[305];
bool vis[305];

int main() {
    freopen("disease.in", "r", stdin);
    freopen("disease.out", "w", stdout);
    int n, ty;
    cin >> n >> ty;
    srand(time(0));
    for (int i = 0;i < n - 1;i++) {
        int u, v;
        cin >> u >> v;
        sn[u].push_back(v);
        sn[v].push_back(u);
    }
    long long anss = INT_MAX;
    for (int i = 0;i < 500000;i++) {
        memset(vis, 0, sizeof(vis));
        c[1] = 1;
        que.push(1);
        long long ere, ans = 0;
        thisc = 1;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (c[v] != thisc) {
                ere = rand() % top;
                ere = sns[ere];
                top = 0;
                thisc = c[v];
            }
            if (v == ere) {
                continue;
            }
            for (int i = 0;i < sn[v].size();i++) {
                if (vis[sn[v][i]]) {
                    continue;
                }
                vis[sn[v][i]] = true;
                c[sn[v][i]] = c[v] + 1;
                sns[top++] = sn[v][i];
                que.push(sn[v][i]);
            }
            vis[v] = true;
            ans++;
            if (ans > anss) {
                ans = INT_MAX;
                top = 0;
                while (!que.empty()) {
                    que.pop();
                }
                break;
            }
        }
        anss = min(anss, ans);
    }
    cout << anss;
    return 0;
}



