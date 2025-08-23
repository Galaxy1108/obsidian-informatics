#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define maxn 200010
#define writeln(X); write(X); *O++ = '\n';
using namespace std;
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
template < typename T >
inline void read(T &X) 
{
	X = 0; bool f = false; char ch = getchar();
	while (ch < '0' || ch > '9') {f |= ch == '-'; ch = getchar();}
	while (ch >= '0' && ch <= '9') {X = X * 10 + (ch ^ 48); ch = getchar();}
	X = f ? -X : X;
	return;
}
template < typename T >
inline void write(T X) 
{
	if (X == 0) {*O++ = '0'; return;}
	if (X < 0) {*O++ = '-'; X = -X;}
	static int cnt = 0, num[21];
	while (X) {num[++cnt] = X % 10; X /= 10;}
	while (cnt) *O++ = num[cnt--] ^ 48;
	return;
}
int n, q, x, y, p;
int a[maxn], mi[maxn];
int s, node[maxn << 2];
ll ans, sum;
inline void build()
{
	for (s = 1; s < n; s <<= 1);
	for (int i = 1; i <= n; ++i) node[s + i - 1] = a[i];
	for (int i = s - 1; i; --i) node[i] = max(node[i << 1], node[(i << 1) | 1]);
}
inline void update(int x, int v)
{
	x += s - 1; node[x] = v;
	for (int i = x >> 1; i; i >>= 1) node[i] = max(node[i << 1], node[(i << 1) | 1]);
}
int main()
{
	freopen("imperishable.in", "r", stdin);
	freopen("imperishable.out", "w", stdout);
	read(n);
	read(n);
	mi[0] = 1;
	for (int i = 1; i <= n; ++i) read(a[i]), mi[i] = (mi[i - 1] << 1) % mod;
	build();
	p = 1;
	for (; p <= n; ++p)
	{
		sum += a[p]; ans = (ans + mi[p]) % mod;
		if (sum >= node[1]) break;
	}
	for (; p; --p)
	{
		if (sum - a[p] >= node[1])
		{
			sum -= a[p];
			ans = (ans - mi[p] + mod) % mod;
		}
	}
	writeln(ans);
	read(q);
	for (int i = 1; i <= q; ++i)
	{
		read(x); read(y);
		a[x] = y; update(x, y);
		sum = 0, ans = 0, p = 1;
		for (; p <= n; ++p)
		{
			sum += a[p]; ans = (ans + mi[p]) % mod;
			if (sum >= node[1]) break;
		}
		for (; p; --p)
		{
			if (sum - a[p] >= node[1])
			{
				sum -= a[p];
				ans = (ans - mi[p] + mod) % mod;
			}
		}
		writeln(ans);
	}
	fwrite(obuf, O - obuf, 1, stdout); 
	return 0;
}
