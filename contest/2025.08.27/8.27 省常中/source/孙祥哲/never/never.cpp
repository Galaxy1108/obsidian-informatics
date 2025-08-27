#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll T, n, x, y, s, t;
int f[1000][100];

int main()
{
	freopen("never.in", "r", stdin);
	freopen("never.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n >> s >> t >> x >> y;
		if (x <= 100 && y <= 100 && abs(s) <= 100 && abs(t) <= 100)
		{
			for (int i = -200; i <= 200; i++) f[i+500][0] = (i>=t?i-x:i+y);
			for (int j = 1; j <= 63; j++)
				for (int i = -200; i <= 200; i++)
					f[i+500][j] = f[f[i+500][j-1]+500][j-1];
			for (int j = 0; j <= 63; j++)
				if ((n>>j)&1) s = f[s+500][j];
			cout << s << '\n';
		}
		else if (x == y)
		{
			ll res;
			if (s >= t)
			{
				ll _ = (s-t+x-1)/x;
				if (_ >= n) res = s - x*n;
				else
				{
					n -= _;
					s = s - _ * x;
					if (n % 2 == 0) res = s;
					else res = s + x;
				}
			}
			else
			{
				ll _ = (t-s)/x;
				if (_ >= n) res = s + x*n;
				else
				{
					n -= _;
					s = s + _ * x;
					if (n % 2 == 0) res = s;
					else res = s + x;
				}
			}
			cout << res << '\n';
		}
	}
	return 0;
} 
/*
1
119198101 92 90 2 2
*/
