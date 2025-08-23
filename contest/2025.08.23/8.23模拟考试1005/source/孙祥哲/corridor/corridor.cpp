#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define mod 998244353
using namespace std;

int tp, n, m, k, q;
int a[1005][1005];

signed main()
{
	freopen("corridor.in", "r", stdin);
	freopen("corridor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> tp >> n >> m >> k;
	for (int i = 1, x, y; i <= k; i++)
		cin >> x >> y, a[x][y] = 1;
	cin >> q;
	while (q--)
	{
		int op, x, y, t, fc;
		cin >> op >> x >> y;
		if (op == 1) a[x][y] = 1;
		else
		{
			cin >> t;
			if (x == 0) x = 1, fc = 1;
			else y = 1, fc = 0;
			while (x <= n && y <= m && t)
			{
				if (a[x][y]) fc = !fc, t--;
				if (!t) break;
				if (fc) x++;
				else y++;
			}
			cout << x << " " << y << '\n';
		}
	}
	return 0;
} 
