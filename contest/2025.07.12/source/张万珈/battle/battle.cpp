#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10010][3],ans=-1;
int check(int x,int y,int z)
{
    if(a[x][0] <= a[y][0] || a[x][0] <= a[z][0]) return -1;
    if(a[y][1] <= a[x][1] || a[y][1] <= a[z][1]) return -1;
    if(a[z][2] <= a[x][2] || a[z][2] <= a[y][2]) return -1;
    return a[x][0] + a[y][1] + a[z][2];
}
signed main()
{
    freopen("battle.in","r",stdin);
    freopen("battle.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for(int a=1;a<=n;a++)
    {
        for(int b=1;b<=n;b++)
        {
            for(int c=1;c<=n;c++)
            {
                if(a==b || b == c || c == a) continue;
                ans = max(ans,check(a,b,c));
            };
        }
    }
    cout << ans;
    return 0;
}