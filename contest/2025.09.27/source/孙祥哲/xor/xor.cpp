#include <bits/stdc++.h>
#define ll long long
#define min(x,y) ((x)>(y)?(y):(x))
#define max(x,y) ((x)<(y)?(y):(x))
using namespace std;

int n, k, m;
ll ans;
int a[500005];

signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		ans++;
		int t1 = a[i], t2 = a[i];
		for (int j = i+1; j <= n; j++)
		{
			t1 ^= a[j], t2 = max(t2, a[j]);
			ans += t1 <= t2;
		}
	}
	cout << ans;
	return 0;
}
/*
5
1 2 3 4 5
*/
