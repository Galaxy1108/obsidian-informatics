/*
  Program: maze
  Copyright by G10
  Please do not copy it
  Or Mr.Xiang will invite you with a cup of tee
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<ctime>
#include<vector>
#include<stack>
#include<set>
#include<map>
#define File(S) freopen(S".in","r",stdin);freopen(S".out","w",stdout);
#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif
using namespace std;

typedef long long LL;

const int INF=2147483647;

LL getint()
{
    LL res=0,p=1;
    char ch=getchar();
    while ((ch<'0'||ch>'9') && ch!='-') ch = getchar();
    if (ch=='-') p=-1,ch=getchar();
    while (ch>='0'&&ch<='9') res=res*10+ch-'0',ch=getchar();
    return res*p;
}

const int N=15;
const int go[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int n,m,tx,ty;
int g[N][N],dis[N][N];
LL cnt[N][N];
struct Node
{
    int x,y;
    Node(){}
    Node(int x,int y):x(x),y(y){}
};
queue <Node> Q;

int main()
{
    File("maze");
    n=getint();m=getint();tx=getint();ty=getint();
    int i,j,x,y,xx,yy;
    for (i=1;i<=n;i++) for (j=1;j<=m;j++) g[i][j]=getint()^1;
    dis[1][1]=1;cnt[1][1]=1;
    Q.push(Node(1,1));
    while (!Q.empty()) {
        x=Q.front().x;y=Q.front().y;Q.pop();
        for (i=0;i<=3;i++) {
            xx=x+go[i][0];yy=y+go[i][1];
            if (g[xx][yy]) {
                if (!dis[xx][yy]) {
                    dis[xx][yy]=dis[x][y]+1;
                    cnt[xx][yy]=cnt[x][y];
                    Q.push(Node(xx,yy));
                }
                else if (dis[xx][yy]==dis[x][y]+1) {
                    cnt[xx][yy]+=cnt[x][y];
                }
            }
        }
    }
    printf("%lld\n",cnt[tx][ty]);
    return 0;
}
