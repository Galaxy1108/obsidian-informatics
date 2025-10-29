#include<bits/stdc++.h>
using namespace std;
const int mx=505;
const int mod=998244353;
int n,x;
long long f[mx][mx];
int a[mx],b[mx];
int ans=0;

bool check()
{
    for(int i=1;i<=n;i++) b[i]=a[i];
    sort(b+1,b+1+n);
    int p=1;
    while(p<=n)
    {
        int np=p;
        int k=(b[p]-1)/(n-p)+1;
        while(b[np]<=k*(n-p)&&np<=n+1) np++;
        p=np;
        if(p==n) return 0;
    }
    return 1;
}
void dfs(int p)
{
    if(p==n+1)
    {
        if(check()) ans++;
        return;
    }
    for(int i=1;i<=x;i++)
    {
        a[p]=i;
        dfs(p+1);
    }
}

int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>x;
    dfs(1);
    cout<<ans<<endl;
    // f[1][0]=1;
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=x;j++)
    //     {
    //         for(int k=1;k<i;k++)
    //         {
    //             for(int w=1;w<=x;w++)
    //             {
    //                 f[i][j]+=f[k][w]+f[i-k][j-w];
    //                 f[i][j]%=mod;
    //             }
                
    //         }
    //     }
    // }
    // cout<<f[n][x]<<endl;
    return 0;
}
