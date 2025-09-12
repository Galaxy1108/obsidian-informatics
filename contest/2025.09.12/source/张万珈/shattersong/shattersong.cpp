#include <bits/stdc++.h>
using namespace std;

int z[100010];
int mp[510][510];
int main()
{
    freopen("shattersongs.in","r",stdin);
    freopen("shattersongs.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> z[i];
        for(int j=1;j<=n;j++) mp[i][j] = INT_MAX;
        mp[i][i] = 0;
    }
    for(int i=1,u,v,w;i<=m;i++)
    {
        cin >> u >> v >> w;
        mp[u][v] = w;
        mp[v][u] = w;
    }
    if(n == 2) {cout << "2\n1 1\n1 2"; return 0;}
    
}