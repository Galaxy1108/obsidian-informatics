#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=105;
int n,m,K,a[N][2],f[N][N][15],g[N][15];
il void solve1()
{
    memset(g,-0x3f,sizeof g);
    g[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        g[i][0]=g[i-1][0];
        for(int j=1;j<=K;j++)
        {
            g[i][j]=g[i-1][j];
            for(int k=0;k<i;k++)
            {
                g[i][j]=max(g[i][j],g[k][j-1]+a[i][1]-a[k][1]);
            }
        }
    }
    cout<<g[n][K];
}
il void solve2()
{
    memset(f,-0x3f,sizeof f);
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)f[i][j][0]=0;
    for(int k=0;k<=K;k++)
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int t=i+1;t<=n;t++)f[t][j][k]=max(f[t][j][k],f[i][j][k]);
                for(int t=j+1;t<=n;t++)f[i][t][k]=max(f[i][t][k],f[i][j][k]);
            }
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                for(int t=i+1;t<=n;t++)f[t][j][k+1]=max(f[t][j][k+1],f[i][j][k]+a[t][1]-a[i][1]);
                for(int t=j+1;t<=n;t++)f[i][t][k+1]=max(f[i][t][k+1],f[i][j][k]+a[t][2]-a[j][2]);
                int now=0;
                if(i<j)now+=a[j][1]-a[i][1];
                else now+=a[i][2]-a[j][2];
                f[max(i,j)][max(i,j)][k+1]=max(f[max(i,j)][max(i,j)][k+1],f[i][j][k]+now);
                for(int t=max(i,j)+1;t<=n;t++)
                    f[t][t][k+(i==j?1:2)]=max(f[t][t][k+(i==j?1:2)],f[i][j][k]+now+a[t][1]+a[t][2]-a[max(i,j)][1]-a[max(i,j)][2]);
            }
        }
    }
    cout<<f[n][n][K];
}
int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    cin>>n>>m>>K;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int j=1;j<=m;j++)for(int i=1;i<=n;i++)a[i][j]+=a[i-1][j];
    if(m==1)solve1();
    else solve2();
    return 0;
}