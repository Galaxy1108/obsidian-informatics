#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mpr make_pair
const int N=15;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='1')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int n,m,X,Y;
bool vis[N][N];
int dis[N][N],ans[N][N];
int tox[4]={1,-1,0,0},toy[4]={0,0,1,-1};

signed main(){
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    n=read();m=read();X=read();Y=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            vis[i][j]=read();
    for(int i=0;i<=n+1;++i)vis[i][0]=vis[i][m+1]=1;
    for(int i=0;i<=m+1;++i)vis[0][i]=vis[n+1][i]=1;
    memset(dis,0x3F,sizeof(dis));
    dis[1][1]=0;ans[1][1]=1;
    queue<pii> q;q.push(mpr(1,1));
    while(!q.empty()){
        pii u=q.front();q.pop();
        int x=u.first,y=u.second;
        if(dis[x][y]>dis[X][Y])break;
        for(int i=0;i<4;++i){
            int nx=x+tox[i],ny=y+toy[i];
            if(!vis[nx][ny]&&dis[nx][ny]>=dis[x][y]+1){
                if(dis[nx][ny]==dis[x][y]+1)ans[nx][ny]+=ans[x][y];
                else {
                    dis[nx][ny]=dis[x][y]+1,ans[nx][ny]=ans[x][y];
                    q.push(mpr(nx,ny));
                }
            }
        }
    }
    print(ans[X][Y]);putchar('\n');
    return 0;
}
