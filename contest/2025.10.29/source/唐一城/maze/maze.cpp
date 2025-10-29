#include <bits/stdc++.h>
using namespace std;
const int N=20;
int n,m,ex,ey,a[N][N],ans=INT_MAX,cnt=0,vis[N][N],f[N][N];
inline void dfs(int x,int y,int dis) {
    if(dis>ans)return;
    if(x==ex&&y==ey) {
        if(ans>dis)ans=dis,cnt=1;
        else if(ans==dis)cnt++;
        return;
    }if(f[x][y]>dis)f[x][y]=dis;
    if(f[x][y]<dis)return;
    if(!vis[x+1][y]&&x+1<=n&&!a[x+1][y]){vis[x+1][y]=1;dfs(x+1,y,dis+1);vis[x+1][y]=0;}
    if(!vis[x-1][y]&&1<=x-1&&!a[x-1][y]){vis[x-1][y]=1;dfs(x-1,y,dis+1);vis[x-1][y]=0;}
    if(!vis[x][y+1]&&y+1<=m&&!a[x][y+1]){vis[x][y+1]=1;dfs(x,y+1,dis+1);vis[x][y+1]=0;}
    if(!vis[x][y-1]&&1<=y-1&&!a[x][y-1]){vis[x][y-1]=1;dfs(x,y-1,dis+1);vis[x][y-1]=0;}
}
int main() {
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>n>>m>>ex>>ey;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){cin>>a[i][j];f[i][j]=INT_MAX;}
    dfs(1,1,0);cout<<cnt;
    return 0;
}
