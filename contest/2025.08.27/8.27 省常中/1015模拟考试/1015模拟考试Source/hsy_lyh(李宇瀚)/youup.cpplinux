#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 3e5 + 5;
const int M = 998244353;

int num;
int n, x;
int head[N], pre[N], ver[N], cnt = 0;
int fz[N];
int dep[N], top[N], hson[N], fa[N], dfn[N], tot = 0;
int siz[N];
int vis[N];
int lim;
int total = 0;

void add_edge(int u, int v) {
    pre[++cnt] = head[u];
    head[u] = cnt;
    ver[cnt] = v;
    return;
}

int fpow(int a, int b) {
    int ans = 1, base = a;
    while(b > 0) {
        if(b & 1) ans = (ans * base) % M;
        base = (base * base) % M;
        b >>= 1;
    }
    return ans;
}

int getInv(int a) {
    return fpow(a, M - 2);
}

void dfs1(int nown, int f) {
    dep[nown] = dep[f] + 1, dfn[nown] = ++tot;
    fa[nown] = f, siz[nown] = 1;
    for(int i = head[nown]; i; i = pre[i]) {
        int v = ver[i];
        if(v == f) continue;
        dfs1(v, nown);
        siz[nown] += siz[v];
    }
    return;
}

void dfs2(int nown, int f) {
    if(nown == hson[f]) top[nown] = top[f];
    else top[nown] = nown;
    int maxn = 0, indx = 0;
    for(int i = head[nown]; i; i = pre[i]) {
        int v = ver[i];
        if(v == f) continue;
        if(siz[v] > maxn) maxn = siz[v], indx = v;
    }
    hson[nown] = indx;
    for(int i = head[nown]; i; i = pre[i]) {
        int v = ver[i];
        if(v == f) continue;
        dfs2(v, nown);
    }
    return;
}

int LCA(int x, int y) {
    while(top[x] != top[y]) {
        if(dep[top[x]] <= dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return (dep[x] <= dep[y] ? x : y);
}

void dfs(int nown, int lastn) {
    if(nown == lim + 1) {
        total++;
        if(total > M) total -= M;
        return;
    }
    for(int i = lastn + 1; i <= n; i++) {
        if(vis[i]) continue;
        bool flag = 0;
        for(int j = 1; j < nown; j++) {
            if(dep[i] + dep[fz[j]] - 2 * dep[LCA(fz[j], i)] > x) {
                flag = 1;
                break;
            }
        }
        if(flag) continue;
        vis[i] = 1;
        fz[nown] = i;
        dfs(nown + 1, i);
        vis[i] = 0;
        fz[nown] = 0;
    }
}

signed main() {
    freopen("youup.in", "r", stdin);
    freopen("youup.out", "w", stdout);
    cin >> num;
    cin >> n >> x;
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
        add_edge(v, u);
    }
    if(n <= 20) {
        dfs1(1, 0);
        dfs2(1, 0);
        for(int i = 1; i <= n; i++) {
            lim = i, total = 0;
            dfs(1, 0);
            cout << total << " ";
        }
        cout << endl;
        return 0;
    } 
    else if(46 <= num && num <= 49) {
        if(x == 0) {
            cout << n << " ";
            for(int i = 2; i <= n; i++) cout << 0 << " ";
            cout << endl;
        }
        else if(x == 1) {
            cout << n << " ";
            cout << n - 1 << " ";
            for(int i = 3; i <= n; i++) cout << 0 << " ";
            cout << endl;
        }
        else {
            cout << n << " ";
            cout << n * (n - 1) / 2 << " ";
            int t1 = n * (n - 1), t2 = (1 * 2);
            for(int i = 3; i <= n; i++) {
                t1 = (t1 * (n - i + 1)) % M;
                t2 = (t2 * i) % M;
                cout << (t1 * getInv(t2)) % M << " ";
            } 
            cout << endl;
        }
    }
} 