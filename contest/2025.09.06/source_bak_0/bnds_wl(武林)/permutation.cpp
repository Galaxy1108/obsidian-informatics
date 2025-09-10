#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct node
{
	int x, s;
	node(int x0 = 0, int s0 = 0)
	{
		x = x0;
		s = s0;
	}
	friend bool operator < (node n1, node n2)
	{
		return n1.s < n2.s;
	}
};
int p[100005], q[100005];
node pd[100005], qd[100005];
bool vis[100005];
int h[100005];

int main()
{
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	int n, i, j, jp, jq, c, cp = 0, cq = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%d", p + i);
	for(i = 1; i <= n; i++)
		scanf("%d", q + i);
	memset(vis, 0, sizeof(vis));
	for(i = 1; i <= n; i++)
	{
		j = i;
		c = 0;
		while(!vis[j])
		{
			vis[j] = 1;
			++c;
			j = p[j];
		}
		if(c)
			pd[++cp] = node(i, c);
	}
	memset(vis, 0, sizeof(vis));
	for(i = 1; i <= n; i++)
	{
		j = i;
		c = 0;
		while(!vis[j])
		{
			vis[j] = 1;
			++c;
			j = q[j];
		}
		if(c)
			qd[++cq] = node(i, c);
	}
	if(cp != cq)
	{
		printf("NO\n");
		return 0;
	}
	sort(pd + 1, pd + cp + 1);
	sort(qd + 1, qd + cq + 1);
	for(i = 1; i <= cp; i++)
	{
		if(pd[i].s != qd[i].s)
			break;
		for(j = 1, jp = pd[i].x, jq = qd[i].x; j <= pd[i].s; j++, jp = p[jp], jq = q[jq])
			h[jp] = jq;
	}
	if(i <= cp)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(i = 1; i <= n; i++)
		printf("%d ", h[i]);
	printf("\n");
	return 0;
}