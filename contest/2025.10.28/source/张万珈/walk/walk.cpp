#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
ll a[N];
ll s[N],s1[N],l[N],r[N],mn[N];
int main()
{
    freopen("walk.in","r",stdin);
    freopen("walk.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        s[i] = s[i-1] + a[i];
        s1[i] = s1[i-1] + 1 - (a[i]&1);
    }
    for(int i=1;i<=n;i++)
    {
        l[i] = min(s[i],l[i-1] + (a[i]&1) + ((a[i]==0)?2:0));
        mn[i] = min(mn[i-1],l[i]-s1[i]);
    }
    for(int i=n;i>=1;i--)
    {
        r[i] = min(s[n] - s[i-1],r[i+1] + (a[i]&1) + ((a[i]==0)?2:0));
    }
    ll ans = 1e18;
    for(int i=1;i<=n;i++)
    {
        ans = min(ans,mn[i-1]+r[i+1]+s1[i]);
    }
    cout << ans;
}