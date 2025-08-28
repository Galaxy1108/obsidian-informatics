#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;

constexpr ui N = 250000 + 1, P = 998244353;

struct Node {
	array<ui, 3> sum;
	ui m[3];
} seg[N << 2];

ui a[N], b[N], c[N];

array<ull, 3> operator + (const array<ull, 3> &x, const array<ull, 3> &y) {
	return {x[0] + y[0], x[1] + y[1], x[2] + y[2]};
}
array<ui, 4> que[N];

void solve() {
	ui n, m;
	cin >> n;
	for (ui i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}

	cin >> m;
	bool flag = false, ok = true;
	for (ui i = 1; i <= m; ++i) {
		cin >> que[i][0] >> que[i][1] >> que[i][2];
		flag |= que[i][0] == 7;
		if (que[i][0] <= 3) {
			ok = false;
		}
		if (que[i][0] <= 6 && que[i][0] > 3) {
			cin >> que[i][3];
		}
	}
	if (!flag) {
		return ;
	}
	auto rd = [](ui x) {
		return x >= P ? x - P : x;
	};
	auto mk2 = [&](int p, int v, int l, int r) {
		seg[p].m[0] = (seg[p].m[0] + v) % P;
		seg[p].sum[0] = (seg[p].sum[0] + (r - l + 1) * (ull)v) % P;
	};
	auto mk3 = [&](int p, int v) {
		seg[p].m[1] = (seg[p].m[1] * (ull)v) % P;
		seg[p].sum[1] = (seg[p].sum[1] * (ull)v) % P;
	};
	auto mk4 = [&](int p, int v, int l, int r) {
		seg[p].m[2] = v;
		seg[p].sum[2] = ((ull)v * (r - l + 1)) % P;
	};
	auto pd = [&](int pos, int l, int r) {
		int mid = (l + r) >> 1, ls = pos << 1, rs = pos << 1 | 1;
		for (int i = 0; i < 3; ++i) {
			if (seg[pos].m[i] != numeric_limits<ui>::max()) {
				if (i == 0) {
					mk2(ls, seg[pos].m[i], l, mid);
					mk2(rs, seg[pos].m[i], mid + 1, r);
				} else if (i == 1) {
					mk3(ls, seg[pos].m[i]);
					mk3(rs, seg[pos].m[i]);
				} else {
					mk4(ls, seg[pos].m[i], l, mid);
					mk4(rs, seg[pos].m[i], mid + 1, r);
				}
				if (i == 0) {
				seg[pos].m[i] = 0;
				} else if(i == 1) {
					seg[pos].m[i] = 1;
					
				} else {
					seg[pos].m[i] = numeric_limits<ui>::max();
				}
			}
		}
	};
	auto rgs = [&](int ql, int qr) {
		auto dfs = [&](auto &&self, int pos, int l, int r) -> array<ull, 3> {
			if (ql <= l && r <= qr) {
				return {seg[pos].sum[0], seg[pos].sum[1], seg[pos].sum[2]};
			}
			int mid = (l + r) >> 1;
			pd(pos, l, r);
			if (qr <= mid) {
				return self(self, pos << 1, l, mid);
			}
			if (ql > mid) {
				return self(self, pos << 1 | 1, mid + 1, r);				
			}
			return self(self, pos << 1, l, mid) + self(self, pos << 1 | 1, mid + 1, r);
		};
		return dfs(dfs, 1, 1, n);
	};
	if (ok) {
//		cerr << "!!!\n";
		auto pu = [&](int p) {
			int ls = p << 1, rs = p << 1 | 1;
			for (int i = 0; i < 3; ++i) {
				seg[p].sum[i] = rd(seg[ls].sum[i] + seg[rs].sum[i]);
			}
		};
		auto bd = [&](auto &&self, int pos, int l, int r) {
			seg[pos] = {{0, 0, 0}, {0, 1, numeric_limits<ui>::max()}};
			if (l == r) {
				seg[pos] = {{a[r], b[r], c[r]}, {0, 1, numeric_limits<ui>::max()}};
				return ;
			}
			int mid = (l + r) >> 1;
			self(self, pos << 1, l, mid);
			self(self, pos << 1 | 1, mid + 1, r);
			pu(pos);
		};
		bd(bd, 1, 1, n);
		auto rgc = [&](int tp, int ql, int qr, int v) {
			auto dfs = [&](auto &&self, int pos, int l, int r) {
				if (ql <= l && r <= qr) {
					if (tp == 4) {
						mk2(pos, v, l, r);
					} else if (tp == 5) {
						mk3(pos, v);				
					} else {
						mk4(pos, v, l, r);
					}
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
		for (ui i_ = 1; i_ <= m; ++i_) {
			ui op = que[i_][0], l = que[i_][1], r = que[i_][2], v = que[i_][3];
			if (op == 7) {
				auto res = rgs(l, r);
				cout << res[0] % P << ' ' << res[1] % P << ' ' << res[2] % P << '\n';
				continue;
			}
			rgc(op, l, r, v);
		}
		return ;
	}
	for (ui i_ = 1; i_ <= m; ++i_) {
		ui op = que[i_][0], l = que[i_][1], r = que[i_][2], i;
		if (op <= 3) {
			if (op == 1) {
				ui re = r <= 8 ? 0 : r - 8;
				for (i = l; i <= re; i += 8) {
					a[i] = rd(a[i] + b[i]);
					a[i + 1] = rd(a[i + 1] + b[i + 1]);
					a[i + 2] = rd(a[i + 2] + b[i + 2]);
					a[i + 3] = rd(a[i + 3] + b[i + 3]);
					a[i + 4] = rd(a[i + 4] + b[i + 4]);
					a[i + 5] = rd(a[i + 5] + b[i + 5]);
					a[i + 6] = rd(a[i + 6] + b[i + 6]);	
					a[i + 7] = rd(a[i + 7] + b[i + 7]);
				}
				for ( ; i <= r; ++i) {
					a[i] = rd(a[i] + b[i]);
				}
			} else if (op == 2) {
				ui re = r <= 8 ? 0 : r - 8;
				for (i = l; i <= re; i += 8) {
					b[i] = rd(b[i] + c[i]);
					b[i + 1] = rd(b[i + 1] + c[i + 1]);
					b[i + 2] = rd(b[i + 2] + c[i + 2]);
					b[i + 3] = rd(b[i + 3] + c[i + 3]);
					b[i + 4] = rd(b[i + 4] + c[i + 4]);
					b[i + 5] = rd(b[i + 5] + c[i + 5]);
					b[i + 6] = rd(b[i + 6] + c[i + 6]);	
					b[i + 7] = rd(b[i + 7] + c[i + 7]);
				}
				for ( ; i <= r; ++i) {
					b[i] = rd(b[i] + c[i]);
				}
			} else {
				ui re = r <= 8 ? 0 : r - 8;
				for (i = l; i <= re; i += 8) {
					c[i] = rd(a[i] + c[i]);
					c[i + 1] = rd(a[i + 1] + c[i + 1]);
					c[i + 2] = rd(a[i + 2] + c[i + 2]);
					c[i + 3] = rd(a[i + 3] + c[i + 3]);
					c[i + 4] = rd(a[i + 4] + c[i + 4]);
					c[i + 5] = rd(a[i + 5] + c[i + 5]);
					c[i + 6] = rd(a[i + 6] + c[i + 6]);	
					c[i + 7] = rd(a[i + 7] + c[i + 7]);
				}
				for ( ; i <= r; ++i) {
					c[i] = rd(a[i] + c[i]);
				}
			}
		} else if (op <= 6) {
			ui v = que[i_][3];
			if (op == 4) {
				ui re = r <= 8 ? 0 : r - 8;
				for (i = l; i <= re; i += 8) {
					a[i] = rd(a[i] + v);
					a[i + 1] = rd(a[i + 1] + v);
					a[i + 2] = rd(a[i + 2] + v);
					a[i + 3] = rd(a[i + 3] + v);
					a[i + 4] = rd(a[i + 4] + v);
					a[i + 5] = rd(a[i + 5] + v);
					a[i + 6] = rd(a[i + 6] + v);	
					a[i + 7] = rd(a[i + 7] + v);
				}
				for ( ; i <= r; ++i) {
					a[i] = rd(a[i] + v);
				}
			} else if (op == 5) {
				ui re = r <= 8 ? 0 : r - 8;
				ull d = v;
				for (i = l; i <= re; i += 8) {
					b[i] = b[i] * d % P;
					b[i + 1] = b[i + 1] * d % P;
					b[i + 2] = b[i + 2] * d % P;
					b[i + 3] = b[i + 3] * d % P;
					b[i + 4] = b[i + 4] * d % P;
					b[i + 5] = b[i + 5] * d % P;
					b[i + 6] = b[i + 6] * d % P;	
					b[i + 7] = b[i + 7] * d % P;
				}
				for ( ; i <= r; ++i) {
					b[i] = b[i] * d % P;
				}
			} else {
				ui re = r <= 8 ? 0 : r - 8;
				for (i = l; i <= re; i += 8) {
					c[i] = v;
					c[i + 1] = v;
					c[i + 2] = v;
					c[i + 3] = v;
					c[i + 4] = v;
					c[i + 5] = v;
					c[i + 6] = v;	
					c[i + 7] = v;
				}
				for ( ; i <= r; ++i) {
					c[i] = v;
				}
			}
		} else if (op == 7) {
			ull sa{}, sb{}, sc{};
			ui re = r <= 8 ? 0 : r - 8;
			for (i = l; i <= re; i += 8) {
				sa += a[i];
				sb += b[i];
				sc += c[i];
				sa += a[i + 1];
				sb += b[i + 1];
				sc += c[i + 1];
				sa += a[i + 2];
				sb += b[i + 2];
				sc += c[i + 2];
				sa += a[i + 3];
				sb += b[i + 3];
				sc += c[i + 3];
				sa += a[i + 4];
				sb += b[i + 4];
				sc += c[i + 4];
				sa += a[i + 5];
				sb += b[i + 5];
				sc += c[i + 5];
				sa += a[i + 6];
				sb += b[i + 6];
				sc += c[i + 6];
				sa += a[i + 7];
				sb += b[i + 7];
				sc += c[i + 7];
			}
			for ( ; i <= r; ++i) {
				sa += a[i];
				sb += b[i];
				sc += c[i];
			}
			cout << sa % P << ' ' << sb % P << ' ' << sc % P << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);

	ui t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
