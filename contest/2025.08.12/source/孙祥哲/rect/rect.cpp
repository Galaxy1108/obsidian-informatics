#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, col;
char ch;
int ans[505][505];
bool a[505][505], can[505][505];

int main()
{
	freopen("rect.in", "r", stdin);
	freopen("rect.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> ch, ans[i][j] = a[i][j] = ch=='C'?1:0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (!a[i][j]) continue;
			memset(can, 1, sizeof(can));
			for (int x = i; x <= n; x++)
				for (int y = j; y <= m; y++)
					can[x][y] = 0;
			can[i][j] = 1;
			for (int x = i; x <= n; x++)
				for (int y = j; y <= m; y++)
					if (i!=x || j!=y)
					{
//						printf("(%d,%d):%d,%d,%d\n", x, y, can[x-1][y], can[x][y-1], a[x][y]);
						can[x][y] = can[x-1][y]&&can[x][y-1]&&a[x][y];
					}
			int maxn = -1e9, xx, yy;
			for (int x = i; x <= n; x++)
				for (int y = j; y <= m; y++)
				{
					if (can[x][y] && (x-i+1)*(y-j+1) > maxn)
						xx = x, yy = y;
				}
			col++;
			for (int x = i; x <= xx; x++)
				for (int y = j; y <= yy; y++)
					ans[x][y] = col, a[x][y] = 0;
//			for (int i = 1; i <= n; i++)
//			{
//				for (int j = 1; j <= m; j++)
//					cout << can[i][j];
//				cout << '\n';
//			}
//			cout << '\n';
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
	return 0;
} 
