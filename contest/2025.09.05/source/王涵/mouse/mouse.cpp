#include <cstdio>

const int MX = 1010;

namespace solve
{
double f[MX][MX], g[MX][MX];

double solve(int w, int b)
{
	g[0][0] = 1;
	for (int i = 0; i <= w; i++)
		for (int j = not i; j <= b; j++)
			f[i][j] = (double)i / (i + j) + (j ? (double)j / (i + j) * (1 - g[i][j - 1]) : 0),
			g[i][j] = (double)i / (i + j) + (j ? (double)j / (i + j) * (1 - ((i ? (double)i / (i + j - 1) * f[i - 1][j - 1] : 0) + (j - 1 ? (double)(j - 1) / (i + j - 1) * f[i][j - 2] : 0))) : 0);
	return f[w][b];
}
}

int main()
{
	freopen("mouse.in", "r", stdin);
	freopen("mouse.out", "w", stdout);
	int w, b;
	scanf("%d%d", &w, &b);
	printf("%.9lf", solve::solve(w, b));
}
