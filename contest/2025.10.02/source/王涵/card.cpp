#include <cstdio>
#include <set>
#include <array>

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

void write(int x)
{
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}

const int MX = 1000010, MXT = MX << 2;

namespace solve
{
namespace tr
{
struct balTree
{
private:
	int fa[MXT], son[MXT][2], val[MXT], cnt[MXT], sum[MXT], siz[MXT], tot, rt;
	
#define update(x) (sum[x] = sum[son[x][0]] + val[x] * cnt[x] + sum[son[x][1]], siz[x] = siz[son[x][0]] + cnt[x] + siz[son[x][1]])
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
	
	int find(int x)
	{
		int p = rt;
		while (val[p] != x)
			p = son[p][val[p] < x];
		return p;
	}
	
public:
	void ins(int x)
	{
		if (not rt)
			rt = ++tot;
		else
		{
			int p = rt, pfa;
			while (p)
			{
				pfa = p;
				if (val[p] == x)
				{
					cnt[p]++;
					update(p);
					splay(p);
					return;
				}
				p = son[p][val[p] < x];
			}
			son[pfa][val[pfa] < x] = ++tot;
			fa[tot] = pfa;
		}
		val[tot] = x;
		cnt[tot] = 1;
		update(tot);
		splay(tot);
	}
	
	void del(int x)
	{
		int p = find(x);
		cnt[p]--;
		update(p);
		splay(p);
	}
	
	std::pair <int, int> query(int x)
	{
		if (not rt)
			return { 0, x };
		
		int p = rt, pfa, ret = 0;
		while (p)
		{
			pfa = p;
			if (sum[son[p][0]] <= x)
			{
				x -= sum[son[p][0]];
				ret += siz[son[p][0]];
				if (x >= val[p] * cnt[p])
					x -= val[p] * cnt[p],
					ret += cnt[p],
					p = son[p][1];
				else
				{
					ret += x / val[p];
					x %= val[p];
					return { ret, x };
				}
			}
			else
				p = son[p][0];
		}
		splay(pfa);
		return { ret, x };
	}
#undef update
#undef get
} tr[2];

void ins(int l, bool col)
{
	tr[col].ins(l);
}

void del(int l, bool col)
{
	tr[col].del(l);
}

std::pair <int, std::array <int, 2> > query(int c0, int c1)
{
	auto r0 = tr[0].query(c0), r1 = tr[1].query(c1);
	return { r0.first + r1.first, { r0.second, r1.second } };
}
}

std::set <int> st;
bool col[MX];
int n, c[2], sum;

void init(int n, int c0, int c1)
{
	solve::n = n;
	c[0] = c0; c[1] = c1;
}

void set(int p, bool x)
{
	c[col[p] = x]--;
	auto it = st.lower_bound(p);
	if (it != st.begin() and it != st.end())
	{
		int l = *prev(it), r = *it;
		if (col[l] == col[r])
			tr::del(r - l - 1, col[l]),
			sum -= 2;
		else
			sum--;
	}
	if (it != st.end())
	{
		int r = *it;
		if (col[p] == col[r])
			tr::ins(r - p - 1, col[p]),
			sum += 2;
		else
			sum++;
	}
	if (it != st.begin())
	{
		int l = *prev(it);
		if (col[p] == col[l])
			tr::ins(p - l - 1, col[p]),
			sum += 2;
		else
			sum++;
	}
	st.insert(p);
}

void reset(int p)
{
	c[col[p]]++;
	st.erase(p);
	auto it = st.lower_bound(p);
	if (it != st.begin() and it != st.end())
	{
		int l = *prev(it), r = *it;
		if (col[l] == col[r])
			tr::ins(r - l - 1, col[l]),
			sum += 2;
		else
			sum++;
	}
	if (it != st.end())
	{
		int r = *it;
		if (col[p] == col[r])
			tr::del(r - p - 1, col[p]),
			sum -= 2;
		else
			sum--;
	}
	if (it != st.begin())
	{
		int l = *prev(it);
		if (col[p] == col[l])
			tr::del(p - l - 1, col[p]),
			sum -= 2;
		else
			sum--;
	}
}

int query()
{
	if (st.empty())
		return c[0] and c[1];
	else
	{
		auto pr = tr::query(c[0], c[1]);
		int cl = col[*st.begin()], cr = col[*st.rbegin()], ex = 2;
		if (pr.second[cl] >= *st.begin() - 1)
			pr.second[cl] -= *st.begin() - 1,
			ex--;
		if (pr.second[cr] >= n - *st.rbegin())
			pr.second[cr] -= n - *st.rbegin(),
			ex--;
		return sum - (pr.first << 1) + ex;
	}
}
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n = read(), m = read(), q = read(), c[2] = {};
	for (int t = n; t--; c[read() & 1]++);
	solve::init(n, c[0], c[1]);
	int op, p, b;
	while (m--)
	{
		p = read(), b = read();
		solve::set(p, b & 1);
	}
	while (q--)
	{
		op = read();
		p = read();
		if (op == 1)
			solve::reset(p);
		else
			solve::set(p, read() & 1);
		write(solve::query());
		putchar('\n');
	}
}
