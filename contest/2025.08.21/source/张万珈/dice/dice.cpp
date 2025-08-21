#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define int long long
int pow(int a,int x)
{
    int ret = 1;
    while(x)
    {
        if(x&1) ret = (ret*a) % mod;
        x >>= 1;
        a = (a*a) % mod;
    }
    return ret;
}
int md(int x)
{
    x -= (x/mod)*mod;
    if(x < 0) x+=mod;
    return x;
}
long long a[5010];
long long sum = 1;
signed main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum = sum*a[i] % mod;
    }
    sort(a+1,a+n+1);
    int qwq = sum;
    int ans=0;
    for(int i=n;i>=1;i--)
    {
        sum = md(sum * pow(a[i],(long long)mod-2));
        long long now=pow(a[i],n-i+2);
        for(int j=a[i]-1;j>a[i-1];j--)
        {
            now = md(now-pow(j,n-i+1));
        }
        now = md(now-(a[i-1]+1)*(pow(a[i-1],n-i+1)));
        now = md(now*sum);
        ans = md(ans+now);
    }
    cout << md(ans*pow(qwq,(long long)mod-2));
    return 0;
}