#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
using namespace std;

int n, m, p;
int f[2][3200][3200], s1[3200], s2[3200];

int qp(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (res*a)%p;
		a = (a*a)%p, b >>= 1;
	}
	return res;
}

signed main()
{
	freopen("a.in", "r", stdin); 
	freopen("a.out", "w", stdout);
	cin >> n >> m >> p;
	if (n == 1) { cout << (m+1)*m/2%p; return 0; }
	if (m == 1) { cout << 1; return 0; }
	for (int j = 1; j <= m; j++)
		for (int k = j; k <= m; k++)
			f[1][j][k] = 1;
	for (int i = 2; i <= n; i++)
	{
		int v = i&1;
		for (int j = 1; j <= m; j++)
		{
			s1[j] = s1[j-1];
			for (int k = 1; k <= j; k++) s1[j] = (s1[j]+f[!v][k][j])%p;
		}
		for (int j = m; j >= 1; j--)
		{
			s2[j] = s2[j+1];
			for (int k = j; k <= m; k++) s2[j] = (s2[j]+f[!v][j][k])%p;
		}
		for (int j = 1; j <= m; j++)
			for (int k = j; k <= m; k++)
				f[v][j][k] = (s1[m]-s1[j-1]-s2[k+1]+p)%p;
//		for (int j = 1; j <= m; j++)
//			for (int k = j; k <= m; k++)
//				printf("f[%d][%d][%d]:%d\n", i, j, k, f[v][j][k]);
//		for (int j = 1; j <= m; j++) cout << s1[j] << " "; puts("");
//		for (int j = 1; j <= m; j++) cout << s2[j] << " "; puts("");
	}
	int sum = 0;
	for (int j = 1; j <= m; j++)
		for (int k = j; k <= m; k++)
			sum = (sum+f[n&1][j][k])%p;
	cout << sum;
	return 0;
} 
