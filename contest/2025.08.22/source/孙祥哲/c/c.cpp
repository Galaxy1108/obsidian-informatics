#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <random>
using namespace std;

const int N=5010;
int a[N][N], n, seed, vis[N];

void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}

int dfs(int x, int st, int h)
{
	if (x > n) x -= n;
	if (x == st && h)
	{
		for (int i = 1; i <= n+1; i++)
			if (!vis[i]) return i;	
	}
	int maxn = 0, p;
	for (int i = 1; i <= n+1; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1;
			int _ = dfs(x+1, st, h+1);
//			cout << "---" << st << " " << x << " " << i << " " << _ << '\n';
			if (a[x][_] > maxn)
				maxn = a[x][_], p = _;
			vis[i] = 0;
		}
	}
	return p;
}

signed main()
{
	freopen("c.in", "r", stdin); 
	freopen("c.out", "w", stdout);
	cin >> n >> seed;
	if (seed) gen(n, seed);
	else
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n+1; j++) cin >> a[i][j];
	}
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		cout << dfs(i, i, 0) << ' ';
	}
	return 0;
} 
