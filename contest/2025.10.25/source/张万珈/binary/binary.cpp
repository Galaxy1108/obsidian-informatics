#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N],s[N],r1[N],r2[N],l1[N],l2[N];
int n;
void init()
{
    int lst1=n+1,lst2=n+1,lst0=n+1,lst3=n+1;
    for(int i=n;i>=1;i--)
    {
        if(a[i] == 1) lst3 = lst0,lst0 = i;
        if(a[i] == 0) lst2 = lst1,lst1 = i;
        r1[i] = lst1,r2[i] = lst2;l1[i] = lst0;l2[i] = lst3;
    }
}
int main()
{
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    init();
    int m;
    cin >> m;
    for(int _=1;_<=m;_++)
    {
        int tp,x,y;
        cin >> tp;
        if(tp == 1)
        {
            cin >> x;
            a[x] ^= 1;
            init();
        }
        else
        {
            cin >> x >> y;
            int ans = 0;
            for(int i=x;i<=y;i++)
            {
                if(r1[i] > y) ans += ((y-i+1)/2);
                else if(r2[i] > y) ans += (y-i)/2 + (((r1[i]-i)&1)?0:1);
                else 
                {
                    ans += ((r2[i]-i-1)/2) + (((r1[i]-i)&1)?0:1) + (y - r2[i] + 1);
                    if(l1[i] <= y && l2[i] > r2[i])
                    {
                        ans -= min(l2[i]-1,y) - max(l1[i],r2[i]) + 1;
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}