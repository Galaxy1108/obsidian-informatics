#include <bits/stdc++.h>
using namespace std;

struct s{
    int v,c;
};

struct sa{
    int u,v,c;
};

sa rodes[100005];
int cs[100005],cnts;
int fa[100005][15],dep[100005],cost[100005][15];
vector<s> a[100005];

void dfs(int root, int fno) {
    fa[root][0] = fno;
    dep[root] = dep[fa[root][0]] + 1;
    for (int i = 1; i < 15; ++i) {
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
        cost[root][i] = cost[fa[root][i - 1]][i - 1] + cost[root][i - 1];
    }
    int sz = a[root].size();
    for (int i = 0; i < sz; ++i) {
        if (a[root][i].v == fno){
            continue;
        }
        cost[a[root][i].v][0] = a[root][i].c;
        dfs(a[root][i].v, root);
    }
}

int lca(int x, int y){
    if (dep[x] > dep[y]){
        swap(x, y);
    }
    int tmp = dep[y] - dep[x],ans=0;
    for (int j = 0; tmp; ++j, tmp >>= 1){
        if(tmp & 1){
            ans += cost[y][j];
            y = fa[y][j];
        }
    }
    if (y == x){
        return ans;
    }
    for (int j = 14; j >= 0 && y != x; --j) {
        if (fa[x][j] != fa[y][j]) {
            ans += cost[x][j] + cost[y][j];
            x = fa[x][j];
            y = fa[y][j];
        }
    }
    ans += cost[x][0] + cost[y][0];
    return ans;
}



int main(){
    freopen("currencies.in","r",stdin);
    freopen("currencies.out","w",stdout);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<n;i++){
        cin>>rodes[i].u>>rodes[i].v;
    }
    for(int i=1;i<=m;i++){
        int p,c;
        cin>>p>>c;
        rodes[p].c+=c;
    }
    for(int i=1;i<n;i++){
        a[rodes[i].u].push_back({rodes[i].v,rodes[i].c});
        a[rodes[i].v].push_back({rodes[i].u,rodes[i].c});
    }
    dfs(1,-1);
    for(int i=1;i<=q;i++){
        int s,t,x,y;
        cin>>s>>t>>x>>y;
        int u=lca(s,t);
        if(y>=u){
            cout<<x<<'\n';
            continue;
        }
        cout<<x-(u/rodes[1].c-y/rodes[1].c)<<'\n';
    }
}