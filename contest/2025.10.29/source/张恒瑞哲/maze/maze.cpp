#include<bits/stdc++.h>
using namespace std;

#define pr printf
#define sc scanf
#define REP(a,b,c) for(int a = (b);a <= (c);++a)
#define DOW(a,b,c) for(int a = (b);a >= (c);--a)
#define Pb push_back
#define Eb emplace_back
#define Sz(v) (int(v.size()))
#define FALL(v) v.begin(),v.end()
#define fi first
#define se second

typedef long long ll;
typedef pair<int,int> P2i;
typedef vector<int> Vi;

const int INF = INT_MAX;
const long long LNF = LLONG_MAX;
const double Pi = 3.1415926535;
const double EPS = 1e-7;

const int MAXN = 20;
const int MOD = 0;

int n,m;
bitset<MAXN> mp[MAXN];
int bfsj[MAXN][MAXN];
int dis[MAXN][MAXN];

struct Pos{ int x,y; };
struct State{ Pos p; int pd; };
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

void Bfs(Pos S){
    queue<State> q; q.push({S,0});
    bfsj[S.x][S.y] = 1;
    while(!q.empty()){
        Pos ps = q.front().p;
        int pd = q.front().pd;
        int x = ps.x,y = ps.y;
        q.pop();
        REP(i,0,3){
            int nx = x+dx[i],ny = y+dy[i];
            if(nx < 1 || nx > m || ny < 1 || ny > n) continue;
            if(mp[nx][ny]) continue;
            Pos nps = {nx,ny};
            if(!dis[nx][ny]) dis[nx][ny] = pd+1,bfsj[nx][ny] += bfsj[x][y],q.push({nps,pd+1});
            else if(pd+1 == dis[nx][ny]) bfsj[nx][ny] += bfsj[x][y];
        }
    }
}

int main(){

	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);

    int tmp,tx,ty; sc("%d%d%d%d",&n,&m,&tx,&ty);
    REP(i,1,n) REP(j,1,m) sc("%d",&tmp),mp[j][i] = tmp;
    Bfs({1,1});
    pr("%d",bfsj[tx][ty]);

    return 0;
}
