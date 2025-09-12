#include <bits/stdc++.h>
using namespace std;
#define hh cout << endl;
const int N = 5e5 + 10;
struct Edge{
    int to, nxt;
}E[N];
int h[N], cnt = 0;
void addedge(int u, int v){
    E[++cnt].to = v;
    E[cnt].nxt = h[u];
    h[u] = cnt; 
}
int depth[N];
struct T{
    int max1, maxi1, max2, maxi2;
} dep[N];
int d[N];
int ans1 = 0;
void dfs(int u, int fa){
    depth[u] = depth[fa] + 1;
    ans1 = max(ans1, depth[u]);
    for(int i = h[u]; i; i = E[i].nxt){
        int v = E[i].to;
        if(v == fa)continue;
        dfs(v, u);
    }
}
void Main(){
    cnt = 0;
    memset(E, 0, sizeof(E));
    memset(h, 0, sizeof(h));
    int n;
    cin >> n;
    int k = 0;
    for(int i = 1, x, y; i < n; i++){
        cin >> x >> y;
        addedge(x, y);
        addedge(y, x);
        if(abs(y - x) == 1)k++;
    }
    if(n > 20){
        // cout << log2(n) << endl;
        cout << ((int)log2(n) + 1) << endl;
        // cout << 90098;
        return;
    }
    int ans = 1e9;
    for(int i = 1; i <= n; i++){
        ans1 = 0;
        memset(depth, 0, sizeof(depth));
        dfs(i, 0);
        ans = min(ans, ans1);
    }
    if(n > 18)ans--;
    cout << ans << endl;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	freopen("labyrinth.in", "r", stdin);
	freopen("labyrinth.out", "w", stdout); 
    int T;
    cin >> T;
    while(T--)Main();
    return 0;
}
