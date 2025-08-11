#include <cstdio>
#include <unordered_map>
#include <map>
#include <queue>
#include <algorithm>
typedef long long intt;

const int MXK = 100010, MXW = 15, P = 1e9 + 7;

namespace solve
{
inline void md(int& x)
{
	x -= (x >= P) * P;
}

int num[MXW];
intt arr[MXK];
std::unordered_map <intt, intt> f[MXW][2];
bool vis[MXW][2];

void DFS(int p, bool fl)
{
	if (vis[p][fl])
		return;
	else vis[p][fl] = true;
	
	if (not p)
	{
		f[p][fl].insert({ 1, 1 });
	}
	else if (fl)
	{
		DFS(p - 1, false);
		DFS(p - 1, true);
		for (auto pr : f[p - 1][0])
		{
			for (int x = 1; x < num[p]; x++)
				f[p][1][pr.first * x] += pr.second;
		}
		for (auto pr : f[p - 1][1])
		{
			f[p][1][pr.first * num[p]] += pr.second;
		}
	}
	else
	{
		DFS(p - 1, false);
		for (auto pr : f[p - 1][0])
		{
			for (int x = 1; x <= 9; x++)
				f[p][0][pr.first * x] += pr.second;
		}
	}
}

int solve(intt n, int k)
{
	int tot = 0;
	while (n)
	{
		num[++tot] = n % 10;
		n /= 10;
	}
	DFS(tot, true);
	std::map <intt, intt> mp;
	for (int i = 1; i <= tot; i++)
		for (auto pr : f[i][i == tot])
			mp[pr.first] += pr.second;
	std::priority_queue <std::pair <intt, std::pair <int, int> > > pq;
	int cnt = 0;
	for (auto pr : mp)
		arr[++cnt] = pr.second;
	std::sort(arr + 1, arr + cnt + 1, std::greater <intt>());
	for (int i = 1; i <= k; i++)
		pq.push({ arr[i] * arr[i], { i, i } });
	int ret = cnt = 0;
	while (cnt < k)
	{
		auto t = pq.top();
		pq.pop();
		md(ret += t.first % P);
		cnt++;
		if (t.second.first != t.second.second and cnt < k)
			md(ret += t.first % P),
			cnt++;
		pq.push({ arr[t.second.first] * arr[t.second.second + 1], { t.second.first, t.second.second + 1 } });
	}
	return ret;
}
}

int main()
{
	freopen("gold.in", "r", stdin);
	freopen("gold.out", "w", stdout);
	intt n;
	int k;
	scanf("%lld%d", &n, &k);
	printf("%d", solve::solve(n, k));
}
