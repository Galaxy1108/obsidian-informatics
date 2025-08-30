#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
constexpr int N = 305, Q = 200005;
int n, q, a[N][N];
ll f[N][N], ans[Q];
struct Query {
	int x3, x4, y3, y4, id;
	Query () = default;
	Query (int x3, int x4, int y3, int y4, int id) : x3(x3), x4(x4), y3(y3), y4(y4), id(id) {}
} qr[Q];
ll min(ll x, ll y) {
	return (x < y ? x : y);
}
bool cmp(Query x, Query y) {
	if (x.x3 == y.x3)
		return (x.y3 < y.y3);
	return (x.x3 < y.x3); 
}
void Solve(void) {
	sort(qr + 1, qr + q + 1, cmp);
	int nowx = 0, nowy = 0;
	for (int i = 1; i <= q; ++i) {
		if (qr[i].x3 == nowx && qr[i].y3 == nowy) {
			ans[qr[i].id] = f[qr[i].x4][qr[i].y4];
			continue;
		}
		nowx = qr[i].x3, nowy = qr[i].y3;
		f[nowx][nowy] = a[nowx][nowy];
		for (int x = nowx; x <= n; ++x)
			for (int y = nowy; y <= n; ++y) {
				if (x > nowx && y > nowy)
					f[x][y] = min(f[x-1][y], f[x][y-1]) + a[x][y];
				else if (x > nowx)
					f[x][y] = f[x-1][y] + a[x][y];
				else if (y > nowy)
					f[x][y] = f[x][y-1] + a[x][y];
			}
		ans[qr[i].id] = f[qr[i].x4][qr[i].y4];
	}
	for (int i = 1; i <= q; ++i)
		printf("%lld\n", ans[i]);
	return ;
}
int main(void) {
	freopen("glyph.in", "r", stdin);
	freopen("glyph.out", "w", stdout);
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= q; ++i) {
		scanf("%d %d %d %d", &qr[i].x3, &qr[i].x4, &qr[i].y3, &qr[i].y4);
		qr[i].id = i;
	}
	Solve();
	return 0;
}
