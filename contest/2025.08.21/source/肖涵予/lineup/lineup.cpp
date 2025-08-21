#include <bits/stdc++.h>
#define mk std::make_pair
typedef std::pair <int, int> pii;
constexpr int N = 55;
int n, h[N];
int t[N], id[N], pos[N], to[N], from[N];
bool vis[N];
int ans;
namespace I {
	void swap(int& x, int y) {
		std::swap(pos[id[x]], pos[id[y]]);
		std::swap(id[x], id[y]);
		x = y;
		return ;
	}
}
int main(void) {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	std::cin.tie(0) -> std::ios::sync_with_stdio(false);
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		std::cin >> h[i];
		id[i] = i, pos[i] = i;
	}
	memcpy(t, h, sizeof h);
	std::sort(t, t + n);
	for (int i = 0; i < n; ++i) if (h[i] == t[i]) to[i] = from[i] = i, vis[i] = true;
	for (int i = 0; i < n; ++i) if (!to[i]) for (int j = 0; j < n; ++j) if (!vis[j] && h[i] == t[j]) {
		vis[j] = true, to[i] = j, from[j] = i;
		break;
	}
	std::priority_queue <pii> pq;
	for (int i = 0; i < n; ++i) pq.push(mk(abs(to[i] - i), i));
	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();
		if (pos[u] == to[u]) continue;
		int now = pos[u], st = to[u];
		while (now != st) {
			int v = from[now];
			if ((now - pos[v]) * (st - pos[v]) > 0) {
				ans += (abs(now - st) << 1);
				I::swap(now, st);
				break;
			}
			ans += (abs(now - pos[v]) << 1);
			I::swap(now, pos[v]);
		}
	}
	std::cout << ans;
	return 0;
}
