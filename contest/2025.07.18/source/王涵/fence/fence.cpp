#include <cstdio>
#include <map>
#include <algorithm>
typedef long long intt;

const int MX = 100010, P = 1e9 + 7;

struct node
{
	int w, h;
} rt[MX];

namespace solve
{
namespace sgt
{
std::map <intt, intt> mp;
int ret;

int f(std::pair <intt, intt> pr)
{
	intt n = pr.second - pr.first + 1;
	return (((__int128)n * (n - 1) >> 1) + n) % P;
}

void update(intt l, intt r)
{
	auto p = mp.lower_bound(l);
	if (p != mp.end() and p->first == r + 1 and p != mp.begin() and prev(p)->second == l - 1)
	{
		(ret += ((P - f(*p) + P - f(*prev(p))) % P + f({ prev(p)->first, p->second })) % P) %= P;
		std::pair <intt, intt> t = { prev(p)->first, p->second };
		mp.erase(prev(p));
		mp.erase(p);
		mp.insert(t);
	}
	else if (p->first == r + 1)
	{
		(ret += (P - f(*p) + f({ l, p->second })) % P) %= P;
		std::pair <intt, intt> t = { l, p->second };
		mp.erase(p);
		mp.insert(t);
	}
	else if (p != mp.begin() and prev(p)->second == l - 1)
	{
		(ret += (P - f(*prev(p)) + f({ prev(p)->first, r })) % P) %= P;
		std::pair <intt, intt> t = { prev(p)->first, r };
		mp.erase(prev(p));
		mp.insert(t);
	}
	else
	{
		(ret += f({ l, r })) %= P;
		mp.insert({ l, r });
	}
}

int query(intt l, intt r)
{
	int n = r - l + 1;
	return ret * ((((__int128)n * (n - 1) >> 1) + n + (__int128)(l - 1) * n) % P) % P;
}
}

struct node
{
	intt l, r;
	int h;
} ly[MX];

bool cmp(node& a, node& b)
{
	return a.h > b.h;
}

int solve(int n)
{
	intt pre = 0;
	for (int i = 1; i <= n; i++)
	{
		ly[i] = { pre, pre + rt[i].w - 1, rt[i].h };
		pre += rt[i].w;
	}
	std::sort(ly + 1, ly + n + 1, cmp);
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ly[i].h != ly[i - 1].h)
		{
			(ret += sgt::query(ly[i].h + 1, ly[i - 1].h)) %= P;
		}
		sgt::update(ly[i].l, ly[i].r);
	}
	return (ret + sgt::query(1, ly[n].h)) % P;
}
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", &rt[i++].h));
	for (int i = 1; i <= n; scanf("%d", &rt[i++].w));
	printf("%d", solve::solve(n));
}
