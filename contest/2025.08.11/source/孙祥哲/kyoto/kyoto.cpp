#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int a[10005], b[10005];
long long f[1005][1005];

int main()
{
	freopen("kyoto.in", "r", stdin);
	freopen("kyoto.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	memset(f, 0x3f, sizeof(f)); f[1][1] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			f[i][j] = min(f[i][j], min(f[i-1][j]+b[j], f[i][j-1]+a[i]));
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= m; j++) printf("%9lld ", f[i][j]);
//		puts("");
//	}
	cout << f[n][m];
	return 0;
} 
