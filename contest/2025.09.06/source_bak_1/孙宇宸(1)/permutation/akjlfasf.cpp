#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#ifdef jiji
template <typename T, typename... Args>
void dbg(const T &first, Args... args) {
	cerr << first;
	if constexpr (sizeof...(args)) {
		cerr.put(' ');
		dbg(args...);
	} else {
		cerr << endl;
	}
}
#endif

constexpr int N = 200000 + 1, P = 998244353;

mt19937 rnd{random_device{}()};

vector<int> gt(int n) {
	vector<int> v(n + 1);
	iota(v.begin() + 1, v.end(), 1);
	shuffle(v.begin() + 1, v.end(), rnd);
	return v;
}
vector<int> operator * (const vector<int> &x, const vector<int> &y) {
	vector<int> res(x.size());
	for (size_t i = 1; i < x.size(); ++i) {
		res[i] = y[x[i]];
	}
	return res;
}

void solve() {
	int n = 100000;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), c(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
	}
	assert(c * a == b * c);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
#ifdef jiji
//	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);	
#endif
	
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
