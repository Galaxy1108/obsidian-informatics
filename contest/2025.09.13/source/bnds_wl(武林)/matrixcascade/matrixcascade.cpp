#include <cstdio>
#include <algorithm>

using namespace std;

int wow[305][305], b[90005];
int tree[90005], lim, n, x, y;
void add(int x)
{
	int i;
	for(i = x; i <= lim; i += (x & -x))
		tree[i]++;
}
int qry(int x)
{
	int i, ans = 0;
	for(i = x; i; i -= (x & -x))
		ans += tree[i];
	return ans;
}
bool work()
{
	int i, j, cx, cy;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			b[(i - 1) * n + j] = wow[i][j];
	cx = 0;
	for(i = 1; i <= n * n; i++)
		tree[i] = 0;
	for(i = 1; i <= n * n; i++)
	{
		cx += qry(b[i]);
		add(b[i]);
	}
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			b[(j - 1) * n + i] = wow[i][j];
	cy = 0;
	for(i = 1; i <= n * n; i++)
		tree[i] = 0;
	for(i = 1; i <= n * n; i++)
	{
		cy += qry(b[i]);
		add(b[i]);
	}
	return cx == x && cy == y;	
}

int main()
{
	freopen("matrixcascade.in", "r", stdin);
	freopen("matrixcascade.out", "w", stdout);
	int t, i, j, k, cx, cy;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &n, &x, &y);
		lim = n * n;
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				wow[i][j] = (i - 1) * n + j;
		if(work())
		{
			printf("YES\n");
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					printf("%d%c", wow[i][j], " \n"[j == n]);
			continue; 
		}
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
				wow[i][j] = (j - 1) * n + i;
		if(work())
		{
			printf("YES\n");
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					printf("%d%c", wow[i][j], " \n"[j == n]);
			continue; 
		}
		for(i = 1; i <= n * n; i++)
			b[i] = i;
		for(k = 1; k <= 362880; k++)
		{
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					wow[i][j] = b[(i - 1) * n + j];
			if(work())
				break;
			next_permutation(b + 1, b + n * n + 1);
		}
		if(k < 362880)
		{
			printf("YES\n");
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					printf("%d%c", wow[i][j], " \n"[j == n]);
			continue; 
		}
		if(n <= 3)
		{
			printf("NO\n");
			continue;
		}
		for(k = 1; k <= 100000; k++)
		{
			random_shuffle(b + 1, b + n * n + 1);
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					wow[i][j] = b[(i - 1) * n + j];
			if(work())
				break;
		}
		if(k < 100000)
		{
			printf("YES\n");
			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++)
					printf("%d%c", wow[i][j], " \n"[j == n]);
			continue; 
		}
		printf("NO\n");
	}
	return 0;
}