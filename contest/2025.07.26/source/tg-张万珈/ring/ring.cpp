#include <bits/stdc++.h>
using namespace std;
long long a[10010],m[10010];
struct node{
    int x1,x2;
} g[5010][5010];
long long dp[10010];
int n;
long long ans = 0x3f3f3f3f3f3f;
void solve(int start)
{
    for(int i=m[2];i<=m[n];i++)
    {
    	dp[i] = 0x3f3f3f3f3f3f;
	}
    dp[start] = (a[start] * a[start]) + (2e6 - a[start]) * (2e6 - a[start]);
    int len = 0;
    for(int i=start+1;i<=m[2];i++)
    {
        len++;
        int x1 = g[i][len].x1,x2 = g[i][len].x2;
        dp[i] = dp[i-1] - 2*(x2-a[i])*(a[i]-x1);
    }
    for(int i=3;i<=n;i++)
    {
        for(int start = m[i-2]+1;start<=m[i-1];start++)
        {
            len = 0;
            long long now = dp[start-1] + (a[start] * a[start]) + (2e6 - a[start]) * (2e6 - a[start]);
            for(int j=start+1;j<=m[i-1];j++)
            {
                len++;
                int x1 = g[j][len].x1,x2 = g[j][len].x2;
                now -= 2*(x2-a[j])*(a[j]-x1);
            }
            for(int r = m[i-1]+1;r<=m[i];r++)
            {
                len++;
                int x1 = g[r][len].x1,x2 = g[r][len].x2;
                now -= 2*(x2-a[r])*(a[r]-x1);
                dp[r] = min(dp[r],now);
            }
        }
    }
    for(int start = m[n-1]+1;start<=m[n];start++)
    {
        len = 0;
        long long now = dp[start-1] + (a[start] * a[start]) + (2e6 - a[start]) * (2e6 - a[start]);
        for(int j=start+1;j<=m[n]+start-1;j++)
        {
            len++;
            int x1 = g[j][len].x1,x2 = g[j][len].x2;
            now -= 2*(x2-a[j])*(a[j]-x1);
            while(j == m[n]+start-1)
            {
                ans = min(ans,now);
                break;
            }
        }
    }
}
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> m[i];
        m[i] += m[i-1];
//        cout << m[i] << ' ' << m[i-1] << endl;
        for(int j=m[i-1]+1;j<=m[i];j++)
        {
            cin >> a[j];
        }
//        cout << m[i] << ' ' << m[i-1] << endl;
    }
    m[n+1] = m[n] + m[1];
    for(int i=m[n]+1;i<=m[n+1];i++)
    {
        a[i] = a[i-m[n]];
    }
//    cout << "OK";
    for(int i=2;i<=n;i++)
    {
        for(int now = m[i]+1;now <= m[i+1];now++)
        {
            int mx=200000,mn=0;
            node qwq;
            for(int lst = now-1;lst > m[i-1];lst--)
            {
                if(a[lst] < mx && a[lst] > a[now]) mx = a[lst],qwq.x2 = mx;
                if(a[lst]> mn && a[lst] < a[now]) mn = a[lst],qwq.x1 = mn;
                g[now][now-lst] = qwq;
            }
        }
    }
    for(int i=1;i<=m[1];i++)
    {
        solve(i);
//        cout << ans << endl;
    }
    cout << ans;
    return 0;
}
