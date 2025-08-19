#include <cstdio>
#include <vector>
#include <cstring>
typedef long long intt;

const int MX = 100010, P = 1e9 + 7, V = 70, MXV = V + 5;

int a[MX];

namespace solve
{
const int pri[] = { 2, 3, 5, 7, 1, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67 }, R = 4, G = 15;

int f[MXV][1 << R];
std::vector <int> vec[MXV];

namespace DP
{
int f[2][2][1 << R];

void DP(int b)
{
	int p = 0, st;
	memset(f[0], 0, sizeof(f[0]));
	f[0][0][0] = 1;
	for (int x : vec[b])
	{
		p ^= 1;
		st = 0;
		for (int i = 0, t = x; i < R; i++)
			while (not (t % pri[i])) t /= pri[i], st ^= 1 << i;
		memcpy(f[p], f[p ^ 1], sizeof(f[p]));
		for (int i = 0; i < 1 << R; i++)
		{
			(f[p][1][i ^ st] += f[p ^ 1][0][i]) %= P;
			(f[p][0][i ^ st] += f[p ^ 1][1][i]) %= P;
		}
	}
	memcpy(solve::f[b], f[vec[b].size() & 1][0], sizeof(f[0][0]));
	if (b == 1)
		for (int i = 0; i < 1 << R; i++)
			(solve::f[b][i] += f[vec[b].size() & 1][1][i]) %= P;
}
}

int tf[1 << R];

int solve(int n)
{
	for (int i = 1, t; i <= n; i++)
	{
		t = a[i];
		for (int j = 0; j < R; j++)
			while (not (t % pri[j])) t /= pri[j];
		vec[t].push_back(a[i]);
	}
	for (int i = 0; i <= G; i++)
	{
		DP::DP(pri[i + R]);
	}
	for (int i = 1; i <= G; i++)
	{
		for (int s = 0; s < 1 << R; s++)
		{
			for (int t = 0; t < 1 << R; t++)
			{
				(tf[s ^ t] += (intt)f[pri[i + R]][s] * f[pri[i - 1 + R]][t] % P) %= P;
			}
		}
		memcpy(f[pri[i + R]], tf, sizeof(tf));
		memset(tf, 0, sizeof(tf));
	}
	return f[pri[G + R]][0] - 1;
}
}

int main()
{
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	printf("%d", solve::solve(n));
}
