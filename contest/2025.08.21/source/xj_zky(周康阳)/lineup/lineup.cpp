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
const int N = 1e6 + 7;
int n, a[N], b[N];
vi vc[N]; 
int main() {
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	L(i, 1, n) {
		cin >> a[i];
		b[i] = a[i];
		vc[a[i]].emplace_back(i);
	}
	ll ns = 0;
	sort(b + 1, b + n + 1);
	R(i, n, 1) {
		ns += abs(i - vc[b[i]].back());
		vc[b[i]].pop_back();
	}
	cout << ns << '\n';
	return 0;
} 