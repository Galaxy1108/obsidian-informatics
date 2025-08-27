#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
int T;
long long f[100010],inv[100010];

long long qmi(long long a,long long x)
{
    long long ret=1;
    while(x)
    {
        if(x&1) ret = (ret*a) % mod;
        a = (a*a) % mod;
        x>>=1;
    }
    return ret;
}
void init()
{
    f[0] = 1;
    for(int i=1;i<=50000;i++)
    {
        f[i] = f[i-1] * i % mod;
    }
    inv[50000] = qmi(f[50000],mod-2);
    for(int i=49999;i>=1;i--)
    {
        inv[i] = (inv[i+1] * (i+1)) % mod;
    }
    inv[0] = 1;
    return ;
}
long long C(int n,int m)
{
    return (f[n] * inv[m] % mod) * inv[n-m] % mod;
}
void solve()
{
    long long n,x;
    cin >> n >> x;
    if(n == 1)
    {
        cout << 1;
        return;
    }
    if(x==0)
    {
        cout << n << ' ';
        for(int i=2;i<=n;i++)
        {
            cout << 0 << ' ';
        }
    }
    else if(46 <= T && T<=49)
    {
        if(x == 1)
        {
            cout << n << ' ' << C(n,2) << ' ';
            for(int i=3;i<=n;i++)
            {
                cout << 0 << ' ';
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                cout << C(n,i) << ' ';
            }
        }
    }
}

int main()
{
    freopen("youup.in","r",stdin);
    freopen("youup.out","w",stdout);
    cin >> T;
    init();
    solve();
}