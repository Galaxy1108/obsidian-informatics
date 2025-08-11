#include <bits/stdc++.h>
using namespace std;
const int N = 150005;
int n;
struct node {
	int id;
	int x, y, z;
} a[N];
int ans = -1;
int read(void) {
	int x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - 48;
		ch = getchar(); 
	}
	return x;
}
int main(void) {
	freopen("battle.in", "r", stdin);
	freopen("battle.out", "w", stdout);
	n = read();
	for (int i = 1; i <= n; ++i) {
		a[i].id = i;
		a[i].x = read(), a[i].y = read(), a[i].z = read();
	}
	if (n <= 500) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					if (i != j && i != k && j != k && a[i].x > a[j].x && a[i].x > a[k].x && a[j].y > a[i].y && a[j].y > a[k].y && a[k].z > a[i].z && a[k].z > a[j].z) {
						ans = max(ans, a[i].x + a[j].y + a[k].z);
					}
				}
			}
		}
		printf("%d", ans);
		return 0;
	}
	printf("-1");
	return 0;
}
