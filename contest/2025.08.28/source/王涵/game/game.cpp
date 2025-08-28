#include <cstdio>
#include <vector>

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

const int MX = 2000010, W = 23, MXT = MX * W;
int p0;
std::vector <int> T[MX];
int fa[MX];

namespace solve
{
namespace trie
{
int siz[MXT], son[MXT][2], mk[MXT], emp[MXT], tot, top;

void init()
{
	tot = top = 0;
}

void del(int x)
{
	emp[++top] = x;
}

int newrt()
{
	int t = top ? emp[top--] : ++tot;
	siz[t] = son[t][0] = son[t][1] = mk[t] = 0;
	return t;
}

void copy(int& p)
{
	if (not p)
		p = newrt();
}

void push_up(int p)
{
	siz[p] = siz[son[p][0]] + siz[son[p][1]];
}

void add(int x, int& p, int z)
{
	copy(p);
	siz[p]++;
	if (~z)
		add(x, son[p][(bool)(x & 1 << z)], z - 1);
}

void add(int x, int& p)
{
	add(x ^ mk[p], p, W - 1);
}

void xorr(int x, int& p)
{
	mk[p] ^= x;
}

void merge(int& p, int& q, int z, int tp, int tq)
{
	if (not p or not q)
	{
		if (not p)
			p = q;
	}
	else if (not ~z)
		siz[p] |= siz[q];
	else
	{
		merge(son[p][(bool)(tp & 1 << z)], son[q][(bool)(tq & 1 << z)], z - 1, tp, tq);
		merge(son[p][(bool)(~tp & 1 << z)], son[q][(bool)(~tq & 1 << z)], z - 1, tp, tq);
		push_up(p);
		del(q);
	}
}

void merge(int& p, int& q)
{
	merge(p, q, W - 1, mk[p], mk[q]);
}

int mex(int p, int z, int tmk)
{
	if (not ~z)
		return 0;
	else
	{
		if (siz[son[p][(bool)(tmk & 1 << z)]] == 1 << z)
			return mex(son[p][(bool)(~tmk & 1 << z)], z - 1, tmk) + (~tmk & 1 << z);
		else
			return mex(son[p][(bool)(tmk & 1 << z)], z - 1, tmk) + (tmk & 1 << z);
	}
}

int mex(int p)
{
	return mex(p, W - 1, mk[p]);
}
}

int rt[MX], sg[MX];

void DFS(int u)
{
	sg[u] = 0;
	for (int v : T[u])
		DFS(v),
		sg[u] ^= sg[v];
	rt[u] = trie::newrt();
	trie::add(sg[u], rt[u]);
	for (int v : T[u])
		trie::xorr(sg[u] ^ sg[v], rt[v]),
		trie::merge(rt[u], rt[v]);
	sg[u] = trie::mex(rt[u]);
}

int solve()
{
	trie::init();
	DFS(1);
	return sg[1];
}
}
int p1;
int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int t = read(), n, ans = 0;
	while (t--)
	{
		n = read();
		for (int i = 2; i <= n; i++)
			T[fa[i] = read()].push_back(i);
		ans ^= solve::solve();
		for (int i = 1; i <= n; T[i++].clear());
	}
	printf("%d", ans);
//	fprintf(stderr, "%.4lf", (&p1 - &p0) / 1024.0 / 1024);
}
