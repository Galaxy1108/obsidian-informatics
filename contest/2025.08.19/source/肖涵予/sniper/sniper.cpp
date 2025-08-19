#include <bits/stdc++.h>
using namespace std;
const int N = 8005;
const int val[22] = {0, 100, 100, 97, 96, 95, 90, 85, 80, 82, 78, 75, 70, 65, 55, 50, 15, 12, 10, 8, 5, 2};
int n;
int f[N][2];
struct Node {
	int w, u, t, p;
} a[N];
bool cmp(Node cmpx, Node cmpy) {
	return (cmpx.t < cmpy.t || (cmpx.t == cmpy.t && cmpx.p > cmpy.p));
}
bool check(int pre, int now) {
	if (a[pre].u == a[now].u) return (a[now].t - a[pre].t > 1);
	return ((a[now].t - a[pre].t - 1) * 2 >= abs(a[now].u - a[pre].u));
}
int main(void) {
	freopen("sniper.in", "r", stdin);
	freopen("sniper.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].w >> a[i].u >> a[i].t;
		if (a[i].w == 15) a[i].p = 1;
	}
	sort(a + 1, a + n + 1, cmp);
	f[1][1] = val[a[1].w];
	if (a[1].w == 15) f[1][0] = -1;
	for (int i = 2; i <= n; ++i) {
		if (a[i].w == 15) f[i][0] = -1;
		else f[i][0] = max(f[i-1][0], f[i-1][1]);
		f[i][1] = val[a[i].w];
		for (int j = i - 1; j >= 1; --j) { // 枚举上一个射杀的敌人。
			if (a[j].t < a[i].t && check(j, i))
				f[i][1] = max(f[i][1], f[j][1] + val[a[i].w]);
			if (a[j].w == 15) break;
		}
		if (a[i].w != 15) continue;
		int now = i + 1;
		while (now <= n && a[now].t == a[i].t) f[now][1] = -1, f[now++][0] = f[i][1];
		i = now - 1;
	}
	cout << max(f[n][0], f[n][1]);
	return 0;
}
