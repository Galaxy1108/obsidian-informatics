#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll fa1[500005], fa2[500005];
ll w1[500005], w2[500005];
vector<ll> a1[500005], a2[500005];
ll dfsn[500005], cnt, rdfsn[500005];
ll ndfs[500005];

int fa[500005][31], dep[500005];
int n, m;

void dfs(int root, int f){
    fa[root][0] = f;
    dep[root] = dep[fa[root][0]] + 1;
    for (int i = 1; i < 31; ++i){
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
    }
    int sz = a1[root].size();
    for (int i = 0; i < sz; ++i){
        if (a1[root][i] == f){
            continue;
        }
        dfs(a1[root][i], root);
    }
}
int lca(int x, int y){
    if (dep[x] > dep[y])
        swap(x, y);
    int tmp = dep[y] - dep[x];
    for (int j = 0; tmp; ++j, tmp >>= 1){
        if (tmp & 1){
            y = fa[y][j];
        }
    }
    if (y == x){
        return x;
    }
    for (int j = 30; j >= 0 && y != x; --j){
        if (fa[x][j] != fa[y][j]){
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    return fa[x][0];
}

void build(int u){
    dfsn[u] = ++cnt;
    ndfs[cnt] = u;
    for(auto v:a2[u]){
        if(v==fa2[u]){
            continue;
        }
        build(v);
    }
    rdfsn[u] = cnt;
}

ll ans1(int u,int v){
    ll anss = 0, cnts = 0;
    while(u!=v){
        anss += w2[u] * (cnts++);
        u = fa2[u];
    }
    anss += w2[v] * (cnts++);
    return anss;
}

ll ans2(int u,int v){
    ll lcs = lca(u, v);
    ll anss = 0;
    int su = u;
    while(u!=lcs){
        anss += w1[u];
        u = fa1[u];
    }
    while(v!=lcs){
        anss += w1[v];
        v = fa1[v];
    }
    return anss;
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ll n;
    cin >> n;
    for (int i = 2; i <= n;i++){
        cin >> fa1[i];
        a1[fa1[i]].emplace_back(i);
    }
    for (int i = 2; i <= n;i++){
        cin >> w1[i];
    }
    for (int i = 2; i <= n;i++){
        cin >> fa2[i];
        a2[fa2[i]].emplace_back(i);
    }
    for (int i = 1; i <= n;i++){
        cin >> w2[i];
    }
    build(1);
    dfs(1, 0);
    for (int i = 1; i <= n;i++){
        ll anss = LLONG_MIN;
        for (int j = dfsn[i]; j <= rdfsn[i];j++){
            anss = max(anss, ans1(ndfs[j], i) + ans2(ndfs[j], i));
        }
        cout << anss << ' ';
    }
    return 0;
}