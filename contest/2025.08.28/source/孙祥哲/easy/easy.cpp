#include <bits/stdc++.h>
#define mod 998244353
#define ll long long
#define N 200005
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

ll n, m;
ll a[N];

signed main()
{
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	if (n <= 5000 && m <= 5000)
	{
		while (m--)
		{
			ll op = read(), l, r, v = 0;
			if (op == 1 || op == 2)
			{
				if (op == 1) v = read();
				for (int i = 1; i <= n; i++) a[i] = op==1?min(a[i],v):a[i]+i;
			}
			else
			{
				l = read(), r = read();
				for (int i = l; i <= r; i++) v += a[i];
				write(v, '\n');
			}
		}
	}
	return 0;
} 
/*
15 15
6 14 14 6 3 6 4 13 10 3 12 5 11 9 6
1 9
1 2
2
2
2
1 11
3 4 6
2
1 6
2
1 9
1 11
1 11
3 4 4
3 2 13
*/
