#include <bits/stdc++.h>
using namespace std;
constexpr int N = 30;
int n, A[N], B[N];
int ans = INT_MAX;
void dfs(int step, int now, multiset <int> floor, int t) {
	if (step > n) {
		if (!floor.size()) {
			ans = min(ans, t);
			return ;
		}
		for (int x : floor) {
			int num = floor.count(x);
			floor.erase(x);
			dfs(step, x, floor, t + abs(now - x) + num);
			while (num--)
				floor.insert(x);
		}
		return ;
	}
	for (int x : floor) {
		int num = floor.count(x);
		floor.erase(x);
		dfs(step, x, floor, t + abs(now - x) + num);
		while (num--)
			floor.insert(x);
	}
	if (floor.size() < 4) {
		floor.insert(B[step]);
		dfs(step + 1, A[step], floor, t + abs(A[step] - B[step]) + 1);
	}
	return ;
}
int main(void) {
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> A[i] >> B[i];
	multiset <int> empty_multiset;
	dfs(1, 1, empty_multiset, 0);
	cout << ans;
	return 0;
}
