#include <cstdio>
typedef long long intt;

const int MX = 100010, MXT = MX << 6, W = 30;

int a[MX];

namespace solve
{
namespace trie
{
int son[MXT][2], siz[MXT], mk[MXT], emp[MXT], tot, top;

void del(int& x)
{
	emp[++top] = x;
	x = 0;
}

void copy(int& p)
{
	if (not p)
	{
		p = top ? emp[top--] : ++tot;
		son[p][0] = son[p][1] = siz[p] = mk[p] = 0;
	}
}

void ins(int x, int& p, int z = W - 1)
{
	copy(p);
	x ^= mk[p];
	if (not ~z)
		siz[p]++;
	else
		ins(x, son[p][x >> z & 1], z - 1),
		siz[p] = siz[son[p][0]] + siz[son[p][1]];
}

void xorr(int x, int& p)
{
	copy(p);
	mk[p] ^= x;
}

int query(int x, int p, int z = W - 1, int tmk = 0)
{
	tmk ^= mk[p];
	if (not ~z)
		return siz[p];
	else if (x & 1 << z)
		return siz[son[p][tmk >> z & 1]] + query(x, son[p][tmk >> z & 1 ^ 1], z - 1, tmk);
	else
		return query(x, son[p][tmk >> z & 1], z - 1, tmk);
}

int qxor(int x, int a, int p)
{
	if (p)
	{
		xorr(x, p);
		int t = query(a, p);
		xorr(x, p);
		return t;
	}
	else
		return 0;
}

void clear(int& p)
{
	if (p)
	{
		clear(son[p][0]);
		clear(son[p][1]);
		del(p);
	}
}
}

int ls[MX], rs[MX], siz[MX], l[MX], r[MX], pre[MX], rt[MX];
intt ans;

void DFS(int u)
{
	if (ls[u])
		DFS(ls[u]);
	if (rs[u])
		DFS(rs[u]);
	siz[u] = 1 + siz[ls[u]] + siz[rs[u]];
	
	if (siz[ls[u]] < siz[rs[u]])
	{
		if (ls[u])
			trie::clear(rt[ls[u]]);
		for (int i = l[u]; i <= u; i++)
			ans += trie::qxor(pre[u] ^ pre[i - 1], a[u], rt[rs[u]]) + ((pre[u] ^ pre[i - 1]) <= a[u]);
		rt[u] = rs[u] ? rt[rs[u]] : 0;
		trie::ins(0, rt[u]);
		trie::xorr(pre[u] ^ pre[l[u] - 1], rt[u]);
		for (int i = l[u]; i < u; i++)
			trie::ins(pre[i] ^ pre[l[u] - 1], rt[u]);
	}
	else
	{
		if (rs[u])
			trie::clear(rt[rs[u]]);
		for (int i = u; i <= r[u]; i++)
			ans += trie::qxor(pre[i] ^ pre[l[u] - 1], a[u], rt[ls[u]]) + ((pre[i] ^ pre[l[u] - 1]) <= a[u]);
		rt[u] = ls[u] ? rt[ls[u]] : 0;
		for (int i = u; i <= r[u]; i++)
			trie::ins(pre[i] ^ pre[l[u] - 1], rt[u]);
	}
}

intt solve(int n)
{
	static int fa[MX];
	for (int i = 1; i <= n; i++)
	{
		int p = i - 1;
		while (p and a[p] < a[i])
			p = fa[p];
		ls[i] = rs[p];
		fa[rs[p]] = i;
		rs[p] = i;
		fa[i] = p;
	}
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] ^ a[i],
		l[i] = ls[i] ? l[ls[i]] : i;
	for (int i = n; i; i--)
		r[i] = rs[i] ? r[rs[i]] : i;
	DFS(rs[0]);
	return ans;
}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	printf("%lld", solve::solve(n));
}
