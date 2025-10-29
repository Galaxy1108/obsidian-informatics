#include<iostream>
using namespace std;
int mp[15][15],stp[15][15],cnt[15][15];
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1},h,t;
struct node
{
    int x,y;
}q[250];
int main()
{
    freopen("maze.in","r",stdin);
    freopen("maze.out","w",stdout);
    int n,m,i,j,a,b;
    cin>>n>>m>>a>>b;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
    {
        cin>>mp[i][j];
        stp[i][j]=-1;
    }
    stp[1][1]=0;
    cnt[1][1]=1;
    q[t].x=1;
    q[t].y=1;
    t++;
    while(h<t)
    {
        if(q[h].x==a&&q[h].y==b)
            break;
        for(i=0;i<=3;i++)
        {
            int xn=q[h].x+dx[i];
            int yn=q[h].y+dy[i];
            if(xn>=1&&xn<=n&&yn>=1&&yn<=m&&mp[xn][yn]==0)
            {
                if(stp[xn][yn]==-1)
                {
                    stp[xn][yn]=stp[q[h].x][q[h].y]+1;
                    cnt[xn][yn]+=cnt[q[h].x][q[h].y];
                    q[t].x=xn;
                    q[t].y=yn;
                    t++;
                }
                else
                {
                    if(stp[xn][yn]==stp[q[h].x][q[h].y]+1)
                        cnt[xn][yn]+=cnt[q[h].x][q[h].y];
                }
            }
        }
        h++;
    }
    cout<<cnt[a][b];
    return 0;
}

