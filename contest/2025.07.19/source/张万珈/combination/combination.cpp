#include <bits/stdc++.h>
using namespace std;
int n,x,mod,m;
int a[100010];
long long fac[100010],inv[100010];
long long qmi(long long aa,long long bb)
{
    long long r=1;
    long long a=aa,b=bb;
    while(b)
    {
        if(b&1) r = (r*a) % mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return r;
}
long long C(long long n,long long m)
{
    long long r=1;
    r = (r*fac[n]) % mod;
    r = (r*inv[m]) % mod;
    r = (r*inv[n-m]) % mod;
    return r;
}
long long f(long long x)
{
    long long r=0,t=1;
    for(int i=0;i<=m;i++)
    {
        r = (r+t*a[i]) % mod;
        t = (t*x) % mod;
    }
    return r;
}
void exgcd(int a,long long &x,int b,long long &y)
{
	//cout << x << ' ' << y;
    if(b==0) {x=1,y=0;return;}
    exgcd(b,y,a%b,x);
    y -= (a/b) * x;
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
	freopen("combination.in","r",stdin);
    freopen("combination.out","w",stdout);
    cin >> n >> x >> mod >> m;
    for(int i=0;i<=m;i++)
    {
        cin >> a[i];
    }
    fac[0] = 1;
    for(long long i=1;i<=n;i++)
    {
        fac[i] = (fac[i-1]*i) % mod;
    }
    long long tot,qwq;
    exgcd(fac[n],inv[n],mod,tot);
    for(long long i=n-1;i>=1;i--)
    {
        inv[i] = (inv[i+1]*(i+1))% mod;
    }
    inv[0] = 1;
    long long ans = 0;
    for(int k=0;k<=n;k++)
    {
        long long now=1;
        now = C(n,k);
        now = (now*qmi(x,k)) % mod;
        now = (now*f(k)) % mod;
        ans = (ans+now) % mod;
    }
    cout << ans;
    return 0;
}
