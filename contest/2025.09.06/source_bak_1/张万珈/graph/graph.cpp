#include <bits/stdc++.h>
using namespace std;
mt19937 rd(20100217);
struct node{
    int u,v;
};
int u[151],v[151];
bool vis[151];
vector<node> e;

int main()
{
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    int n,m;
    cin >> n >> m;
    if(n > 50) return 0;
    for(int i=1;i<=m;i++)
    {
        cin >> u[i] >> v[i];
        if(u[i] > v[i]) swap(u[i],v[i]);
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i+1;j<=m;j++)
        {
            if(u[i] == u[j] || v[i] == v[j] || u[i] == v[j] || v[i] == u[j])
            {
                e.push_back({i,j});
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=1e4;i++)
    {
        shuffle(e.begin(),e.end(),rd);
        for(int j=1;j<=m;j++)
        {
            vis[j] = 0;
        }
        int cnt = 0;
        for(node x:e)
        {
            if(vis[x.u] || vis[x.v]) continue;
            vis[x.u] = vis[x.v] = 1;
            cnt++;
        }
        ans = max(ans,cnt);
    }
    cout << ans;
    return 0;
}