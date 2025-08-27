#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 205
using namespace std;
ll M, S;
int n, a[maxn];
int f[100005], las[100005];
void solve() {
	scanf("%lld%lld%d", &M, &S, &n);
	ru(i, 1, n) scanf("%d", &a[i]);
	int B = a[n] + 1;
	f[0] = 1; ru(i, 1, B) f[i] = 0;
	rd(i, 60, 0) {
		ru(j, 0, B) las[j] = f[j], f[j] = 0;
		ru(j, 0, B) if(las[j]) {
			ll t = (S >> (i + 1)) - j;
			t *= 2;
			ll t2 = S >> i;
			if(t > t2 || t < t2 - 2 * B) continue;
			if((M >> i) & 1) {
				ru(k, 1, n) {
					if(t + a[k] > t2 || t + a[k] < t2 - B) continue;
					f[t2 - t - a[k]] ^= las[j];
				}
			}
			else {
				if(t > t2 || t < t2 - B) continue;
				f[t2 - t] ^= las[j];
			}
		}
	}
	printf("%d\n", f[0]);
}
int main() {
	freopen("give.in", "r", stdin);
	freopen("give.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}