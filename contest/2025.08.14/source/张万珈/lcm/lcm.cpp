#include <bits/stdc++.h>
using namespace std;
__int128_t f[110],e[110];
__int128_t gcd(__int128_t a,__int128_t b)
{
    if(b == 0) return a;
    else return gcd(b,a%b);
}
void print(__int128_t x)
{
    int ret[110],tot=0;
    while(x)
    {
        ret[++tot] = x%10;
        x/=10;
    }
    for(int i=tot;i>=1;i--)
    {
        cout << ret[i];
    }
    return;
}
void solve()
{
    int n,p;
    cin >> n >> p;
    for(int i=2;i<=100;i++)
    {
        e[i] = e[i-1] + 2*f[i-1];
        f[i] = f[i-1] + e[i-1];
        // cout << i << ' ';
        // print(f[i]);
        // cout << endl;
    }
    __int128_t ans=1;
    __int128_t fans=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=i-1;j>=2;j--)
        {
            f[i] /= gcd(f[i],f[j]);
        }
        
        ans = (ans*(f[i]%p)) % p;
        // if(i>=90) print(ans);
        fans = (fans+((ans*i)%p)%p)%p;
        if(fans < 0) fans+=p;
    }
    print(fans);
    printf("\n");
}
int main()
{
    freopen("lcm.in","r",stdin);
    freopen("lcm.out","w",stdout);
    f[1] = 1,e[1] = 1;
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
}