#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 200005
#define ll long long
using namespace std;
const int mo = 998244353;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
int n, a[maxn], v[maxn], tot; ll sum;
int work() {
	int mx = 0; ll tmp = sum, ans = 0;
	rd(i, n, 1) {
		mx = max(mx, a[i]), tmp -= a[i];
		if(mx > tmp) {
			mx -= a[i];
			ans += v[i];
		}
	}
	return ans % mo;
}
int main() {
	freopen("imperishable.in", "r", stdin);
	freopen("imperishable.out", "w", stdout);
	n = read(), n = read();
	v[0] = 1;
	ru(i, 1, n) a[i] = read(), v[i] = (ll)v[i - 1] * 2 % mo, sum += a[i];
	int q = read();
	printf("%d\n", work());
	while(q--) {
		int x = read(), y = read();
		sum += y - a[x], a[x] = y;
		printf("%d\n", work());
	}
	return 0;
}