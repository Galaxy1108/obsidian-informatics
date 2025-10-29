#include<bits/stdc++.h>
using namespace std;
const int N = 20;
int n,m,g1,g2;
bool a[N][N];
long long num[N][N];
int t[N][N];
bool vis[N][N];
typedef pair<pair<int,int>,int> pii;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void bfs(){
    queue<pii>q;
    q.push({{1,1},0});
    t[1][1] = 0;
    num[1][1] = 1;
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        if(u.second>t[u.first.first][u.first.second])continue;
        if(u.second+1>t[g1][g2])continue;
        if(vis[u.first.first][u.first.second])continue;
        vis[u.first.first][u.first.second] = 1;
        //cout<<"s1 "<<u.first.first<<" "<<u.first.second<<" "<<u.second<<endl;
        for(int i = 0;i<4;i++){
            int rx = u.first.first;
            int ry = u.first.second;
            int nowx = u.first.first+dx[i];
            int nowy = u.first.second+dy[i];
            if(nowx<1||nowx>n||nowy<1||nowy>m)continue;
            if(a[nowx][nowy])continue;
            if(t[nowx][nowy]<u.second+1)continue;
            if(u.second+1<=t[nowx][nowy]){
                t[nowx][nowy] = min(t[nowx][nowy],u.second+1);
                //if(nowx==3&&nowy==3)cout<<rx<<" "<<ry<<" "<<num[rx][ry]<<" "<<u.second<<endl;
                num[nowx][nowy]+=num[rx][ry];
                //if(num[nowx][nowy]<0)cout<<"fuck you"<<endl;
                //cout<<"s2 "<<nowx<<" "<<nowy<<" "<<u.second+1<<endl;
                q.push({{nowx,nowy},u.second+1});
            }
        }
    }
}
int main(){
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    cin>>n>>m>>g1>>g2;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            t[i][j] = 0x3f3f3f;
        }
    }
    bfs();

    cout<<num[g1][g2];
    return 0;
}
