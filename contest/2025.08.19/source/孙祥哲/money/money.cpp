#include <bits/stdc++.h>
#define ld double 
using namespace std;

int n, cost;
ld w[2005], c[2005], d[2005], f[2005][2], s[2005];

int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	cin >> n >> cost;
	for (int i = 1; i <= n; i++) cin >> w[i] >> c[i] >> d[i], s[i]=s[i-1]+w[i];
	f[1][0] = w[1], f[1][1] = w[1]*c[1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			f[i][0] = max(f[i][0], max(f[j][0], f[j][1]*d[i]-cost) + s[i] - s[j]);
			f[i][1] = max(f[i][1], max(f[j][0]*c[i], f[j][1]) + (s[i]-s[j])*c[i]);
		}
//		cout << f[i][0] << " " << f[i][1] << '\n';
	}
	printf("%.4lf", max(f[n][0], f[n][1]*d[n]-cost));
	return 0;
} 
