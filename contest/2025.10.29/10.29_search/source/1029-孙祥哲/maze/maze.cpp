#include <bits/stdc++.h>
using namespace std;

int n, m, x, y;
int a[45][45], dis[2][45][45], vis[45][45], cnt[2][45][45];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs(int sx, int sy, int p)
{
    if (a[sx][sy]) return;
    queue<pair<int,int> > q;
    dis[p][sx][sy] = 0, vis[sx][sy] = 1, cnt[p][sx][sy] = 1;
    q.push({sx, sy});
    while (!q.empty())
    {
        int xx = q.front().first, yy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int tx = xx + dx[i], ty = yy + dy[i];
            if (a[tx][ty] || tx<1 || ty<1 || tx>n || ty>m) continue;
            cnt[p][tx][ty] += cnt[p][xx][yy];
            if (vis[tx][ty]) continue;
            q.push({tx, ty});
            vis[tx][ty] = 1, dis[p][tx][ty] = dis[p][xx][yy] + 1;
        }
    }
}

int main()
{
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    memset(dis, 0x3f, sizeof(dis));
    bfs(1, 1, 0), bfs(x, y, 1);
    cout << cnt[0][x][y];
    return 0;
}