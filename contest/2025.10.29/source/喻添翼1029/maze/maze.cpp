#include<bits/stdc++.h>
using namespace std;
const int mx=150;
int n,m,X,Y;
int a[13][13];
long long cnt[150];
long long vis[13][13][150];
long long d[13][13];
struct pos
{
    int x,y,dis;
};
queue<pos> q;
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int Ans=300;
void bfs()
{
    memset(d,0x3f,sizeof(d));
    d[1][1]=0;
    q.push({1,1,0});
    vis[1][1][0]=1;
    while(!q.empty())
    {
        pos p=q.front();
        q.pop();
        int x=p.x,y=p.y,dis=p.dis;

        if(x==X&&y==Y) 
        {
            cnt[dis]=vis[x][y][dis];
            Ans=min(Ans,dis);
        }
        if(dis+1>Ans) continue;

        for(int i=0;i<=3;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(a[nx][ny]) continue;

            if(dis+1>d[nx][ny]) continue;
            d[nx][ny]=dis+1;
            vis[nx][ny][dis+1]+=vis[x][y][dis];

            q.push({nx,ny,dis+1});
        }
        vis[x][y][dis]=0;
    }

}
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>n>>m>>X>>Y;
    for(int i=1;i<=n;i++) 
        for(int j=1;j<=m;j++) cin>>a[i][j];
    bfs();
    cout<<cnt[Ans];
    return 0;
}
