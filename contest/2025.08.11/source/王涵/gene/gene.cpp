#include <cstdio>
#include <vector>
#define min(A, B) (A < B ? A : B)

const int MX = 1000010;

int a[MX];

namespace solve
{
bool vis[MX];
int cnt[MX], cr[MX];

int solve(int n, int l, int r)
{
	std::vector <int> vl, vr;
	for (int i = l; i <= r; vis[a[i++]] = true);
	for (int i = 1; i < l; i++)
		if (not vis[a[i]])
			cnt[a[i]]++;
	for (int i = r + 1; i <= n; i++)
		if (not vis[a[i]])
			cr[a[i]]++;
	for (int i = 1; i < l; i++)
		if (cnt[a[i]] == 1)
			vl.push_back(i);
	for (int i = n; i > r; i--)
		if (cr[a[i]] == 1)
			vr.push_back(i);
st:
	if (vl.empty() or vr.empty())
		return -1;
	else
	{
		if (a[vl.back()] != a[vr.back()])
			return vr.back() - vl.back() + 1;
		else
		{
			vl.pop_back();
			vr.pop_back();
			goto st;
		}
	}
}
}

int main()
{
	freopen("gene.in", "r", stdin);
	freopen("gene.out", "w", stdout);
	int n, l, r;
	scanf("%d%d%d", &n, &l, &r);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	printf("%d", solve::solve(n, l, r));
}
