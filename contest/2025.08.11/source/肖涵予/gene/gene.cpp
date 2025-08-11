#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int n, lft, rght, s[N];
int pos[N], pre[N], nxt[N];
int m, numl, maxn[N];
struct Node {
	int idx, val;
	Node () {}
	Node (int idx, int val) : idx(idx), val(val) {}
} a[N];
int ans = INT_MAX;
int read(void) {
	int x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) {
		x = (x << 3) + (x << 1) + ch - 48;
		ch = getchar();
	}
	return x;
}
int main(void) {
	freopen("gene.in", "r", stdin);
	freopen("gene.out", "w", stdout); 
	n = read(), lft = read(), rght = read();
	for (int i = 1; i <= n; ++i) s[i] = read();
	for (int i = 1; i <= n; ++i) pre[i] = pos[s[i]], pos[s[i]] = i;
	for (int i = 0; i < N; ++i) pos[i] = n + 1;
	for (int i = n; i >= 1; --i) nxt[i] = pos[s[i]], pos[s[i]] = i;
	for (int i = 1; i < lft; ++i) if (!pre[i]) a[++m] = Node(i, s[i]), ++numl;
	for (int i = rght + 1; i <= n; ++i) if (nxt[i] > n) a[++m] = Node(i, s[i]);
	for (int i = numl; i >= 1; --i) maxn[i] = max(maxn[i+1], nxt[a[i].idx]);
	for (int r = numl + 1; r <= m; ++r) {
		int realr = a[r].idx;
		int L = 1, R = numl, boundl = -1;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (a[mid].idx > pre[realr]) {
				boundl = mid;
				R = mid - 1;
			}
			else L = mid + 1;
		}
		if (boundl == -1) continue;
		L = boundl, R = numl;
		int res = -1;
		while (L <= R) {
			int mid = (L + R) >> 1;
			if (maxn[mid] > realr) {
				res = a[mid].idx;
				L = mid + 1;
			}
			else R = mid - 1;
		}
		if (res != -1) ans = min(ans, realr - res + 1);
	}
	if (ans == INT_MAX) printf("-1");
	else printf("%d", ans);
	return 0;
}
