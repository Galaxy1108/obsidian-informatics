#include <cstdio>
#include <vector>
#include <map>

using namespace std;

vector<int> e[505], d[505];
map<int, int> mp[505];
int a[505];
int tmp[505], sz[505];
int ans[505][255][505], mx[505][505];
void dfs(int x, int f)
{
	int c = 0, p, i, j;
	for(auto y: e[x])
		if(y != f)
			dfs(y, x);
	for(auto z: d[x])
	{
		ans[x][++c][0] = z;
		sz[x] = 1;
		for(auto y: e[x])
			if(y != f)
			{
				for(i = 0; i < sz[x] + sz[y]; i++)
					tmp[i] = 0;
				if(!(a[y] % z))
				{
					p = mp[y][z];
					for(i = 0; i < sz[x]; i++)
						for(j = 0; j < sz[y]; j++)
							tmp[i + j] = max(tmp[i + j], ans[x][c][i] + ans[y][p][j] - z);
				}
				for(i = 0; i < sz[x]; i++)
					for(j = 0; j < sz[y]; j++)
						tmp[i + j + 1] = max(tmp[i + j + 1], ans[x][c][i] + mx[y][j]);
				sz[x] += sz[y];
				for(i = 0; i < sz[x]; i++)
					ans[x][c][i] = tmp[i];
			}
	}
	for(i = 0; i < sz[x]; i++)
		for(j = 1; j <= c; j++)
			if(ans[x][j][i] > mx[x][i])
				mx[x][i] = ans[x][j][i];
	
}

int main()
{
	freopen("plan.in", "r", stdin);
	freopen("plan.out", "w", stdout);
	int n, k, u, v, c, i, j;
	scanf("%d%d", &n, &k);
	for(i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(i = 1; i <= n; i++)
		scanf("%d", a + i);
	for(i = 1; i <= n; i++)
	{
		c = 0;
		for(j = 1; 1ll * j * j <= a[i]; j++)
			if(!(a[i] % j))
			{
				d[i].push_back(j);
				mp[i][j] = ++c;
				if(j * j != a[i])
				{
					d[i].push_back(a[i] / j); 
					mp[i][a[i] / j] = ++c;
				}
			}
	}
	dfs(1, 0);
	printf("%d\n", mx[1][k]);
	return 0;
}