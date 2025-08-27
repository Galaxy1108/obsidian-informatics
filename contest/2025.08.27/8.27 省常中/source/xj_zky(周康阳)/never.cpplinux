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
ll solve(ll n, ll s, ll x, ll y) { 
	if(s < 0) {
		ll t = min((abs(s) + y - 1) / y, n);
		s += t * y, n -= t;
	}
	if(s >= x) {
		ll t = min(s / x, n);
		s -= t * x, n -= t;
	}
	if(!n) return s; 
	// ans in [-x,y)
	__int128 tmp = s + (__int128) y * n;
	s = tmp - (tmp + x) / (x + y) * (x + y);
	return s;
}

void Main() {
	ll n, s, t, x, y;
	cin >> n >> s >> t >> x >> y;
	cout << solve(n, s - t, x, y) + t << '\n';
} 

int main() {
//	return system("fc ex_never2.out never.out"), 0;
	freopen("never.in", "r", stdin);
	freopen("never.out", "w", stdout); 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) Main();
	return 0;
}