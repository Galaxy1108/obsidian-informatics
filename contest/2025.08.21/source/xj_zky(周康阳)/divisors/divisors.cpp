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
const int LIM = 11000;
const int N = 5e5 + 7;
int n, m, tot;
mt19937_64 orz(time(0) ^ clock());
struct hamil { // 有向图求哈密顿路径 
	struct edge {
		int u, v;
		edge (int x = 0, int y = 0) { u = x, v = y; }
	} ;
	vector < edge > eg;
	vi in, out;
	void add (int u, int v) {
		eg.push_back(edge (u, v));
	}
	bool road (int x, int y) {
		if(!out[x]) return false ;
		if(out[x] == y) return true ;
		return road (out[x], y);
	}
	vi solve (int n) {
		in.resize(n + 1);
		out.resize(n + 1);
		while (true) {
			L(i, 0, n) in[i] = out[i] = 0;
			int tot = 0, cnt = 0;
			while (true) {
				int lst = tot;
				shuffle (eg.begin(), eg.end(), orz);
				for (auto e : eg) {
					int u = e.u, v = e.v;
					if (in[v] && out[u]) 
						continue ;
					if (road (v, u)) 
						continue ;
					if (!in[v] && !out[u]) ++tot;
					else if (orz() & 1) continue ;
					if (in[v]) 
						out[in[v]] = 0, in[v] = 0;
					if (out[u]) 
						in[out[u]] = 0, out[u] = 0;
					in[v] = u, out[u] = v;
				}
				cnt += 1;
				if(tot != lst) cnt = 0; 
				else {
					cnt += 1;
					if(cnt >= 3e6) 
						break ;
				}
				if(tot == n - 1) 
					break ;
			}
			if(tot == n - 1) 
				break ;
		}
		L(i, 1, n) if(!in[i]) {
			vi R;
			for (int x = i; x; x = out[x]) 
				R.push_back(x);
			return R;
		} 
		return {};
	}
	void clear () {
		eg.clear ();
	}
} ;

hamil S;

int cur[N];

int lcm(int x, int y) {
	return x / __gcd(x, y) * y;
}
void slv(int n) {
	int qaq = 0;
	L(i, 2, n) {
		L(j, 2, n) {
			if(lcm(i, j) <= LIM && i != j) {
				S.add(i - 1, j - 1);
				qaq += 1;
			}
		}
	}
	vi qwq = S.solve (n - 1);
	S.clear ();
	L(i, 1, n) cur[i] = 1;
	L(i, 0, n - 2) 
		cur[i + 1] = lcm(cur[i + 1], qwq[i] + 1), 
		cur[i + 2] = lcm(cur[i + 2], qwq[i] + 1);
	L(i, 1, n) cout << cur[i] << ' ';
	cout << '\n';
}

int slv(vi a, int lim) {
	sort(a.begin(), a.end());
	bool ok = true;
	L(j, 0, sz(a) - 2) if(lcm(a[j], a[j + 1]) > lim) ok = false;
	if(ok) return sz(a);
	
	int xn = sz(a);
	vi vis(xn);
	L(i, 2, xn) {
		vi cur;
		L(j, 0, xn - 1) 
			if(a[j] % i == 0 && !vis[j]) 
				cur.emplace_back(a[j] / i), vis[j] = true;
				
	} 
}

int main() {
	freopen("divisors.in", "r", stdin);
	freopen("divisors.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	vi a;
	L(i, 1, n) a.emplace_back(i); 
//	slv(a, LIM);
	slv(n);
	L(i, 1, n - 1) {
		cout << i << ' ' << i + 1 << '\n';
	}
	return 0;
} 