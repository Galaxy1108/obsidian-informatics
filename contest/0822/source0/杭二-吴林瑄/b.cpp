#include<bits/stdc++.h>
using namespace std;
#define ll long long
int w[2005][2005];
int n;
ll dis[2005];
int vis[2005];
void dij(){
    priority_queue<pair<ll, int> > q;
    for(int i = 0; i <= n; i++)dis[i] = 1e15;
    dis[0] = 0;
    q.emplace(-dis[0], 0);
    while(!q.empty()){
        int p = q.top().second;
        q.pop();
        if(vis[p])continue;
        vis[p] = 1;
        for(int i = 0; i <= n; i++){
            if(dis[i] > dis[p] + w[p][i]){
                dis[i] = dis[p] + w[p][i];
                q.emplace(-dis[i], i);
            }
        }
    }
}
signed main(){
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> n;
    int mnn = 1e9 + 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i; j++){
            scanf("%d", &w[i][i+j]);
            if(mnn > w[i][i+j]){
                mnn = w[i][i+j];
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            w[i][j] = w[j][i];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i!=j)w[i][j] -= mnn;
        }
    }
    for(int i = 1; i <= n; i++){
        int mn = 1e9;
        for(int j = 1; j <= n; j++){
            if(i == j)continue;
            mn = min(mn, w[i][j]);
        }
        w[0][i] = w[i][0] = mn * 2;
    }
    dij();
    for(int i = 1; i <= n; i++){
        ll ans = dis[i] + mnn * (n - 1);
        printf("%lld\n", ans);
    }
    return 0;
}