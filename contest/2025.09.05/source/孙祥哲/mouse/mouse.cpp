#include <bits/stdc++.h>
#define ld __float128
#define mod 9999973
using namespace std;

int n, m;
ld f[1005][1005];

ld dfs(int a, int b)
{
	if (a < 0 || b < 0) return 0;
	if (a == 0 && b == 0) return 0;
	if (a == 0) return 0;
	if (b == 0) return 1;
	if (f[a][b] != -1) return f[a][b];
	return f[a][b] = (ld)1*a/(a+b) + (ld)1*b/(a+b)*(b-1)/(a+b-1)*(dfs(a-1,b-2)*a/(a+b-2)+dfs(a,b-3)*(b-2)/(a+b-2));
}

int main()
{
	freopen("mouse.in", "r", stdin);
	freopen("mouse.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = -1;
	printf("%.9Lf", (long double)dfs(n, m));
	return 0;
}
