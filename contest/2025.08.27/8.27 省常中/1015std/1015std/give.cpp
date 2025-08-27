#include<bits/stdc++.h>
using namespace std;
const int MAXLOG = 62;
const int MAXK = 2e2 + 5;
const int MAXN = 2e5 + 5;
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
ll n, s; int k, a[MAXK];
bool x[MAXLOG], y[MAXLOG];
bitset <MAXN> cur, nxt;
int main() {
	freopen("give.in", "r", stdin);
	freopen("give.out", "w", stdout);
	int T; read(T);
	while (T--) {
		read(n), read(s), read(k);
		for (int i = 0; i < MAXLOG; i++) {
			x[i] = (s & (1ll << i)) != 0;
			y[i] = (n & (1ll << i)) != 0;
		}
		for (int i = 1; i <= k; i++)
			read(a[i]);
		cur.reset();
		cur.set(0);
		for (int i = MAXLOG - 1; i >= 0; i--) {
			nxt.reset();
			for (int j = 0; j <= 1e5; j++)
				nxt[j * 2 + x[i]] = cur[j];
			cur.reset();
			if (y[i]) {
				for (int j = 1; j <= k; j++)
					cur ^= nxt >> a[j];
			} else cur = nxt;
		}
		if (cur[0]) puts("1");
		else puts("0");
	}
	return 0;
}