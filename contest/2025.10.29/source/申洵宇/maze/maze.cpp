#include <bits/stdc++.h>
using namespace std;
#define N 15
constexpr int nt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int n,m,ex,ey,mp[N][N],dis[N][N],cnt[N][N];
int main(){
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>ex>>ey;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    queue<pair<int,int>>que;
    memset(dis,0x3f,sizeof(dis));
    if(mp[1][1]==0){
        que.emplace(1,1);
        dis[1][1]=0;
        cnt[1][1]=1;
    }
    while(!que.empty()){
        int x=que.front().first,
            y=que.front().second;
        que.pop();
        for(int i=0;i<=3;i++){
            int nx=x+nt[i][0],
                ny=y+nt[i][1];
            if(nx<1||nx>n||ny<1||ny>m||mp[nx][ny])continue;
            if(dis[nx][ny]>dis[x][y]+1){
                dis[nx][ny]=dis[x][y]+1;
                cnt[nx][ny]=cnt[x][y];
                que.emplace(nx,ny);
            }
            else if(dis[nx][ny]==dis[x][y]+1){
                cnt[nx][ny]+=cnt[x][y];
            }
        }
    }
    cout<<cnt[ex][ey];
    return 0;
}
/*
4 4 4 4
0 0 1 0
0 1 0 0
0 0 0 0
0 0 0 0
ans:4

4 4 4 4
0 0 1 0
0 0 0 0
0 0 1 0
0 0 0 0
ans:6

6 6 6 6 
0 1 0 0 0 0
0 0 0 1 0 0
1 0 1 1 0 0
0 0 1 0 0 0
0 1 1 0 0 0
0 0 0 0 0 0
ans:7
*/