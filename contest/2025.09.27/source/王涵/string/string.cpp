#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define min(A, B) (A < B ? A : B)
#define minx(A, B) (A = min(A, B))
#define INF 0x3f3f3f3f

inline int max(const int& a, const int& b)
{
	return a < b ? b : a;
}

const int MX = 410;

char s[MX];

namespace solve
{
int f[2][MX][MX][3];
std::vector <int> pos[3];

int solve()
{
	memset(f[1], 0x3f, sizeof(f[1]));
	int n = strlen(s + 1);
	for (int i = 1; s[i]; i++)
		pos[s[i] - '0'].push_back(i);
	if (not pos[0].empty())
		f[1][1][0][0] = 0;
	if (not pos[1].empty())
		f[1][0][1][1] = 0;
	if (not pos[2].empty())
		f[1][0][0][2] = 0;
	for (int i = 2, p; s[i]; i++)
	{
		p = i & 1;
		memset(f[p], 0x3f, sizeof(f[p]));
		for (int s0 = 0; s0 < i; s0++)
			for (int s1 = 0; s0 + s1 < i; s1++)
			{
				int s[3] = { s0, s1, i - 1 - s0 - s1 };
				for (int x = 0; x < 3; x++)
					if (f[p ^ 1][s0][s1][x] < INF)
						for (int z = 0; z < 3; z++)
							if (x != z and s[z] < pos[z].size())
							{
								int pp = pos[z][s[z]], c = max(s[0] - (lower_bound(pos[0].begin(), pos[0].end(), pp) - pos[0].begin()), 0) +
									max(s[1] - (lower_bound(pos[1].begin(), pos[1].end(), pp) - pos[1].begin()), 0) +
									max(s[2] - (lower_bound(pos[2].begin(), pos[2].end(), pp) - pos[2].begin()), 0);
								minx(f[p][s0 + (z == 0)][s1 + (z == 1)][z], f[p ^ 1][s0][s1][x] + c);
							}
			}
	}
	int t = min(min(f[n & 1][pos[0].size()][pos[1].size()][0], f[n & 1][pos[0].size()][pos[1].size()][1]), f[n & 1][pos[0].size()][pos[1].size()][2]);
	return t < INF ? t : -1;
}
}

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%s", s + 1);
	printf("%d", solve::solve());
}
