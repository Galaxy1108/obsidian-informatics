#include <cstdio>
#include <cstring>
#include <algorithm>
#define min(A, B) (A < B ? A : B)
#define max(A, B) (A < B ? B : A)

int read()
{
    char c = getchar();
    while (c < '0' or '9' < c)
    {
        c = getchar();
    }
    int ret = 0;
    while ('0' <= c and c <= '9')
    {
        ret = (ret << 3) + (ret << 1) + c - '0';
        c = getchar();
    }
    return ret;
}

const int MX = 200010;

int p[MX];

namespace solve
{
int pp[900][MX], r[MX];

void init(int n)
{
	int ppp = 1, rrr = n;
	memcpy(pp[0], p, sizeof(p));int sum = 0;
	for (int i = 1; ; i++)
	{
		int mx = 0;
		for (int j = 1; j <= n >> 1; j++)
		{
			mx = max(mx, pp[i - 1][j]);
		}
		pp[i - 1][n + 1] = 10000000;
		auto ptr = std::lower_bound(pp[i - 1] + (n >> 1) + 1, pp[i - 1] + n + 1, mx);
		for (; rrr >= ptr - pp[i - 1]; rrr--)
		{
			r[rrr] = i;
		}
		std::merge(pp[i - 1] + ppp, pp[i - 1] + (n >> 1) + 1, pp[i - 1] + (n >> 1) + 1, ptr, pp[i] + 1);
		bool fl = true;
		for (int j = 1; j <= n; j++)
		{
			if (pp[i - 1][j] != pp[i][j])
			{
				fl = false;
				// ppp = j;
				break;
			}
			else 
			{
				r[j] = i;
			}
		}
		if (fl) break;
		// for (int j = 1; j <= n; j++) printf("%d ", pp[i][j]);putchar('\n');
	}
}

int query(int t, int i)
{
	return pp[min(t, r[i])][i];
}
}

int main()
{
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
    int n, q, t, p;
    n = read();
    q = read();
	for (int i = 1; i <= n; ::p[i++] = read());
	solve::init(n);
	while (q--)
	{
		t = read();
		p = read();
		printf("%d\n", solve::query(t, p));
	}
}
