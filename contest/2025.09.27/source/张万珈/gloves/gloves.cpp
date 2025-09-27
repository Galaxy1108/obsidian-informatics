#include <bits/stdc++.h>
using namespace std;
int a[100010],b[100010];
int n,m;
int mx;

inline bool check(int k)
{
    int now = 1;
    for(int i=1;i<=n;i++)
    {
        if(abs(a[i] - b[now]) <= k) {now++;if(now > m) return 1;}
    }
    return 0;
}

int main()
{
    freopen("gloves.in","r",stdin);
    freopen("gloves.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        mx = max(mx,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin >> b[i];
        mx = max(mx,b[i]);
    }
    if(n < m)
    {
        swap(n,m);
        swap(a,b);
    }
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    int l=0,r=mx+1,ans=-1;
    while(l <= r)
    {
        int mid = (l+r)>>1;
        if(check(mid))
        {
            ans = mid;
            r = mid-1;
        }
        else
        {
            l = mid+1;
        }
    }
    cout << ans;
}