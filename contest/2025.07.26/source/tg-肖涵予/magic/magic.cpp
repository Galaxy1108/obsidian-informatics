#include <bits/stdc++.h>
using namespace std;
const int N = 4005;
int n, q, a[N];
int ans[N][N];
int read(void) {
	int x = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x;
}
void write(int x) {
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + 48);
	return ;
}
void Solve(void) {
	for (int step = 1; step <= n; ++step) {
		int pre = step - 1;
		int l = 1, mid = (n >> 1), r = mid + 1, cnt = 0;
		while (l <= mid && r <= n) {
			if (ans[pre][l] < ans[pre][r]) {
				ans[step][++cnt] = ans[pre][l];
				++l;
			}
			else {
				ans[step][++cnt] = ans[pre][r];
				++r;
			}
		}
		while (l <= mid) {
			ans[step][++cnt] = ans[pre][l];
			++l;
		}
		while (r <= n) {
			ans[step][++cnt] = ans[pre][r];
			++r;
		}
	}
	int t, x;
	while (q--) {
		t = read(), x = read();
		write(ans[min(t, n)][x]);
		putchar('\n');
	}
	return ;
}
int main(void) {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	n = read(), q = read();
	for (int i = 1; i <= n; ++i) {
		a[i] = read();
		ans[0][i] = a[i];
	}
	if (n <= 5000) {
		Solve();
		return 0;
	}
	vector <int> vec, pre, now;
	int t, x;
	while (q--) {
		t = read(), x = read();
		vec.emplace_back(x);
	}
	int step = 0;
	for (int i = 1; i <= n; ++i)
		now.emplace_back(a[i]);
	while (step < min(t, n)) {
		pre = now;
		now.clear();
		int l = 0, r = (n >> 1), mid = r - 1;
		while (l <= mid && r < n) {
			if (pre[l] < pre[r]) {
				now.emplace_back(pre[l]);
				++l;
			}
			else {
				now.emplace_back(pre[r]);
				++r;
			}
		}
		while (l <= mid) {
			now.emplace_back(pre[l]);
			++l;
		}
		while (r < n) {
			now.emplace_back(pre[r]);
			++r;
		}
		++step;
	}
	for (int x : vec) {
		write(now[x-1]);
		putchar('\n');
	}
	return 0;
}
