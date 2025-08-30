#include<bits/stdc++.h>

using namespace std;

struct qj {
    int l, r;
};

int n, m;
int tot = 0;
int vis[21];
qj a[10001];
int fz[10001];
int ans = 0;

bool chk(int x) {
    for(int i = 1; i <= n; i++) vis[i] = 1;
    int cnt = 0;
    for(int i = 1; i <= m; i++) {
        int tmp = (a[fz[i]].l <= x && a[fz[i]].r >= x);
        if(tmp == 1) {
            for(int j = 1; j < a[fz[i]].l; j++) vis[j] = 0;
            for(int j = a[fz[i]].r + 1; j <= n; j++) vis[j] = 0;
        }
        if(tmp == 0) for(int j = a[fz[i]].l; j <= a[fz[i]].r; j++) vis[j] = tmp;
    }
    for(int i = 1; i <= n; i++) if(vis[i]) cnt++;
    // cout << cnt << endl;
    return (cnt == 1);
}

void dfs(int nown, int lastn) {
    if(nown == m + 1) {
        // for(int i = 1; i <= m; i++) cout << a[fz[i]].l << " " << a[fz[i]].r << endl;
        for(int i = 1; i <= n; i++) if(!chk(i)) return;
        ans++;
        return;
    }
    for(int i = lastn + 1; i <= tot; i++) {
        fz[nown] = i;
        dfs(nown + 1, i);
        fz[nown] = 0; 
    }
    return;
}

int main() {
    freopen("oracle.in", "r", stdin);
    freopen("oracle.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) a[++tot].l = i, a[tot].r = j;
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}