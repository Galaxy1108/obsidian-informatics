#include <bits/stdc++.h>
using namespace std;

int a[100010],s[100010];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s[i] = s[i-1] ^ a[i];
    }
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        int mx = 0;
        for(int j=i;j<=n;j++)
        {
            mx = max(mx,a[j]);
            if((s[j] ^ s[i-1]) <= mx) ans++;
        }
    }
    cout << ans;
}