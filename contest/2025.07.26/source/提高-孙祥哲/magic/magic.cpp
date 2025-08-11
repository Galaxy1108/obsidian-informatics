#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;

int n, q, a[200005], flag;
int ans[1005][1005], tm;
int t[200005];

void ds()
{
	for (int i = 1; i <= n; i++) ans[0][i] = a[i];
	for (tm = 1; ;tm++)
	{
		int l = 1, r = n/2+1, cur = 0;
		while (l <= n/2 && r <= n)
		{
			if (ans[tm-1][l] < ans[tm-1][r]) ans[tm][++cur] = ans[tm-1][l], l++;
			else ans[tm][++cur] = ans[tm-1][r], r++;
		}
		while (l <= n/2) ans[tm][++cur] = ans[tm-1][l], l++;
		while (r <= n) ans[tm][++cur] = ans[tm-1][r], r++;
		bool qwq = 0;
		for (int i = 1; i <= n; i++)
			if (ans[tm][i] != ans[tm-1][i]) {qwq=1;break;}
		
//		for (int i = 1; i <= n; i++) cout << ans[tm][i] << " "; 
//		cout << '\n';
		
		if (!qwq) {tm--;break;}
	}
		
}

int main()
{
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout); 
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n <= 1000)
	{
		ds();
//		cout << tm << '\n';
		while (q--)
		{
			int x, y;
			cin >> x >> y;
			x = min(x, tm);
//			cout << x << " " << y << '\n';
			cout << ans[x][y] << '\n';
		}
	}
	return 0;
} 
