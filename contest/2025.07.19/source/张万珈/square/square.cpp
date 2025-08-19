#include <bits/stdc++.h>
using namespace std;
#define int long long
const int prime[11] = {2,3,5,7,11,13,17,19,23,29,31},mod = 1e9+7;
const int p[71] = {0,0,1,2,0,4,3,8,1,0,5,16,2,32,9,6,0,64,1,128,4,10,17,256,3,0,33,2,8,512,7,1024,1,18,65,12,0,0,129,34,5,0,11,0,16,4,257,0,2,0,1,66,32,0,3,20,9,130,513,0,6,0,1025,8,0,36,19,0,64,258,13};
int cnt[70];
bool vis[70];
long long a[100010],dp[2][2100];
long long fac[100010],inv[100010];
long long times(long long a,long long b)
{
    long long r = 0;
    while(b)
    {
        if(b&1) r = (r+a)%mod;
        a = (a+a)%mod;
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
long long sum(long long x)
{
    long long r = 0,now=2;
    while(x >= now)
    {
        r = (r+C(x,now)) % mod;
        now += 2;
    }
    return r;
}
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
signed main()
{
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    vis[37] = 1,vis[41]=1,vis[43]=1,vis[47]=1,vis[53]=1,vis[59]=1,vis[61]=1,vis[67]=1;
    int t=0;
    fac[0] = 1;
    for(long long i=1;i<=n;i++)
    {
        fac[i] = (fac[i-1]*i) % mod;
    }
    inv[n] = qmi(fac[n],mod-2);
    for(long long i=n-1;i>=1;i--)
    {
        inv[i] = (inv[i+1]*(i+1))% mod;
    }
    inv[0] = 1;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(vis[a[i]])
        {
            cnt[a[i]]++;
            continue;
        }
        t^=1;
        for(int x=0;x<2048;x++)
        {
            dp[t][x] = dp[t^1][x];
            dp[t][x] = (dp[t][x] + dp[t^1][x^p[a[i]]]) % mod;
        }
        dp[t][p[a[i]]] = (dp[t][p[a[i]]] + 1) % mod;
    }
    long long fans = dp[t][0];
    if(cnt[37]>1) {fans = (fans + ((times(fans,sum(cnt[37])))%mod)) % mod;fans = (fans+sum(cnt[37])) % mod;}
    if(cnt[41]>1) {fans = (fans + ((times(fans,sum(cnt[41])))%mod)) % mod;fans = (fans+sum(cnt[41])) % mod;}
    if(cnt[43]>1) {fans = (fans + ((times(fans,sum(cnt[43])))%mod)) % mod;fans = (fans+sum(cnt[43])) % mod;}
    if(cnt[47]>1) {fans = (fans + ((times(fans,sum(cnt[47])))%mod)) % mod;fans = (fans+sum(cnt[47])) % mod;}
    if(cnt[53]>1) {fans = (fans + ((times(fans,sum(cnt[53])))%mod)) % mod;fans = (fans+sum(cnt[53])) % mod;}
    if(cnt[59]>1) {fans = (fans + ((times(fans,sum(cnt[59])))%mod)) % mod;fans = (fans+sum(cnt[59])) % mod;}
    if(cnt[61]>1) {fans = (fans + ((times(fans,sum(cnt[61])))%mod)) % mod;fans = (fans+sum(cnt[61])) % mod;}
    if(cnt[67]>1) {fans = (fans + ((times(fans,sum(cnt[67])))%mod)) % mod;fans = (fans+sum(cnt[67])) % mod;}
    cout << fans;
    return 0;
}
