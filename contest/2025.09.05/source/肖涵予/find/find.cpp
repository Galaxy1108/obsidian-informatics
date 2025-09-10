#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1005;
int n, k, num[N][N];
priority_queue <int> pq;
int ans;
int f(int x) {
	int res = 1;
	while (x) {
		res *= (x % 10);
		x /= 10;
	}
	return res;
}
int main(void) {
	freopen("find.in", "r", stdin);
	freopen("find.out", "w", stdout);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			++num[f(i)][f(j)];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			pq.push(num[i][j]);
	while (k--) {
		ans += pq.top();
		pq.pop();
	}
	printf("%d", ans);
	return 0;
}
