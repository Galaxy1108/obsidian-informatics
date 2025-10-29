#include <bits/stdc++.h>
using namespace std;

int dis[15][15];
int cnts[15][15][15 * 15];
bool b[15][15];

int n, m, tx, ty;

bool check(int x, int y) {
    return (x >= 1 && y >= 1 && x <= n && y <= m && !b[x][y]);
}

void dfs(int x, int y, int w) {
    if (dis[x][y] < w) {
        return;
    }
    dis[x][y] = w;
    cnts[x][y][dis[x][y]]++;
    if (check(x + 1, y)) dfs(x + 1, y, w + 1);
    if (check(x - 1, y)) dfs(x - 1, y, w + 1);
    if (check(x, y + 1)) dfs(x, y + 1, w + 1);
    if (check(x, y - 1)) dfs(x, y - 1, w + 1);
}

int main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    cin >> n >> m >> tx >> ty;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cin >> b[i][j];
            dis[i][j] = INT_MAX;
        }
    }
    dfs(1, 1, 0);
    cout << cnts[tx][ty][dis[tx][ty]];
}
