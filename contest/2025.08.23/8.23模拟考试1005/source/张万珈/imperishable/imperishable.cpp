#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
#define endl "\n"
int num;
int n,q;
int a[200010],mx;
long long l[200010];
void solve()
{
    int sum = 0,x;
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        sum += a[i];
        x = i;
        if(sum >= mx) break;
    }
    for(int i=x;i>=1;i--)
    {
        if(sum - a[i] >= mx) sum -= a[i];
        else 
        {
            ans = (ans+l[i]);
            if(ans >= mod)ans -= mod;
        }
    }
    cout << ans << endl;
    return ;
}
signed main()
{
    freopen("imperishable.in","r",stdin);
    freopen("imperishable.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin >> num >> n;
    l[0] = 1;
    for(int i=1;i<=n;i++)
    {
        l[i] = l[i-1] + l[i-1];
        if(l[i] >= mod) l[i] -= mod;
        cin >> a[i];
        mx = (a[i]>mx)?a[i]:mx;
    }
    solve();
    cin >> q;
    for(int i=1,id,x;i<=q;i++)
    {
        cin >> id >> x;
        a[id] = x;
        mx = 0;
        for(int j=1;j<=n;j++)
        {
            mx = (a[j]>mx)?a[j]:mx;
        }
        solve();
    }
    return 0;
}
