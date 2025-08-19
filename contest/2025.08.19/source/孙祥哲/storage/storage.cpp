#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, x[1000005], p[1000005], c[10000005];
int f[1000005];

signed main()
{
	freopen("storage.in", "r", stdin);
	freopen("storage.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	memset(f, 0x3f, sizeof(f));
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> p[i] >> c[i];
	f[n] = c[n];
	for (int i = n-1; i >= 1; i--)
	{
		int minn = f[i+1];
		for (int j = i+1; j <= n; j++)
		{
			minn = min(minn, f[j]);
			f[j] += x[j]*p[i]-x[i]*p[i];
		}
		f[i] = minn + c[i];
	}
	int ans = f[1];
	for (int i = 2; i <= n; i++) ans = min(ans, f[i]);
	cout << ans;
	return 0;
} 
