#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
constexpr int W = 1005;
int w, b;
ld mem[W][W];
bool flag[W][W];
ld solve(int w, int b) {
	if (!w)
		return 0;
	if (!b)
		return 1;
	if (flag[w][b])
		return mem[w][b];
	ld res = (ld)w / (w + b), lst = ((ld)1 - res) * (b - 1) / (w + b - 1);
	if (w + b > 2 && w && b > 1)
		res += lst * solve(w - 1, b - 2) * w / (w + b - 2);
	if (b > 2 && w + b > 2)
		res += lst * solve(w, b - 3) * (b - 2) / (w + b - 2);
	flag[w][b] = true, mem[w][b] = res;
	return res;
}
int main(void) {
	freopen("mouse.in", "r", stdin);
	freopen("mouse.out", "w", stdout);
	scanf("%d %d", &w, &b);
	printf("%.9Lf", solve(w, b));
	return 0;
}
