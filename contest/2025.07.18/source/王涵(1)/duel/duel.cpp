#include <cstdio>
#define max(A, B) (A < B ? B : A)
#define abs(x) (x < 0 ? -(x) : x)

const int MX = 200010, MXT = MX << 1, LG = 6, B = 1 << LG, MXLG = LG + 5;

int a[MX];

namespace solve
{
int d[MXT][MXLG];

void build(int l, int r)
{
	for (int i = l; i <= r; d[i][0] = a[i], i++);
	for (int j = 1; j <= LG; j++)
	{
		for (int i = l; i <= r; i++)
		{
			d[i][j] = abs(d[i][j - 1] - d[i + (1 << (j - 1))][j - 1]);
		}
	}
}

void set(int p, int x)
{
	a[p] = x;
	build(max(p - B + 1, 1), p);
}

void init(int n)
{
	build(1, n);
}

int query(int p, int k)
{
	if (k <= LG)
	{
		return d[p][k];
	}
	else
	{
		static int t[MX];
		for (int i = 0, pt = 0; i < 1 << k; i += B, pt++)
		{
			t[pt] = d[p + i][LG];
		}
		k -= LG;
		for (int j = 1; j <= k; j++)
		for (int i = 0; i < 1 << k; i++)
		{
			t[i] = abs(t[i] - t[i + (1 << (j - 1))]);
		}
		return t[0];
	}
}
}

int main()
{
	freopen("duel.in", "r", stdin);
	freopen("duel.out", "w", stdout);
	int n, q, op, p, k;
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; scanf("%d", a + i++));
	solve::init(n);
	while (q--)
	{
		scanf("%d%d%d", &op, &p, &k);
		if (op == 1)
		{
			solve::set(p, k);
		}
		else
		{
			printf("%d\n", solve::query(p, k));
		}
	}
}
