#include<bits/stdc++.h>
using namespace std;
int n,m,nx,my;
int cnt;
int puz[15][15];
int flag[15][15];
int step[15][15];
int dir1[6]={1,-1,0,0};
int dir2[6]={0,0,-1,1};
void dfs(int x,int y,int steps){
    if(steps==step[nx][my]&&x==nx&&y==my){
        cnt++;
        return;
    }
    for(int i=0;i<4;i++){
        int xx=x+dir1[i];
        int yy=y+dir2[i];
        if(xx>n||xx<1||yy>m||yy<1) continue;
        if(puz[xx][yy]) continue;
        if(flag[xx][yy]) continue;
        if(steps>step[nx][my]) return;
        flag[xx][yy]=1;
        dfs(xx,yy,steps+1);
        flag[xx][yy]=0;
    }
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
    cin>>n>>m>>nx>>my;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>puz[i][j];
    queue<int> q,p;
    int flag_=0;
    q.push(1),p.push(1);
    flag[1][1]=1;
    while(!q.empty()){
        int x=q.front();
        int y=p.front();
        q.pop(),p.pop();
        for(int i=0;i<4;i++){
            int x_=x+dir1[i];
            int y_=y+dir2[i];
            if(x_<1||x_>n||y_<1||y_>n) continue;
            if(puz[x_][y_]) continue;
            if(flag[x_][y_]) continue;
            step[x_][y_]=step[x][y]+1;
            flag[x_][y_]=1;
            if(x_==nx&&y_==my){
                //cout<<step[x_][y_];
                flag_=1;
                break;
            }
            q.push(x_);
            p.push(y_);
        }
        if(flag_) break;
    }
    memset(flag,0,sizeof(flag));
    flag[1][1]=1;
    dfs(1,1,0);
    cout<<cnt<<"\n";
    return 0;
}
/*
10 10 10 10
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/
