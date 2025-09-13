#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100010];

void solve()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i=2;i<=n;i++)
    {
        int now = i;
        while(a[now] > a[now-1])
        {
            swap(a[now],a[now-1]);
            a[--now]--;
            a[now+1]++;
            if(a[now] < a[now+1])
            {
                cout << -1 << "\n";
                return;
            }
            ans = max(ans,a[now]+a[now+1]);
        }
    }
    cout << ans << endl;
}
int main()
{
    freopen("jyrg.in","r",stdin);
    freopen("jyrg.out","w",stdout);
    int T;
    cin >> T;
    a[0] = LONG_LONG_MAX;
    while(T--)
    {
        solve();
    }
}