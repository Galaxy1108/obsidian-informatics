#include <bits/stdc++.h>
#define ll long long
#define lll __int128
#define mod 998244353
using namespace std;

int T, n, m;
int a[300005], cur, ans[300005];
int dis[25][25];

ll qp(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b&1) res = res*a%mod;
		b >>= 1, a = a*a%mod;
	} 
	return res;
}

int main()
{
	freopen("youup.in", "r", stdin);
	freopen("youup.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T >> n >> m;
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1, x, y; i < n; i++)
		cin >> x >> y, dis[x][y] = dis[y][x] = 1;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][k]+dis[k][j], dis[i][j]);
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			printf("dis[%d][%d]=%d\n", i, j, dis[i][j]);
	for (int i = 1; i < (1<<n); i++)
	{
		cur = 0;
		for (int j = 0; j < n; j++) if ((i>>j)&1) a[++cur] = j+1;
		int maxn = 0;
		for (int j = 1; j <= cur; j++)
			for (int k = j+1; k <= cur; k++)
				maxn = max(maxn, dis[a[j]][a[k]]);
		if (maxn <= m) ans[cur]++;
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	return 0;
} 
