#include <cstdio>
#include <algorithm>
#define min(A, B) (A < B ? A : B)
#define max(A, B) (A < B ? B : A)
#define maxx(A, B) (A = max(A, B))
typedef __int128 intt;

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

void write(intt x)
{
	if (x >= 10)
		write(x / 10);
	putchar(x % 10 + '0');
}

const int MX = 2000010;

int h[MX];

namespace solve
{
int premx[MX], nxtmx[MX], premn[MX], nxtmn[MX];

intt solve(int n)
{
	static int stk[MX];
	for (int i = 1, top = 0; i <= n; i++)
	{
		while (top and h[stk[top]] >= h[i])
			top--;
		premn[i] = stk[top];
		stk[++top] = i;
	}
	stk[0] = n + 1;
	for (int i = n, top = 0; i; i--)
	{
		while (top and h[stk[top]] >= h[i])
			top--;
		nxtmn[i] = stk[top];
		stk[++top] = i;
	}
	for (int i = n, top = 0; i; i--)
	{
		while (top and h[stk[top]] <= h[i])
			top--;
		nxtmx[i] = stk[top];
		stk[++top] = i;
	}
	intt ret = stk[0] = 0;
	for (int i = 1, top = 0; i <= n; i++)
	{
		while (top and h[stk[top]] <= h[i])
			top--;
		int p = std::lower_bound(stk + 1, stk + top + 1, premn[i]) - stk;
		if (p <= top)
			maxx(ret, (intt)h[stk[p]] * h[i] * (min(nxtmn[i], nxtmx[stk[p]]) - premn[i] - 1));
		premx[i] = stk[top];
		stk[++top] = i;
	}
	for (int i = n, top = 0; i; i--)
	{
		while (top and h[stk[top]] <= h[i])
			top--;
		int p = std::lower_bound(stk + 1, stk + top + 1, nxtmn[i], std::greater <int> ()) - stk;
		if (p <= top)
			maxx(ret, (intt)h[stk[p]] * h[i] * (nxtmn[i] - max(premn[i], premx[stk[p]]) - 1));
		stk[++top] = i;
	}
	return ret;
}
}

int main()
{
	freopen("drama.in", "r", stdin);
	freopen("drama.out", "w", stdout);
	int n = read();
	for (int i = 1; i <= n; h[i++] = read());
	write(solve::solve(n));
}
