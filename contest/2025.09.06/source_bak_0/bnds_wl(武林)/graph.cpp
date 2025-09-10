#include <cstdio>

using namespace std;

int f[100005], sum[100005];
int getf(int x)
{
	return (x == f[x]) ? x : (f[x] = getf(f[x]));
}
void un(int x, int y)
{
	int fx = getf(x), fy = getf(y);
	if(fx == fy)
	{
		sum[fx]++;
		return ;
	}
	sum[fx] += sum[fy] + 1;
	f[fy] = fx;
}

int main()
{
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	int n, m, i, x, y, ans = 0;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i++)
		f[i] = i;
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d", &x, &y);
		un(x, y);
	}
	for(i = 1; i <= n; i++)
		if(f[i] == i)
			ans += sum[i] / 2; 
	printf("%d\n", ans);
	return 0;
}