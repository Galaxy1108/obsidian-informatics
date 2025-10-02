#include <bits/stdc++.h>
#define len (Int)(r - l + 1)
using namespace std;
typedef __int128 Int;
constexpr int N = 4e3;
int n, h[N];
Int ans;
void write(Int ans) {
	if (ans > 9)
		write(ans / 10);
	putchar(ans % 10 + 48);
	return ;
}
int main(void) {
	freopen("drama.in", "r", stdin), freopen("drama.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	for (int l = 1; l <= n; ++l) {
		int mx = INT_MIN, mn = INT_MAX;
		for (int r = l; r <= n; ++r)
			mx = max(mx, h[r]), mn = min(mn, h[r]), ans = max(ans, len * mx * mn);
	}
	write(ans);
	return 0;
}
