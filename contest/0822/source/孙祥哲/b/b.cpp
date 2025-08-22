#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const long long inf = 0x3f3f3f3f3f3f3f3f;
int n, dis[3005][3005], vis[3005], flag, _;
long long d1[3005][3005];

long long dfs(int x, int minn)
{
	vector<int> v, t;
	for (int i = 1; i <= n; i++)
		if (i != x && !vis[i]) v.push_back(i);
	if (v.empty()) return minn;
	long long res = 1e18;
//	cout << "-------";
//	for (int i : v) cout << i << " "; puts("");
//	getchar(); 
	for (int i = 1; i < (1<<v.size()); i++)
	{
		t.clear();
		long long sum = 0;
		for (int j = 0; j < v.size(); j++)
			if ((i>>j)&1) t.push_back(v[j]);
//		cout << "---";
//		for (int j : t) cout << j << " "; puts("");
//		getchar(); 
		for (int j : t) vis[j] = 1;
		for (int j : t) sum += dfs(j, min(minn,dis[x][j]));
		for (int j : t) vis[j] = 0;
		res = min(res, sum);
	}
	return res+minn;
}

signed main()
{
	freopen("b.in", "r", stdin); 
	freopen("b.out", "w", stdout);
	cin >> n; flag = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i+1, x; j <= n; j++)
			cin >> x, dis[i][j] = dis[j][i] = x,
			flag=((x!=1&&x!=1e9)?0:flag),
			_=(x==1?1:_);
	if (flag)
	{
		for (int i = 1; i <= n; i++)
		{
			int __ = 0;
			for (int j = 1; j <= n; j++) if (dis[i][j] == 1) __ = 1;
			if (__) cout << n-1 << '\n';
			else
			{
				if (_) cout << 1000000000ll+n-2 << '\n';
				else cout << 1000000000ll*(n-1) << '\n';
			}
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			memset(vis, 0, sizeof(vis)); vis[i] = 1;
			cout << dfs(i, 1e9)-1000000000ll << '\n';
		}
	}
	return 0;
} 
/*
4
1000000000 1000000000 1000000000
1000000000 1000000000
1000000000
*/
