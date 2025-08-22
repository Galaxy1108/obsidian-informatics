#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2020;

struct Node {LL mi, id;} a[N];

int n;
LL g[N][N], mi = 1e18, dis[N], ans[N];

bool cmp(Node x, Node y) {
    return x.mi < y.mi;
}

int main() {
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    // freopen("b3.in", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) 
            scanf("%lld", &g[i][j]), mi = min(mi, g[i][j]);
    for (int i = 1; i <= n; i++) {
        g[i][i] = 1e18;
        for (int j = 1; j <= i - 1; j++)
            g[i][j] = g[j][i];
    }
    for (int i = 1; i <= n; i++) {
        a[i].mi = 1e18; a[i].id = i;
        for (int j = 1; j <= n; j++)
            a[i].mi = min(a[i].mi, g[i][j]);
    }
    sort(a + 1, a + n + 1, cmp);
    memset(ans, -245, sizeof(ans));
    memset(dis, -245, sizeof(dis));
    ans[a[n].id] = 0;
    for (int i = n; i >= 2; i--) {
        ans[a[n].id] += g[a[i].id][a[i - 1].id];
    }
    // cout << "mi = " << mi << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            dis[i] = min(dis[i], dis[j] + g[a[i].id][a[j].id] - mi);
        }
        dis[i] = min(dis[i], 2 * a[i].mi);
        // cout << "i = " << i << " id = " << a[i].id << " dis = " << dis[i] << endl;
    }
    for (int i = 1; i <= n; i++) {
        ans[a[i].id] = min(ans[a[i].id], dis[i] + (n - 3) * mi);
    }
    for (int i = 1; i <= n; i++)
        printf("%lld\n", ans[i]);
    return 0;
}
/*
3
1 2
3
*/