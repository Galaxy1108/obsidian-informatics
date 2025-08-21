#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
const int MOD=1000000007;
typedef long long ll;
int a[N],t[N];
ll mypow(ll a,ll b)
{
    if(b==0)return 1;
    ll mi=mypow(a,b>>1);
    mi=mi*mi%MOD;
    if(b&1)mi=mi*a%MOD;
    return mi;
}
int main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,flag=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1&&a[i]!=a[i-1])flag=0;
    }
    if(flag)
    {
        ll ans=mypow(a[n],n+1);
        for(int i=1;i<a[1];i++)ans=(ans-mypow(i,n)+MOD)%MOD;
        cout<<ans*mypow(mypow(a[1],n),MOD-2)%MOD<<'\n';
        return 0;
    }
    for(int i=1;i<=n;i++)t[a[i]]++;
    ll ans=0,cnt=n,sum=1;
    for(int i=1;i<=1000000;i++)
    {
        ans=(ans+i*(mypow(i,cnt)-mypow(i-1,cnt))%MOD*sum%MOD)%MOD;
        //cout<<ans<<' '<<sum<<' '<<cnt<<'\n';
        sum=sum*mypow(i,t[i])%MOD;
        cnt-=t[i];
    }
    //cout<<ans<<'\n';
    cout<<ans*mypow(sum,MOD-2)%MOD<<'\n';
    return 0;
}
