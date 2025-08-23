#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 3005
#define ll long long
using namespace std;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
int n, m, mo, ans;
int f[maxn][maxn];
int main() {
	freopen("easyhard.in", "r", stdin);
	freopen("easyhard.out", "w", stdout);
	n = read(), m = read(), mo = read();
	ru(i, 0, n) f[0][i] = 1;
	ru(i, 1, m) {
		ru(j, 1, n - 1) {
			ll tmp = (ll)f[i - 1][j - 1] + f[i - 1][j + 1] + f[i - 1][j] * 2;
			f[i][j] = tmp % mo;
		}
		f[i][0] = (f[i - 1][1] + f[i - 1][0]) % mo;
		f[i][n] = (f[i - 1][1] + f[i - 1][n]) % mo;
	}
	ru(i, 0, n) ans = (ans + f[m][i]) % mo;
	n--;
	memset(f, 0, sizeof(f));
	ru(i, 0, n) f[0][i] = 1;
	ru(i, 1, m) {
		ru(j, 1, n - 1) {
			ll tmp = (ll)f[i - 1][j - 1] + f[i - 1][j + 1] + f[i - 1][j] * 2;
			f[i][j] = tmp % mo;
		}
		f[i][0] = (f[i - 1][1] + f[i - 1][0]) % mo;
		f[i][n] = (f[i - 1][1] + f[i - 1][n]) % mo;
	}
	ru(i, 0, n) ans = (ans + mo - f[m][i]) % mo;
	printf("%d\n", ans);
	return 0;
}