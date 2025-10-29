#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m,tx,ty,a[15][15];
int dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};
int dis[15][15];
long long cnt[15][15];
struct Node{
    int x,y;
};
queue<Node> q;
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&tx,&ty);
    for (int i=0;i<=n+1;i++)
        for (int j=0;j<=m+1;j++)
            a[i][j] = 1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    memset(dis,0x3f3f3f3f,sizeof(dis));
    dis[1][1] = 0;
    cnt[1][1] = 1;
    q.push({1,1});
    while (!q.empty())
    {
        int x = q.front().x,y = q.front().y;
        q.pop();
        for (int d=0;d<4;d++)
        {
            int nx = x + dx[d],ny = y + dy[d];
            if (a[nx][ny]) continue ;
            if (dis[nx][ny]>dis[x][y]+1)
            {
                dis[nx][ny] = dis[x][y] + 1;
                cnt[nx][ny] = cnt[x][y];
                q.push({nx,ny});
            }
            else if (dis[nx][ny]==dis[x][y]+1)
                cnt[nx][ny] += cnt[x][y];
        }
    }
    printf("%lld",cnt[tx][ty]);
    return 0;
}