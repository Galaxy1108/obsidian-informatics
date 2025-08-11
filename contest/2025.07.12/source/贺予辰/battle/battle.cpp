#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("battle.in", "r", stdin);
	freopen("battle.out", "w", stdout);
	int n, x[150005], y[150005], z[150005];
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i] >> z[i];
	int ans = -1;
	if (n <= 300) 
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				if (x[j] < x[i] && x[k] < x[i] && y[i] < y[j] && y[k] < y[j] && z[i] < z[k] && z[j] < z[k])
					ans = max(ans, x[i] + y[j] + z[k]);
	cout << ans << endl;
	return 0;
}
