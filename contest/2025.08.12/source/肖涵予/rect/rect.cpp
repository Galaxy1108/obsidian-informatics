#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m;
char c[N][N];
int ans[N][N], cnt; 
int main(void) {
	freopen("rect.in", "r", stdin);
	freopen("rect.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> c[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			if (c[i][j] == 'B') continue;
			if (j == 1 || c[i][j-1] == 'B') ans[i][j] = ++cnt;
			else ans[i][j] = ans[i][j-1];
		}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
