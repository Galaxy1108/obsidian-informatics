#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2005;
ll inf=0x3f3f3f3f3f3f3f;
int n;
ll pre[N],mxpre[N],mxsuf[N],mx[N],a[N][3];
int main()
{
    freopen("base.in","r",stdin);
    freopen("base.out","w",stdout);
    cin>>n;
    for(int i=1;i<=2;i++)for(int j=1;j<=n;j++)cin>>a[j][i];
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i][1]+a[i][2],mx[i]=mx[i-1]+a[i][2];
    memset(mxpre,-0x3f,sizeof mxpre);
    memset(mxsuf,-0x3f,sizeof mxsuf);
    for(int i=1;i<=n;i++)for(int j=1;j<=i;j++)mxpre[i]=max(mxpre[i],pre[i]-pre[j-1]);
    for(int i=n;i>=1;i--)for(int j=i;j<=n;j++)mxsuf[i]=max(mxsuf[i],pre[j]-pre[i-1]);
    ll ans=-inf;
    for(int i=2;i<n;i++)for(int j=i;j<n;j++)ans=max(ans,mxpre[i-1]+mxsuf[j+1]+mx[j]-mx[i-1]);
    cout<<ans;
    return 0;
}