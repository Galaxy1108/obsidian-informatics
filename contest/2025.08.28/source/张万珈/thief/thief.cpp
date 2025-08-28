#include <bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)

int a[500010];
dsgf 
int main()
{
    freopen("thief.in","r",stdin);
    freopen("thief.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        // cout << a[i] << "\n";
        // build(rt[i],0,N,a[i],rt[i-1]);
    }
    for(int i=1,l,r,x;i<=m;i++)
    {
        cin >> l >> r >> x;
        for(int now=l;now<=r;now++)
        {
            if(a[now] < x) x--;
            else if(a[now] > x) x++;
        }
        cout << x << endl;
        // cout << ans << endl;
    }
}
