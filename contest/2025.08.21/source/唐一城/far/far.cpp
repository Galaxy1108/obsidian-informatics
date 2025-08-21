#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N=45,mod=998244353;
ll n,t[N],m,l[N],r[N],f[N][1<<11];
il int check(ll x)
{
    for(int i=1;i<=m;i++)
    {
        t[i]=x%2;
        x/=2;
    }
    for(int i=1;i<=m;i++)if(t[i]!=t[m-i+1])return 0;
    return 1;
}
il void solve1()
{
    f[0][0]=1;//cout<<check(3)<<' ';
    for(int i=1;i<=n;i++)
    {
        ll ans=0;
        for(ll j=0;j<(1<<m);j++)
        {
            for(int k=l[i];k<=r[i];k++)
            {
                f[i][j]=(f[i][j]+f[i-1][j^k])%mod;
            }
            // cout<<f[i][j]<<' ';
            if(check(j))ans=(ans+f[i][j])%mod;
        }
        // cout<<'\n';
        cout<<ans<<'\n';
    }
}
il void solve2()
{
    ll mi=(1ll<<m)%mod,now=1;
    for(int i=1;i<=n;i++)
    {
        if(m%2==0)
        {
            cout<<(1ll<<(m/2))%mod*now%mod<<'\n';
        }
        else{
            cout<<(1ll<<(m/2))%mod*now%mod*2%mod<<'\n';
        }
        now=now*mi%mod;
    }
}
int main()
{
    freopen("far.in","r",stdin);
    freopen("far.out","w",stdout);
    cin>>n>>m;
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        if(l[i]==0&&r[i]==(1<<m)-1)continue;
        flag=1;
    }
    if(flag==0)solve2();
    else if(n<=15&&m<=15)solve1();
    return 0;
}