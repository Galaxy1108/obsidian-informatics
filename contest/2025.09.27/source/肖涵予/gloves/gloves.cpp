#include <bits/stdc++.h>
using namespace std;
constexpr int N = 2e5;
int n, m;
bool check(int d, vector <int>& l, vector <int>& r) {
	int now = -1;
	for (int i = 0; i < n; ++i) {
		++now;
		while (now < m && r[now] < l[i] - d)
			++now;
		if (now >= m || r[now] > l[i] + d)
			return false;
	}
	return true;
}
int main(void) {
	freopen("gloves.in", "r", stdin), freopen("gloves.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> m;
	vector <int> l(n), r(m);
	for (int& x : l)
		cin >> x;
	for (int& x : r)
		cin >> x;
	if (n > m)
		swap(l, r), swap(n, m);
	sort(l.begin(), l.end()), sort(r.begin(), r.end());
	int L = 0, R = 1e9, res = 0;
	while (L <= R) {
		int mid = (L + R) >> 1;
		if (check(mid, l, r))
			res = mid, R = mid - 1;
		else
			L = mid + 1;
	}
	cout << res;
	return 0;
}
