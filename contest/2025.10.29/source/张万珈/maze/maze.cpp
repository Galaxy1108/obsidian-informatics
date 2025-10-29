#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mk make_pair
int mp[20][20];
int dis[20][20],cnt[20][20];
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    for(int i=0;i<=m+1;i++)
    {
        mp[0][i] = mp[n+1][i] = 1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> mp[i][j];
            dis[i][j] = 1e9;
        }
    }
    queue<pair<int,pii>> q;
    q.push(mk(0,mk(1,1)));
    while(!q.empty())
    {
        int s=q.front().first;pii now = q.front().second;
        int x = now.first,y = now.second;q.pop();
        // cout << x << ' ' << y << ' ' << s << '\n';
        if(x<1||x>n||y<1||y>m) continue;
        if(dis[x][y] < s) continue;
        else if(dis[x][y] == s){cnt[x][y] ++;}
        else {dis[x][y] = s;cnt[x][y] = 1;}
        if(!mp[x-1][y]) q.push(mk(s+1,mk(x-1,y)));
        if(!mp[x+1][y]) q.push(mk(s+1,mk(x+1,y)));
        if(!mp[x][y-1]) q.push(mk(s+1,mk(x,y-1)));
        if(!mp[x][y+1]) q.push(mk(s+1,mk(x,y+1)));
    }
    cout << cnt[a][b];
}