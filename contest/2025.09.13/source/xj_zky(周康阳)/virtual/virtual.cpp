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
int n, q, l, r;
int f[N];
inline int find(int x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}
int pos[N], tp, pre[N];

char s[N];
int main() {
//	return system("fc virtual3.out virtual.out"), 0;
	freopen("virtual.in", "r", stdin);
	freopen("virtual.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> l >> r;
	L(i, 1, n) f[i] = i;
	cin >> (s + 1);
	L(i, 1, n) if(s[i] == 'a') pos[++tp] = i;
	pos[tp + 1] = n + 1;
	int cnt = 0;
	L(i, 1, n) {
		if(cnt + l > tp) break;
		int L = pos[cnt + l], R = pos[min(cnt + r + 1, tp + 1)] - 1;
		pre[L] += 1, pre[R] -= 1, f[find(i)] = find(L), cnt += s[i] == 'a';
	}
	L(i, 1, n - 1) {
		pre[i] += pre[i - 1];
		if(pre[i]) f[find(i)] = find(i + 1);
	}
	cin >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		if(find(x) == find(y)) cout << "Yes\n";
		else cout << "No\n"; 
	}
	return 0;
} 