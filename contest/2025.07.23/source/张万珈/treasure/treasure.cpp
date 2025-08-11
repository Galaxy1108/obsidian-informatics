#include <bits/stdc++.h>
using namespace std;
int n,k;
int a[100010],ans;
int vis[110][110];
void solve()
{
//	for(int i=1;i<=k;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout << vis[i][j] << ' ';
//		}
//		cout << endl;
//	}
    for(int i=1;i<=n;i++)
    {
        int sum = 0;
        for(int j=i;j>=max(1,i-k+1);j--)
        {
            for(int y = k+j-i;y>=1;y--)
            {
                sum += vis[y][j];
            }
        }
//        cout << sum << ' ';
        if(sum != a[i]) {return;}
    }
    ans++;
    return;
}
void dfs(int x,int y)
{
	//cout << x << ' ' << y << endl;;
    if(x == k+1)
    {
        solve();
        return;
    }
    if(y >= n)
    {
        vis[x][y] = 1;
        dfs(x+1,1);
        vis[x][y] = 0;
        dfs(x+1,1);
        return;
    }
    vis[x][y] = 1;
    dfs(x,y+1);
    vis[x][y] = 0;
    dfs(x,y+1);
    return;
}
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    dfs(1,1);
    cout << ans;
}
