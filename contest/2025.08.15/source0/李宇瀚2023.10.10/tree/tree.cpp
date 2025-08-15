#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 2e6 + 6;

int n;
int ST[N * 2][22];
int lg[N];
ll a[N];

inline ll getdis(int x, int y);

struct Tree {
    int head[N], pre[N], ver[N], cnt = 0;
    ll val[N], dep[N], Ansn[N];
    int ddep[N];
    int ff[N], ed[N], temp[2 * N], tot = 0;

    inline void add_edge(int u, int v, ll w) {
        pre[++cnt] = head[u];
        head[u] = cnt;
        ver[cnt] = v; val[cnt] = w;
        return;
    }

    void dfs(int nown, int fa) {
        ff[nown] = fa; ddep[nown] = ddep[fa] + 1;
        ed[nown] = ++tot, temp[tot] = nown;
        for(int i = head[nown]; i; i = pre[i]) {
            int v = ver[i];
            dep[v] = dep[nown] + val[i];
            dfs(v, nown);
            ed[nown] = ++tot, temp[tot] = nown;
        }
        return;
    }

    void solve(int nown, int fa) {
        for(int i = head[nown]; i; i = pre[i]) {
            int v = ver[i];
            solve(v, nown);
        }
        int Su = 0, cur = nown;
        ll cnt = 1;
        while(cur != 0) {
            cur = ff[cur], Su += cnt * a[cur];
            cnt++;
            Ansn[cur] = max(Ansn[cur], Su + getdis(nown, cur));
        } 
        return;
    }
}Tr[2];

inline int merge(int x, int y) {
    if(Tr[0].ddep[x] <= Tr[0].ddep[y]) return x;
    else return y;
}

inline void build_ST() {
    for(int i = 1; i <= 2 * n - 1; ++i) ST[i][0] = Tr[0].temp[i];
    for(int j = 1; j <= 21; ++j) for(int i = 1; i <= 2 * n - 1; ++i) ST[i][j] = merge(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
    return;
}

inline int query(int l, int r) {
    int t = lg[r - l + 1];
    return merge(ST[l][t], ST[r - (1 << t) + 1][t]);
}

inline int LCA(int x, int y) {
    if(Tr[0].ddep[x] >= Tr[0].ddep[y]) swap(x, y);
    if(Tr[0].ed[x] >= Tr[0].ed[y]) swap(x, y);
    return query(Tr[0].ed[x], Tr[0].ed[y]);
}

inline ll getdis(int x, int y) {
    int lc = LCA(x, y);
    return Tr[0].dep[x] + Tr[0].dep[y] - 2ll * Tr[0].dep[lc];
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 2; i <= N - 5; ++i) lg[i] = lg[i >> 1] + 1;
    for(int i = 2; i <= n; ++i) {
        int x; cin >> x;
        Tr[0].ff[i] = x;
    } 
    for(int i = 2; i <= n; ++i) {
        ll w; cin >> w;
        Tr[0].add_edge(Tr[0].ff[i], i, w);
    }
    for(int i = 2; i <= n; ++i) {
        int x; cin >> x;
        Tr[1].add_edge(x, i, 0);
    }
    for(int i = 1; i <= n; ++i) cin >> a[i];
    Tr[0].dfs(1, 0), Tr[1].dfs(1, 0); Tr[0].ddep[0] = 1e9;
    build_ST();
    Tr[1].solve(1, 0);
    for(int i = 1; i <= n; ++i) cout << Tr[1].Ansn[i] << ' ';
    cout << '\n';
    return 0;
}