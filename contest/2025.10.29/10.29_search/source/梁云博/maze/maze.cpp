#include <bits/stdc++.h>
#define N 14
#define int long long 
using namespace std;
int n,m,x,y;

bitset<N>g[N];


namespace solve
{
    int minn=1e9,cnt,can=0;
    int dir[4][2]={
        {1,0},
        {0,1},
        {-1,0},
        {0,-1}
    };
    int vis[N][N][N*N],dis[N][N];
    void Mobius(int i,int j,int step)
    {
        if(dis[i][j]<step)return;
        // if(i==x && j==y)
        // {
        //     if(minn>dis[i][j])
        //     {
        //         minn=step;
        //         cnt=1;
        //     }
        //     else if(minn==step)cnt++;
        //     return;
        // }
        if(i==x && j==y)can=1;
        dis[i][j]=step;
        vis[i][j][step]++;
        for(int k=0;k<4;k++)
        {
            int ni=i+dir[k][0],nj=j+dir[k][1];
            if(g[ni][nj])continue;
            Mobius(ni,nj,step+1);
        }
    }

    void solve()
    {
        memset(dis,63,sizeof(dis));
        dis[1][1]=0;
        if(g[1][1])return cout<<0<<"\n",void();
        Mobius(1,1,0);
        if(!can)return cout<<0<<"\n",void();
        cout<<vis[x][y][dis[x][y]]<<"\n";
    }
}


signed main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>x>>y;
    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=m+1;j++)
        {
            g[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            bool x;
            cin>>x;
            g[i][j]=x;
        }
    }
    solve::solve();
    return 0;
}