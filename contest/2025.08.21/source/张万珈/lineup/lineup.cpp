#include <bits/stdc++.h>
using namespace std;
struct node{
    int id,x;
};
node a[51];
bool cmp(node a,node b)
{
    return a.x < b.x;
}
int main()
{
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    int n;
    cin >> n;
    long long ans = 0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].x;
        a[i].id = i;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        ans += abs(a[i].id - i);
    }
    cout << ans;
    return 0;
}