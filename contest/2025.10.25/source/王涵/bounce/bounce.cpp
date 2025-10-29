#include <cstdio>
#define max(A, B) (A < B ? B : A)

int read()
{
	char c = getchar();
	while (c < '0' or '9' < c)
		c = getchar();
	int ret = 0;
	while ('0' <= c and c <= '9')
		ret = (ret << 3) + (ret << 1) + c - '0',
		c = getchar();
	return ret;
}

const int MX = 1000010, M = 20, MXM = M + 5;

namespace solve
{
namespace splay
{
int fa[MX], son[MX][2], val[MX], siz[MX], tot, rt;

#define update(x) (siz[x] = siz[son[x][0]] + 1 + siz[son[x][1]])
#define get(x) (son[fa[x]][1] == x)

void rotate(int x)
{
	if (fa[x] == rt)
		rt = x;
	int ffa = fa[fa[x]], dr = get(x);
	son[ffa][get(fa[x])] = x;
	fa[son[x][not dr]] = fa[x];
	son[fa[x]][dr] = son[x][not dr];
	son[x][not dr] = fa[x];
	fa[fa[x]] = x;
	fa[x] = ffa;
	update(son[x][not dr]);
	update(x);
}

void splay(int x)
{
	while (fa[x])
	{
		if (fa[fa[x]])
			rotate(get(x) == get(fa[x]) ? fa[x] : x);
		rotate(x);
	}
}

void build(int l, int r, int& p = rt)
{
	if (l > r)
		return;
	
	int mid = (l + r) >> 1;
	p = ++tot;
	val[p] = mid;
	if (l != r)
	{
		build(l, mid - 1, son[p][0]);
		build(mid + 1, r, son[p][1]);
		fa[son[p][0]] = fa[son[p][1]] = p;
	}
	update(p);
}

void del()
{
	if (son[rt][0] and son[rt][1])
	{
		int t = son[rt][0];
		fa[t] = 0;
		while (son[t][1])
			t = son[t][1];
		splay(t);
		son[t][1] = son[rt][1];
		fa[son[rt][1]] = t;
		rt = t;
		update(rt);
	}
	else if (son[rt][0] or son[rt][1])
		fa[rt = son[rt][(bool)son[rt][1]]] = 0;
}

int size()
{
	return siz[rt];
}

int kth(int k)
{
	int p = rt, pfa;
	while (p)
	{
		pfa = p;
		if (k > siz[son[p][0]])
		{
			k -= siz[son[p][0]] + 1;
			if (not k)
				return splay(p), val[p];
			p = son[p][1];
		}
		else
			p = son[p][0];
	}
	splay(pfa);
	return -2;
}

int find(int x)
{
	int p = rt;
	while (val[p] != x)
		p = son[p][val[p] < x];
	return p;
}

void delx(int x)
{
	splay(find(x));
	del();
}

int del(int k)
{
	int ret = kth(k);
	del();
	return ret;
}

#undef update
#undef get
}

namespace f
{
int f[MXM][MX];

void gen(int f[], int n, int x)
{
	f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = i - (f[i - (i + x - 1) / x] + (f[i - (i + x - 1) / x] > i % x - 1) * ((f[i - (i + x - 1) / x] - max(i % x - 1, 0) - 1) / (x - 1) + (bool)(i % x))) + 1;
}

void init(int n)
{
	for (int m = 2; m <= M; m++)
		gen(f[m], n, m);
}
}

bool dd[MXM], isd[MX];
int n;

void init(int n)
{
	f::init(solve::n = n);
	splay::build(0, n - 1);
}

void del(int m)
{
	if (not dd[m])
	{
		dd[m] = true;
		for (int i = 0; i * m < n; i++)
			if (not isd[i * m])
				splay::delx(i * m),
				isd[i * m] = true;
	}
}

void rem(int m)
{
	for (int i = splay::size() / m; ~i; i--)
		isd[splay::del(i * m + 1)] = true;
}

int query(int m)
{
	return splay::kth(f::f[m][splay::size()]) + 1;
}
}

int main()
{
	freopen("bounce.in", "r", stdin);
	freopen("bounce.out", "w", stdout);
	int n, q, t, m;
	scanf("%d%d", &n, &q);
	solve::init(n);
	while (q--)
	{
		scanf("%d%d", &t, &m);
		if (t == 1)
			solve::del(m);
		else if (t == 2)
			solve::rem(m);
		else
			printf("%d\n", solve::query(m));
	}
}
