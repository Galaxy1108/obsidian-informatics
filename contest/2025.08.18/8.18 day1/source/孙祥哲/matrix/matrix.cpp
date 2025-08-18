#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, k;
int a[105][5], f[105][15], ans[15];

int main()
{
	 freopen("matrix.in", "r", stdin);
	 freopen("matrix.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= m; j++)
    		cin >> a[i][j];
    if (m == 1)
    {
    	for (int i = 1; i <= n; i++)
    	{
    		f[i][1] = max(f[i-1][1]+a[i][1], a[i][1]);
    		for (int j = 2; j <= min(i, k); j++)
    			f[i][j] = max(f[i-1][j]+a[i][1], ans[j-1]+a[i][1]);
    		for (int j = 1; j <= k; j++) ans[j] = max(ans[j], f[i][j]);
//    		for (int j = 1; j <= k; j++) cout << f[i][j] << " ";
//    		cout << '\n'; 
		}
	}
	cout << ans[k];
	return 0;
}
/*
7 1 2
1 2 1 -1 -1 1 1
*/
