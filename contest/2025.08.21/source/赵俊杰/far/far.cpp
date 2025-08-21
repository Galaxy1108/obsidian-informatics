#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=45;
const int MOD=998244353;
ll l[N],r[N],f[1<<17],v,n,m,g[1<<17];
bool ok(ll c)
{
    for(int i=0;i<m;i++)
    {
        if(((c>>i)&1)!=((c>>(m-i-1))&1))
            return 0;
    }
    return 1;
}
int main()
{
    freopen("far.in","r",stdin);
    freopen("far.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int flag=1;
    cin>>n>>m;
    v=(1ll<<m)-1;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        if(l[i]!=0||r[i]!=v)flag=0;
    }
    if(!flag)
    {
        f[0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=v;j++)g[j]=f[j];
            for(int j=0;j<=v;j++)f[j]=0;
            for(int j=l[i];j<=r[i];j++)
                for(int k=0;k<=v;k++)
                    f[k^j]=(f[k^j]+g[k])%MOD;
            ll sum=0;
            for(int j=0;j<=v;j++)
                if(ok(j))sum=(sum+f[j])%MOD;
            //for(int j=0;j<=v;j++)cout<<f[j]<<' ';
            //cout<<'\n';
            cout<<sum%MOD<<'\n';
        }
    }
    else
    {
        ll cnt=(1ll<<((m+1)/2))%MOD,ans=cnt;
        for(int i=1;i<=n;i++)
        {
            cout<<ans<<'\n';
            ans=ans*((1ll<<m)%MOD)%MOD;
        }
    }
    return 0;
}
