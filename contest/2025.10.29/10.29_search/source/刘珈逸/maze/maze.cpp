#include<bits/stdc++.h>
using namespace std;
const int N=15,inf=0x3f3f3f3f;
const int dx[]={0,0,1,-1},
          dy[]={1,-1,0,0};
int n,m,x,y;
int a[N][N];
bool vis[N][N];
int dis[N][N];
long long cnt[N][N];
typedef pair<int,int>pii;
#define fi first
#define se second
queue<pii>q;
int main(){
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
    memset(dis,0x3f,sizeof(dis));
    if(a[1][1]||a[x][y]){
        puts("0");
        return 0;
    }
    q.push({1,1});dis[1][1]=0,cnt[1][1]=1;
    while(q.size()){
        int x=q.front().fi,y=q.front().se;q.pop();
        if(vis[x][y])continue;vis[x][y]=1;
        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m||a[xx][yy])continue;
            if(dis[xx][yy]>dis[x][y]+1)dis[xx][yy]=dis[x][y]+1,cnt[xx][yy]=cnt[x][y],q.push({xx,yy});
            else cnt[xx][yy]+=cnt[x][y];
        }
    }
    printf("%lld\n",cnt[x][y]);
    return 0;
}