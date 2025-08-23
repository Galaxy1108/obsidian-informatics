#include <cstdio>
#include <set>

using namespace std;

set<int> r[50005], c[50005];

int main()
{
	freopen("corridor.in", "r", stdin);
	freopen("corridor.out", "w", stdout);
	int tp, n, m, k, i, x, y, Q, q, ps;
	scanf("%d%d%d%d", &tp, &n, &m, &k);
	for(i = 1; i <= k; i++)
	{
		scanf("%d%d", &x, &y);
		r[x].insert(y);
		c[y].insert(x);
	}
	for(i = 1; i <= n; i++)
		r[i].insert(m + 1);
	for(i = 1; i <= m; i++)
		c[i].insert(n + 1);
	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d%d%d", &tp, &x, &y);
		if(tp == 1)
		{
			r[x].insert(y);
			c[y].insert(x);
		}
		else
		{
			scanf("%d", &q);
			ps = (!y);
			while(q--)
			{
				if(ps == 0)
				{
					x = (*c[y].upper_bound(x));
					if(x == n + 1)
						break;
				}
				if(ps == 1)
				{
					y = (*r[x].upper_bound(y));
					if(y == m + 1)
						break;
				}
				ps = !ps;
			}
			printf("%d %d\n", x, y);
		}
	}
	return 0;
}