#include<iostream>
#include<queue>
using namespace std;
bool mp[15][15];
bool vis[15][15];
struct Qi
{
    int x;
    int y;
    int step;
};
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
int n,m,tx,ty;
int cnt;
int minn=1e9;
inline void DFS(int x,int y,int step)
{
    if(x==tx&&y==ty)
    {
        if(step<minn)
        {
            minn=step,cnt=1;
            return ;
        }
        else if(step==minn) cnt++;
    }
    for(int i=0;i<4;i++)
    {
        if(x+dx[i]<1||x+dx[i]>n||y+dy[i]<1||y+dy[i]>m) continue;
        if(mp[x+dx[i]][y+dy[i]]) continue;
        if(vis[x+dx[i]][y+dy[i]]==1) continue;
        vis[x+dx[i]][y+dy[i]]=1;
        DFS(x+dx[i],y+dy[i],step+1);
        vis[x+dx[i]][y+dy[i]]=0;
    }
    return ;
}
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>n>>m>>tx>>ty;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
        }
    }
    DFS(1,1,0);
    cout<<cnt;
    return 0;
}