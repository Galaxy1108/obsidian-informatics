#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int type;
bool mp[2010][2010];
int n,m,k;
const int nx[3] = {1,0},ny[3] = {0,1};
void dfs(int x,int y,int q,int cnt,int to)
{
    if(mp[x][y])
    {
        to ^= 1;
        cnt ++;
        if(cnt >= q)
        {
            cout << x << ' ' << y << endl;
            return;
        }
    }
    if(x > n)
    {
        cout << x << ' ' << y << endl;
        return ;
    }
    if(y > m)
    {
        cout << x << ' ' << y << endl;
        return ;
    }
    dfs(x+nx[to],y+ny[to],q,cnt,to);
}
int main()
{
    freopen("corridor.in","r",stdin);
    freopen("corridor.out","w",stdout);
    cin >> type >> n >> m >> k;
    for(int i=1,x,y;i<=k;i++)
    {
        cin >> x >> y;
        mp[x][y] = 1;
    }
    int Q;
    cin >> Q;
    for(int i=1,w,x,y,q;i<=Q;i++)
    {
        cin >> w >> x >> y;
        if(w==1)
        {
            mp[x][y] = 1;
        }
        else
        {
            cin >> q;
            if(x == 0) dfs(x+1,y,q,0,0);
            else dfs(x,y+1,q,0,1);
        }
    }
}
