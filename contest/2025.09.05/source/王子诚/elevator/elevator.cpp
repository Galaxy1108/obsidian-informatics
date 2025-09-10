#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[2005], b[2005];
struct s {
    ll a, p, i, c;
    ll p1, p2, p3, p4;
};
queue<s> q;
bool vis[10][5][16][16][16][16][16];

int main() {
    freopen("elevator.in", "r", stdin);
    freopen("elevator.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
    }
    q.push({ 1,1,0,0,0,0,0,0 });
    vis[1][1][0][0][0][0][0] = true;
    while (!q.empty()) {
        s u = q.front();
        q.pop();
        if (u.a != 9 && !vis[u.a + 1][u.p][u.i][u.p1][u.p2][u.p3][u.p4]) {
            q.push({ u.a + 1,u.p,u.i,u.c + 1,u.p1,u.p2,u.p3,u.p4 });
            vis[u.a + 1][u.p][u.i][u.p1][u.p2][u.p3][u.p4] = true;
        }
        if (u.a != 1 && !vis[u.a - 1][u.p][u.i][u.p1][u.p2][u.p3][u.p4]) {
            q.push({ u.a - 1,u.p,u.i,u.c + 1,u.p1,u.p2,u.p3,u.p4 });
            vis[u.a - 1][u.p][u.i][u.p1][u.p2][u.p3][u.p4] = true;
        }
        int lp[4];
        lp[0] = lp[1] = lp[2] = lp[3] = 0;
        if (b[u.p1] != u.a && u.p1 != 0) {
            lp[0] = u.p2, lp[1] = u.p3, lp[2] = u.p4;
            if (!vis[u.a][u.p][u.i - 1][lp[0]][lp[1]][lp[2]][lp[3]]) {
                if (u.i - 1 == 0 && u.p == n + 1) {
                    cout << u.c + 3;
                    return 0;
                }
                q.push({ u.a,u.p,u.i - 1,u.c + 1,lp[0],lp[1],lp[2],lp[3] });
                vis[u.a][u.p][u.i - 1][lp[0]][lp[1]][lp[2]][lp[3]] = true;
            }
            continue;
        }
        if (b[u.p2] != u.a && u.p2 != 0) {
            lp[0] = u.p1, lp[1] = u.p3, lp[2] = u.p4;
            if (!vis[u.a][u.p][u.i - 1][lp[0]][lp[1]][lp[2]][lp[3]]) {
                if (u.i - 1 == 0 && u.p == n + 1) {
                    cout << u.c + 3;
                    return 0;
                }
                q.push({ u.a,u.p,u.i - 1,u.c + 1,lp[0],lp[1],lp[2],lp[3] });
                vis[u.a][u.p][u.i - 1][lp[0]][lp[1]][lp[2]][lp[3]] = true;
            }
            continue;
        }
        if (b[u.p3] != u.a && u.p3 != 0) {
            lp[0] = u.p1, lp[1] = u.p2, lp[2] = u.p4;
            if (!vis[u.a][u.p][u.i - 1][lp[0]][lp[1]][lp[2]][lp[3]]) {
                if (u.i - 1 == 0 && u.p == n + 1) {
                    cout << u.c + 3;
                    return 0;
                }
                q.push({ u.a,u.p,u.i - 1,u.c + 1,lp[0],lp[1],lp[2],lp[3] });
                vis[u.a][u.p][u.i - 1][lp[0]][lp[1]][lp[2]][lp[3]] = true;
            }
            continue;
        }
        if (b[u.p4] != u.a && u.p4 != 0) {
            lp[0] = u.p1, lp[1] = u.p2, lp[2] = u.p3;
            if (!vis[u.a][u.p][u.i - 1][lp[0]][lp[1]][lp[2]][lp[3]]) {
                if (u.i - 1 == 0 && u.p == n + 1) {
                    cout << u.c + 3;
                    return 0;
                }
                q.push({ u.a,u.p,u.i - 1,u.c + 1,lp[0],lp[1],lp[2],lp[3] });
                vis[u.a][u.p][u.i - 1][lp[0]][lp[1]][lp[2]][lp[3]] = true;
            }
            continue;
        }
        if (u.a == a[u.p] && u.p <= n) {
            lp[u.i] = u.p;
            if (!vis[u.a][u.p + 1][u.i + 1][lp[0]][lp[1]][lp[2]][lp[3]]) {
                q.push({ u.a,u.p + 1,u.i + 1,u.c + 1,lp[0],lp[1],lp[2],lp[3] });
                vis[u.a][u.p + 1][u.i + 1][lp[0]][lp[1]][lp[2]][lp[3]] = true;
            }
        }
    }
}