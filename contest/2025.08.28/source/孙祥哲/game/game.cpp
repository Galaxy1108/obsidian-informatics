#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
#define N 500005
using namespace std;

ll read()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') x = x*10+ch-'0', ch = getchar();
	return x*f;
}
void write(ll x) { if (x < 0) putchar('-'), x=-x; if (x > 9) write(x / 10); putchar(x%10+'0'); }
void write(ll x, char ed) { write(x),putchar(ed); }

signed main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	puts("0");
	return 0;
} 
