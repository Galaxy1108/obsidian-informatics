#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+5;
int n,m;
ll f[N][105],a[N];
int main()
{
    freopen("brush.in","r",stdin);
    freopen("brush.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    memset(f,0x3f,sizeof f);
    f[1][1]=a[1];
    for(int i=2,pre=a[1],id=1;i<=m;i++)
    {
        f[i][(i-id)+1]=a[i]+pre;
        if(pre>a[i])id=i,pre=a[i];
    }
    for(int i=m+1;i<=n;i++)
    {
        for(int d=2;d<=m;d++)
        {
            int j=max(0,i-d+1);
            for(int k=max(0,i-m);k<=j;k++)
            {
                f[i][d]=min(f[i][d],f[j][(j-k+1)]+a[i]);
            }
        }
    }
    ll ans=f[0][0];
    for(int i=max(0,n-m+1);i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            int k=max(0,i-j+1);
            if(n-k+1<=m)ans=min(ans,f[i][j]);
        }
    }
    cout<<ans;
    return 0;
}