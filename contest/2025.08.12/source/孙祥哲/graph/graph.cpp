#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

int T, n, m, s, t, cur;
int f[1005][1005], p[1005][1005];
vector<int> v[1234];
vector<int> a[12341];

void dfs(int x, int id)
{
	for (int y : v[x])
	{
		if (f[x][y]==p[x][y]) continue;
		f[x][y]++,f[y][x]++;
		vector<int> qwq = a[id];
		qwq.push_back(y);
		a[++cur] = qwq;
		dfs(y, cur);
	}
}

int main()
{
	freopen("gragh.in", "r", stdin);
	freopen("gragh.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while (T--)
	{
		memset(p, 0, sizeof(p));
		cin >> n >> m;
		for (int i = 1, x, y; i <= m; i++)
			cin >> x >> y, v[x].push_back(y), v[y].push_back(x), p[x][y]++,p[y][x]++;
		int k = ceil(1.0 * m / (n-1));
		for (int s = 1; s <= n; s++)
		{
			for (int t = 1; t <= n; t++)
			{
				if (s == t) continue;
				cur = 0;
				vector<int> qw; qw.push_back(s);
				a[++cur] = qw;
				memset(f, 0, sizeof(f));
				dfs(s, 0);
				int cnt = 0;
				for (int i = 1; i <= cur; i++)
					if (a[i][a[i].size()-1] = t) cnt++;
				if (cnt >= k)
				{
					cout << s << " " << t << '\n';
					for (int i = 1; i <= cur && k; i++)
					{
						if (a[i][a[i].size()-1] = t)
						{
							k--;
							for (int j : a[i]) cout << j << " ";
							cout << '\n';
						}
					}
				}
			} 
		}
	} 
	return 0;
} 
