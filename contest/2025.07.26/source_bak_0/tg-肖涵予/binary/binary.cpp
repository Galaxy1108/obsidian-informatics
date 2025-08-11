#include <bits/stdc++.h>
using namespace std;
const int M = 12;
const int N = 1 << M;
const int T = 1700;
int m, n, H, W;
bool flag[M][N];
int h[M], pow2[M];
char ans[T][T];
void preDfs(int step, int u, bool val) {
	flag[step][u] = val;
	if (step == m)
		return ;
	int left = (u << 1) - 1, right = (u << 1), nxt = step + 1;
	if (flag[nxt][left])
		preDfs(nxt, left, true);
	else
		preDfs(nxt, left, val);
	if (flag[nxt][right])
		preDfs(nxt, right, true);
	else
		preDfs(nxt, right, val);
	return ;
}
void init(void) {
	pow2[0] = 1;
	for (int i = 1; i < M; ++i)
		pow2[i] = pow2[i-1] << 1;
	h[1] = 1, h[2] = 3;
	for (int i = 3; i < M; ++i)
		h[i] = h[i-1] << 1;
	return ;
}
void Print(int step, int u, int i, int j) {
	ans[i][j] = 'o';
	if (step == m)
		return ;
	int nxt = step + 1, left = (u << 1) - 1, right = (u << 1), num = 0, hb = m - step + 1;
	if (nxt == m)
		num = 1;
	else
		num = (h[hb] >> 1) - 1;
	if (!flag[nxt][left]) {
		for (int k = 1; k <= num; ++k)
			ans[i+k][j-k] = '/';
		Print(nxt, left, i + num + 1, j - num - 1);
	}
	if (!flag[nxt][right]) {
		for (int k = 1; k <= num; ++k)
			ans[i+k][j+k] = '\\';
		Print(nxt, right, i + num + 1, j + num + 1);
	}
	return ;
}
int main(void) {
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	init();
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> m >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		flag[x][y] = true;
	}
	preDfs(1, 1, false);
	H = h[m];
	W = 1;
	for (int i = 2; i <= pow2[m-1]; ++i) {
		++W;
		if (i % 2)
			++W;
		else
			W += 3;
	}
	int nowy = (W + 1) >> 1;
	for (int i = 1; i <= H; ++i)
		for (int j = 1; j <= W; ++j)
			ans[i][j] = ' ';
	Print(1, 1, 1, nowy);
	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j)
			cout << ans[i][j];
		cout << '\n';
	}
	return 0;
}
