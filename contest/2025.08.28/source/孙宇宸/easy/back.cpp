#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;

template <typename T, typename... Args>
void dbg(const T &first, Args... args) {
	cerr << first;
	if (sizeof...(args)) {
		cerr.put(' ');
		dbg(args...);
	} else {
		cerr << endl;
	}
}

constexpr int N = 250000 + 1, P = 998244353;

struct Node {
	ll suma, sumb, sumc;
	int ma, mb, mc;
	bool ta, tb, tc;
} seg[N << 2];

int a[N], b[N], c[N];

void solve() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	
	auto pu = [](int p) {
		int ls = p << 1, rs = p << 1 | 1;
		seg[p].suma = seg[ls].suma + seg[rs].suma;	
		seg[p].sumb = seg[ls].sumb + seg[rs].sumb;	
		seg[p].sumc = seg[ls].sumc + seg[rs].sumc;	
	};
	auto bd = [&](auto &&self, int pos, int l, int r) {
		if (l == r) {
			seg[pos] = {a[r], b[r], c[r], -1, -1, -1, false, false, false};
			return ;
		}
		int mid = (l + r) >> 1;
		self(self, pos << 1, l, mid);
		self(self, pos << 1 | 1, mid + 1, r);
		pu(pos);
	};
	bd(bd, 1, 1, n);
	
	auto mk1 = [](int pos) {
		seg[pos].ta = true;
		seg[pos].suma += seg[pos].sumb;
	};
	auto mk2 = [](int pos) {
		seg[pos].tb = true;
		seg[pos].sumb += seg[pos].sumc;
	};
	auto mk3 = [](int pos) {
		seg[pos].mc = true;
		seg[pos].sumc += seg[pos].suma;
	};
	auto pd = [&](int pos, int l, int r) {
		int mid = (l + r) >> 1, ls = pos << 1, rs = pos << 1 | 1;
		if (seg[pos].ta) {
			mk1(ls);
			mk1(rs);
			seg[pos].ta = false;
		} else if (seg[pos].tb) {
			mk2(ls);
			mk2(rs);
			seg[pos].tb = false;
		} else if (seg[pos].tc) {
			mk3(ls);
			mk3(rs);
			seg[pos].tc = false;
		}
		
	};
	auto rge1 = [&](int ql, int qr) {
		auto dfs = [&](auto &&self, int pos, int l, int r) {
			if (ql <= l && r <= qr) {
				if (l != r) {
					pd(pos, l, r);
				}
				mk1(pos);
				return ;
			}
			int mid = (l + r) >> 1;
			pd(pos, l, r);
			if (ql <= mid) {
				self(self, pos << 1, l, mid);
			}
			if (qr > mid) {
				self(self, pos << 1 | 1, mid + 1, r);				
			}
			pu(pos);
		};
		dfs(dfs, 1, 1, n);
	};
	
	cin >> m;
	while (m--) {
		int op, l, r;
		cin >> op >> l >> r;
		if (op == 1) {
			
		} else if (op == 2) {
			
		} else if (op == 3) {
			
		} else if (op == 4) {
			
		} else if (op == 5) {
			
		} else if (op == 6) {
			
		} else if (op == 7) {
			
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
