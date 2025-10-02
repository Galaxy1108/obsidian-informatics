#include<bits/stdc++.h>
using namespace std;
int n;
int a[2000010];
int maxn[10001][1001],minn[10001][1001];
__int128 ans=0,calc=0;
void write(__int128 x)
{
    if(x>=0&&x<=9)
    {
        putchar(x+'0');
        return;
    }
    write(x/10);
    write(x%10);
}
int main()
{
    freopen("drama.in","r",stdin);
    freopen("drama.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    maxn[0][0]=0,minn[0][0]=1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(1000,i);j++)
        {
            if(j==1)
            {
                maxn[i][j]=minn[i][j]=a[i];
                continue;
            }
            maxn[i][j]=max(maxn[i-1][j-1],a[i]);
            minn[i][j]=min(minn[i-1][j-1],a[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=min(1000,i);j++)
        {
            calc=1ll*j*maxn[i][j]*minn[i][j];
            ans=max(calc,ans);
        }
    }
    write(ans);
}
