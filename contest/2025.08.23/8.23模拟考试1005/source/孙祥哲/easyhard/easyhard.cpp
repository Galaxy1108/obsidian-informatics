#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

int n, m, p, ans;
bool f1[10000000];
long long f[2][6005][4];

void dfs(int x, int c1, int c2, int s)
{
	if (x > m) { f1[s] = 1; return; }
	if (c1)
	{
		dfs(x+1, c1-1, c2+1, (s<<2)+0);
		dfs(x+1, c1-1+1, c2, (s<<2)+1);
	}
	if (c2)
	{
		dfs(x+1, c1+1, c2-1, (s<<2)+3);
		dfs(x+1, c1, c2-1+1, (s<<2)+2);
	}
}

signed main()
{
	freopen("easyhard.in", "r", stdin);
	freopen("easyhard.out", "w", stdout);
	cin >> n >> m >> p;
	if (n <= 10 && m <= 10)
	{
		for (int i = 0; i <= n; i++) dfs(1, i, n-i, 0);
		for (int i = 0; i < (1<<(m*2)); i++) ans += f1[i];
		cout << ans%p; 
		return 0;
	}
	f[1][0][0] = f[1][1][1] = f[1][1][2] = f[1][2][3] = 1;
	for (int i = 2; i <= m; i++)
	{
		int v = i&1;
		for (int j = max(0,i-1-n); j <= min(2*i-2,i-1+n); j++)
		{
			int qu = max(1, abs(i-1-j));
			if (qu == n)
			{
				f[v][j+1][2] = (f[v][j+1][2]+f[!v][j][0]+f[!v][j][2])%p;
				f[v][j+2][3] = (f[v][j+2][3]+f[!v][j][0]+f[!v][j][2])%p;
				f[v][j+0][0] = (f[v][j+0][0]+f[!v][j][1]+f[!v][j][3])%p;
				f[v][j+1][1] = (f[v][j+1][1]+f[!v][j][1]+f[!v][j][3])%p;
			}
			else
			{
				long long t = f[!v][j][0]+f[!v][j][1]+f[!v][j][2]+f[!v][j][3];
				f[v][j+1][2] = (f[v][j+1][2]+t)%p;
				f[v][j+2][3] = (f[v][j+2][3]+t)%p;
				f[v][j+0][0] = (f[v][j+0][0]+t)%p;
				f[v][j+1][1] = (f[v][j+1][1]+t)%p;
			}
		}
//		for (int j = 0; j <= 2*i; j++) cout << f[v][j] << " ";
//		puts("");
	}
	long long sum = 0;
	for (int i = 0; i <= 2*m; i++) 
		sum = (sum+f[m&1][i][0]+f[m&1][i][1]+f[m&1][i][2]+f[m&1][i][3])%p;
	cout << sum;
	return 0;
} 
