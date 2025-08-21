#include <iostream>
#include <cstring>
#include <queue>
#define int long long
#define mod 998244353
using namespace std;

int n, m, cnt;
int l[50], r[50], f[2][2000005];

bool check(int x)
{
	for (int i = 1; i <= m; i++)
		if (((x>>(i-1))&1) != ((x>>(m-i))&1))
			return 0;
	return 1;
}
//void dfs(int x, int sum)
//{
//	if (x > k)
//	{
//		for (int i = 1; i <= m; i++)
//			if (((sum>>(i-1))&1) != ((sum>>(m-i))&1))
//				return;
//		cnt++; return;
//	}
//	for (int i = l[x]; i <= r[x]; i++) dfs(x+1, sum^i);
//}

signed main()
{
	freopen("far.in", "r", stdin);
	freopen("far.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
//	for (int i = 1; i <= n; i++) k = i, cnt = 0, dfs(1, 0), cout << cnt << '\n';
	for (int i = l[1]; i <= r[1]; i++) f[1][i] = 1;
	for (int j = 0; j < (1ll<<m); j++) if (check(j)) cnt = (cnt+f[1][j])%mod;
	cout << cnt << '\n';
	for (int i = 2; i <= n; i++)
	{
		int p = i&1;
		for (int j = 0; j < (1ll<<m); j++) f[p][j] = 0;
		for (int j = 0; j < (1ll<<m); j++)
			for (int k = l[i]; k <= r[i]; k++)
				f[p][j^k] = (f[p][j^k]+f[!p][j])%mod;
		cnt = 0;
		for (int j = 0; j < (1ll<<m); j++) if (check(j)) cnt = (cnt+f[p][j])%mod;
//		for (int j = 0; j < (1ll<<m); j++) cout << f[!p][j] << " ";
//		cout << '\n';
		cout << cnt << '\n';
	}
	return 0;
}
