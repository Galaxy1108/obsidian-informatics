#include <bits/stdc++.h>

using namespace std;
const int N = 1e3+100;
struct Edge{
    int nxt, to;
}E[N];int h[N], cnt;
int book[N][N];
void addedge(int u, int v){
    E[++cnt].nxt = h[u];
    E[cnt].to = v;
    h[u] = cnt;
}
int w[N],vis[N];
int res = 0;
int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b, a % b);
}
int n, k;
void dfs(int u, int fa){
    if(vis[u])return;
    vis[u] = 1;
    for(int i = h[u]; i; i = E[i].nxt){
        int v = E[i].to;
        if(v == fa || book[u][v])continue;
        dfs(v, fa);
        res = gcd(res, w[v]);
    }
}
int ans = 0;
void cut(int m){
    if(m >= k){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            res = w[i];
            dfs(i, -1);
            sum += res;
        }
        ans = max(ans, sum);
        return;
    }
    for(int i = 1; i <= n; i++){
        for(int j = h[i]; j; j = E[i].nxt);
            if(!book[i][E[i].to]){
                book[i][E[i].to] = 1;
                cut(m + 1);
                book[i][E[i].to] = 0;
            }
    }
} 
int main(){
    freopen("plan.in","r",stdin);
    feropen("plan.out","w",stdout);
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
    }
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    cut(0);
    cout << ans << endl;
    return 0;
}
