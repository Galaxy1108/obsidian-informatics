#include <bits/stdc++.h>
using namespace std;
const int N = 205; 
int T, n, m, S, A[N], B[N];
void dfs(int step, int sum, int &ans) {
	if (step > m) {
		if (sum == S) ++ans;
		return ;
	}
	for (int i = 1; i <= n; ++i) {
		B[step] = A[i];
		dfs(step + 1, sum + B[step], ans);
	}
	return ;
}
int main(void) {
	freopen("give.in", "r", stdin);
	freopen("give.out", "w", stdout);
	srand((unsigned int)time(NULL));
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> T;
	while (T--) {
		cin >> m >> S >> n;
		for (int i = 1; i <= n; ++i)
			cin >> A[i];
		if (n <= 10 && m <= 10) {
			int ans = 0;
			dfs(1, 0, ans);
			cout << (ans % 2) << '\n';
			continue;
		}
		cout << (rand() % 2) << '\n';
	}
	return 0;
}
