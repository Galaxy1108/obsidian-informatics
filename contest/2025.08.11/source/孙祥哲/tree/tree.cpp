#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node { long long x, y; }a[500005];
bool cmp(Node x, Node y)
{
	if (1.0*x.x/x.y != 1.0*y.x/y.y) return 1.0*x.x/x.y < 1.0*y.x/y.y;
	else return x.y < y.y;
}

int n, fa[500005], cur;
vector<int> v[500005]; 
long long w[500005];

void dfs(int x)
{
	Node b[1005] = {};
	a[x].x = w[x], a[x].y = 1, cur = 0;
	for (int i : v[x])
	{
		dfs(i);
		b[++cur] = a[i];
	}
	if (!cur) return;
	sort(b + 1, b + 1 + cur, cmp);
//	cout << "-------------------------\n";
//	cout << x << ":" << cur << endl;
	for (int i = 1; i <= cur; i++)
	{
//		cout << b[i].x << '/' << b[i].y << endl;
			if (1.0*b[i].x/b[i].y >= 1.0*a[x].x/a[x].y)
				a[x].x += b[i].x, a[x].y += b[i].y;
	}
//	cout << "-------------------------\n";
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 2; i <= n; i++) cin >> fa[i], v[fa[i]].push_back(i);
	for (int i = 1; i <= n; i++) cin >> w[i];
	dfs(1);
	for (int i = 1; i <= n; i++) printf("%.10lf\n", 1.0*a[i].x/a[i].y);
	return 0;
} 
