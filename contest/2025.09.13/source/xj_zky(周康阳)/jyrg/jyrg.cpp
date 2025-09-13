#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 2e6 + 7;
const ll inf = 2.1e18;
int n, ord[N];
ll a[N];
/*
x_i = a_i - i
b_i = a_{i+1}-1
x_i = x_{i+1} + i
*/
ll mx[N], tag[N], qrs;
void build(int x, int L, int R) {
	tag[x] = 0;
	if(L == R) return mx[x] = a[L] + L * 2 + 1, void();
	int mid = (L + R) >> 1;
	build(x << 1, L, mid); build(x << 1 | 1, mid + 1, R); 
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}
ll add(int x, int L, int R, int l, int r) {
	if(l <= L && R <= r) return tag[x] -= 2, mx[x] -= 2, mx[x];
	int mid = (L + R) >> 1;
	ll ns = -inf;
	if(l <= mid) ns = max(ns, add(x << 1, L, mid, l, r));
	if(r > mid) ns = max(ns, add(x << 1 | 1, mid + 1, R, l, r));
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]) + tag[x];
	return ns + tag[x];
}
void upd(int x, int L, int R, int p) {
	if(L == R) return mx[x] = -inf, void();
	int mid = (L + R) >> 1;
	p <= mid ? upd(x << 1, L, mid, p) : upd(x << 1 | 1, mid + 1, R, p); 
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]) + tag[x];
}

ll w[N];
void Main() {
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
		a[i] -= i;
		ord[i] = i;
	}
	sort(ord + 1, ord + n + 1, [&] (int x, int y) {
		return a[x] < a[y];
	});
	L(i, 1, n - 1) {
		if(a[ord[i]] == a[ord[i + 1]]) {
			cout << "-1\n";
			return ;
		}
	}
	ll ns = 0;
	build(1, 1, n);
	L(o, 1, n) {
		int p = ord[o];
		if(p < n) ns = max(ns, add(1, 1, n, p + 1, n) + a[p]);
		upd(1, 1, n, p);
	}
	cout << ns << '\n';
}
int main() {
//	return system("fc jyrg3.ans jyrg.out"), 0;
	freopen("jyrg.in", "r", stdin);
	freopen("jyrg.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
} 