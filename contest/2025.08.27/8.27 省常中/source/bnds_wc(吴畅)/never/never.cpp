#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define ll long long
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 100005
#define int long long
using namespace std;
ll n, S, T, X, Y;
int L, R, siz[maxn], tot; ll d[maxn];
vector<pii> G[maxn];
void work(ll &pos, ll id, ll step) {
	ll cnt = step / siz[id];
	pos += d[id] * cnt;
	step -= siz[id] * cnt;
	if(!step) return;
	for (auto x: G[id]) {
		if(step <= (ll)siz[x.fi] * x.se) {
			work(pos, x.fi, step);
			return;
		}
		pos += d[x.fi] * x.se;
		step -= (ll)siz[x.fi] * x.se;
	}
}
void solve() {
	scanf("%lld%lld%lld%lld%lld", &n, &S, &T, &X, &Y);
	ru(i, 1, tot) {
		G[i].clear();
		d[i] = 0;
		siz[i] = 0;
	}
	d[L = 1] = Y, d[R = 2] = -X, siz[1] = siz[2] = 1, tot = 2;
	while(1) {
		if(d[L] <= -d[R]) {
			if(S >= T) {
				ll step = (S - T + (-d[R])) / (-d[R]);
				if(step * siz[R] >= n) {
					work(S, R, n);
					break;
				}
				n -= step * siz[R], S += step * d[R];
			}
			if(d[L] == 0) {
				work(S, L, n);
				break;
			}
			ll step = (T - S + d[L] - 1) / d[L];
			if(step * siz[L] >= n) {
				work(S, L, n);
				break;
			}
			n -= step * siz[L], S += step * d[L];
			ll cnt = (-d[R]) / d[L];
			siz[++tot] = siz[L] * cnt + siz[R];
			d[tot] = d[R] + cnt * d[L];
			G[tot].push_back(mp(R, 1));
			G[tot].push_back(mp(L, cnt));
			R = tot;
		}
		else {
			if(S < T) {
				ll step = (T - S - 1 + d[L]) / d[L];
				if(step * siz[L] >= n) {
					work(S, L, n);
					break;
				}
				n -= step, S += step * d[L];
			}
			if(d[R] == 0) {
				work(S, R, n);
				break;
			}
			ll step = (S - T + (-d[R])) / (-d[R]);
			if(step * siz[R] >= n) {
				work(S, R, n);
				break;
			}
			n -= step * siz[R], S += step * d[R];
			ll cnt = d[L] / (-d[R]);
			siz[++tot] = siz[R] * cnt + siz[L];
			d[tot] = d[L] + cnt * d[R];
			G[tot].push_back(mp(L, 1));
			G[tot].push_back(mp(R, cnt));
			L = tot;
		}
	}
	printf("%lld\n", S);
}
signed main() {
	freopen("never.in", "r", stdin);
	freopen("never.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--) solve();
	return 0;
}