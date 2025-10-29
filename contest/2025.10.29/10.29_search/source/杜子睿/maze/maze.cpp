#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,mp[15][15],book[15][15],cnt[15][15],d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct node{
    int x,y,t,fx,fy;
};
void bfs(){
    queue<node> q;
    q.push({1,1,0,0,0});
    cnt[0][0]=1;
    while(!q.empty()){
        node u=q.front();
        q.pop();
        if(book[x][y]&&u.t>book[x][y])break;
        if(u.x==1&&u.y==1&&u.t!=0)continue;
        if(book[u.x][u.y]){if(book[u.x][u.y]==u.t)cnt[u.x][u.y]+=cnt[u.fx][u.fy];continue;}
        book[u.x][u.y]=u.t;
        cnt[u.x][u.y]+=cnt[u.fx][u.fy];
        for(int i=0;i<4;i++){
            int nx=u.x+d[i][0],ny=u.y+d[i][1];
            if(nx<=n&&ny<=m&&nx>=1&&ny>=1&&!mp[nx][ny])q.push({nx,ny,u.t+1,u.x,u.y});
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>mp[i][j];
    if(mp[1][1]||mp[x][y]){cout<<0;return 0;}
    bfs();
    cout<<cnt[x][y];
    return 0;
}