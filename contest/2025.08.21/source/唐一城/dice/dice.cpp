#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
const int N=5005,mod=1e9+7;
int n,a[N];
ll pre[N];
il ll qmi(ll a,ll b)
{
    ll res=1;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }return res;
}
il ll check(ll x){if(x<0)return x+mod;return x;}
int main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);a[n+1]=INT_MAX;
    ll y=1;pre[0]=1;
    for(int i=1;i<=n;i++)y=y*a[i]%mod,pre[i]=pre[i-1]*a[i]%mod;
    // cout<<y<<' ';
    y=qmi(y,mod-2);
    ll x=1;
    for(ll i=2;i<=a[n];i++)
    {
        int now=lower_bound(a+1,a+n+1,i)-a;
        // cout<<now<<' ';
        x=(x+pre[now-1]*i%mod*check(qmi(i,n-now+1)-qmi(i-1,n-now+1))%mod)%mod;
    }
    cout<<x*y%mod;
    return 0;
}