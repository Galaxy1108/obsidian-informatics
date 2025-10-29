#include<bits/stdc++.h>
#define pii pair<int, int>
#define mkp make_pair

using namespace std;

const int N = 101;

int mapn[N][N];
int n, m, x, y;
int vis[N * N];
int del[5][2] = {{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int flag = 0, kk = 0;
int total = 0;

void bfs() {
    queue<pii> q;
    q.push(mkp(1, 0));
    vis[1] = 1;
    while(!q.empty()) {
        int nown = q.front().first, nowb = q.front().second;
        q.pop();
        if(flag && nowb > kk) return;
        if(flag == 0 && nown == ((x - 1) * m + y)) {
            flag = 1;
            kk = nowb;
            total = 1;
        }
        else if(nown == (x - 1) * m + y) total++;
        int nx = (nown - 1) / m + 1, ny = (nown - 1) % m + 1; 
        for(int i = 1; i <= 4; i++) {
            if(nx == 1 && i == 2) continue;
            if(nx == n && i == 1) continue;
            if(ny == 1 && i == 4) continue;
            if(ny == m && i == 3) continue;
            int nt = (nown + del[i][0] * m + del[i][1]), nnx = nx + del[i][0], nny = ny + del[i][1];
            if(mapn[nnx][nny]) continue;
            if(vis[nt] && vis[nt] < nowb + 1) continue;
            vis[nt] = nowb + 1;
            q.push(mkp(nt, nowb + 1));
        }
    }
    return;
}

int main() {
    freopen("maze.in", "r", stdin);
    freopen("maze.out", "w", stdout);
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> mapn[i][j];
    }
    bfs();
    cout << total << endl;
    return 0;
}