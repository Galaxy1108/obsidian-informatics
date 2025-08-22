#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int mod;
int ans=0;
void DFS(int a,int b,int deep)
{
    if(deep>n)
    {
        ans++;
        ans%=mod;
        return;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=i;j<=m;j++)
        {
            if((i<a&&j<a)||(i>b&&j>b))
            {
                continue;
            }
            DFS(i,j,deep+1);
        }
    }
}
signed main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin>>n>>m>>mod;
    if(n==1)
    {
        cout<<(1ll*m*(m+1)/2)%mod;
        return 0;
    }
    if(m==1)
    {
        cout<<m%mod;
        return 0;
    }
    DFS(1,m,1);
    cout<<ans%mod;
}