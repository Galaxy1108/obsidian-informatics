#include <cstdio>
#include <unordered_map>
#include <set>
#include <queue>
typedef long long intt;

const int MX = 100010, P = 1e9 + 7;

namespace solve
{
std::unordered_map <intt, intt> f[MX][2];
int dgt[MX];

void DFS(int i, bool fl)
{
	for (int z = 1; fl ? z <= dgt[i] : z < 10; z++)
		for (auto pr : f[i - 1][fl and z == dgt[i]])
			f[i][fl][pr.first * z] += pr.second;
}

int solve(intt n, int k)
{
	std::unordered_map <intt, intt> mp;
	f[0][0][1] = f[0][1][1] = 1;
	for (int i = 1; n; i++)
	{
		dgt[i] = n % 10;
		DFS(i, false);
		DFS(i, true);
		n /= 10;
		for (auto pr : f[i][not n])
			mp[pr.first] += pr.second;
	}
	std::multiset <intt, std::greater <intt> > st;
	for (auto pr : mp)
		st.insert(pr.second);
	static intt cc[MX];
	static int rr[MX];
	int r = 0;
	for (auto x : st)
	{
		cc[++r] = x;
		if (r == k)
			break;
	}
	std::priority_queue <std::pair <intt, int> > q;
	for (int i = 1; i <= k; i++)
		q.push({ cc[i] * cc[rr[i] = 1], i });
	
	int p, ret = 0;
	while (k-- and not q.empty())
	{
		p = q.top().second;
		q.pop();
		
		(ret += cc[p] * cc[rr[p]] % P) %= P;
		if (++rr[p] <= r)
			q.push({ cc[p] * cc[rr[p]], p });
	}
	return ret;
}
}

int main()
{
	freopen("find.in", "r", stdin);
	freopen("find.out", "w", stdout);
	intt n;
	int k;
	scanf("%lld%d", &n, &k);
	printf("%d", solve::solve(n, k));
}
