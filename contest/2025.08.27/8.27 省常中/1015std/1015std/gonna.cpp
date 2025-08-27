#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXP = 2e7 + 5;
typedef long long ll;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, P, tot, prime[MAXN], f[MAXN], ans[MAXN];
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
		}
	}
}
int used, power[MAXP], pre[MAXP];
int func(int x, int y) {
	int ans = 0;
	while (x % y == 0) {
		ans++;
		x /= y;
	}
	return ans;
}
int calc(int p, int c) {
	while (used < c) {
		used++;
		power[used] = 1ll * power[used - 1] * p % P;
		pre[used] = power[used] + pre[used - 1];
		if (pre[used] >= P) pre[used] -= P;
	}
	return pre[c];
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int main() {
	freopen("gonna.in", "r", stdin);
	freopen("gonna.out", "w", stdout);
	read(n), read(P); sieve(n);
	for (int i = 1; i <= n; i++)
		ans[i] = 1;
	for (int i = 1; i <= tot; i++) {
		int p = prime[i], now = 0, sum = 0;
		used = 0; power[0] = pre[0] = 1; 
		for (int j = 1; j <= n; j++) {
			now += func(j, p), sum += now;
			int delta = calc(p, now * (j + 1) - 2 * sum);
			ans[j] = 1ll * ans[j] * delta % P;
		}
	}
	int finalans = 0;
	for (int i = 1; i <= n; i++)
		update(finalans, ans[i]);
	cout << finalans << endl;
	return 0;
}