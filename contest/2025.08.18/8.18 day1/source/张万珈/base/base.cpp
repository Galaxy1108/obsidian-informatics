#include <bits/stdc++.h>
using namespace std;
int a1[2010],a2[2010];
long long s1[2010],s2[2010],mx1[2010],mx2[2010];
int main()
{
    freopen("base.in","r",stdin);
    freopen("base.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a1[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a2[i];
    }
    for(int i=1;i<=n;i++)
    {
        mx1[i] = a1[i] + a2[i];
        if(mx1[i-1] > 0) mx1[i] += mx1[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        s1[i] = s1[i-1] + a1[i];
    }
    for(int i=1;i<=n;i++)
    {
        s2[i] = s2[i-1] + a2[i];
    }
    for(int i=2;i<=n;i++)
    {
        mx2[i] = -1e18;
        for(int j=1;j<=i-1;j++)
        {
            mx2[i] = max(mx2[i],s2[i] - s2[j] + mx1[j]);
            // cout << i << ' ' << j << ' ' << s2[i] << ' ' << s2[j] << ' ' << mx1[j] << endl;
        }
        // cout << mx2[i] << '\n';
    }
    // cout << endl;
    long long ans=-1e18;
    for(int i=3;i<=n;i++)
    {
        for(int j=2;j<=i-1;j++)
        {
            ans = max(ans,s1[i] + s2[i] - s1[j] - s2[j] + mx2[j]);
            // cout << i << ' ' << j << ' ' << ans << endl;
        }
    }
    cout << ans;
}