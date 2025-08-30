#include <bits/stdc++.h>
using namespace std;

struct node{
    int x1,y1,x2,y2,id;
};
node q[100000];
bool cmp(node a,node b)
{
    if(a.x1 != b.x1) return a.x1 < b.x1;
    return a.y1 < b.y1;
}
int a[210][210];
long long dp[210][210];
long long ans[100010];

int main()
{
    freopen("glyph.in","r",stdin);
    freopen("glyph.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n,Q;
    cin >> n >> Q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >> a[i][j];
    for(int i=1;i<=Q;i++)
    {
        cin >> q[i].x1 >> q[i].x2 >> q[i].y1 >> q[i].y2;
        q[i].id = i;
    }
    sort(q+1,q+Q+1,cmp);
    for(int i=1;i<=Q;i++)
    {
        if(q[i].x1 == q[i-1].x1 && q[i].y1 == q[i-1].y1)
        {
            ans[q[i].id] = dp[q[i].x2 - q[i].x1 + 1][q[i].y2 - q[i].y1 + 1];
            continue;
        }
        int x1 = q[i].x1,y1 = q[i].y1,x2 = q[i].x2,y2 = q[i].y2;

        for(int i=x1;i<=n;i++)
            dp[i-x1+1][1] = dp[i-x1][1] + a[i][y1];
        for(int i=y1;i<=n;i++)
            dp[1][i-y1+1] = dp[1][i-y1] + a[x1][i];
        
        for(int i=x1+1;i<=n;i++)
        {
            for(int j=y1+1;j<=n;j++)
            {
                dp[i-x1+1][j-y1+1] = min(dp[i-x1][j-y1+1],dp[i-x1+1][j-y1]) + a[i][j];
            }
        }
        ans[q[i].id] = dp[x2-x1+1][y2-y1+1];
    }
    for(int i=1;i<=Q;i++)
    {
        cout << ans[i] << "\n";
    }
    return 0;
}