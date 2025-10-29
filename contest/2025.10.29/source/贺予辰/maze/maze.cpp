#include<bits/stdc++.h>
using namespace std;
struct pnt {
    int x, y, stp;
};
queue<pnt> q;
bool g[15][15];
int stp[15][15], n, m, x, y, cnt = 0, fff;
bool work(pnt p) {
    if (p.x < 1 || p.x > n ||
    p.y < 1 || p.y > m) return 0;
    if (g[p.x][p.y]) return 0;
    if (p.x == x && p.y == y) {
        if (p.stp < stp[x][y]) {
            cnt = 1, stp[x][y] = p.stp;
            return 1;
        }
        if (p.stp == stp[x][y])
            ++cnt;
        return 0;
    }
    if (p.stp < stp[p.x][p.y]) {
        stp[p.x][p.y] = p.stp;
        return 1;
    }
    return 0;
}
int BFS() {
    memset(stp, 0x3f, sizeof(stp));
    q.push((pnt){1, 1, 0});
    while (!q.empty()) {
        pnt tmp = q.front(), k = tmp;
        q.pop(); ++k.x, ++k.stp;
        if (work(k)) q.push(k);
        k = tmp, --k.x, ++k.stp;
        if (work(k)) q.push(k);
        k = tmp, --k.y, ++k.stp;
        if (work(k)) q.push(k);
        k = tmp, ++k.y, ++k.stp;
        if (work(k)) q.push(k);
    }
    return cnt;
}
int main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(g, 0, sizeof(g));
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> fff, g[i][j] = fff;
    cout << BFS() << '\n';
    return 0;
}