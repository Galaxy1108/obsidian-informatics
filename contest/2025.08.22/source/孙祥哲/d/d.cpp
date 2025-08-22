#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int T, n, q, l, r, qwq, _;
int x[100005];

signed main()
{
	freopen("d.in", "r", stdin); 
	freopen("d.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> n; _ = 1;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 3; i <= n; i++)
			if (x[i]-x[i-1] != x[i-1]-x[i-2]) _ = 0;
		cin >> q;
		while (q--)
		{
			cin >> l >> r;
			if (_)
			{
				if (l == r) cout << "0 " << x[l] << " 1\n";
				else cout << x[l+1]-x[l] << " " << x[l] << " 1\n";
				continue;
			}
			qwq = 0;
			for (int c = 1; !qwq && c <= 10; c++)
			for (int a = 0; !qwq && a <= 10; a++)
			for (int b = 0; !qwq && b <= 10; b++)
			{
				bool f = 1;
				for (int i = l; i <= r; i++) if (((i-l)*a+b)/c!=x[i]) { f = 0; break; }
				if (f) { qwq = 1, cout << a << " " << b << " " << c << '\n'; break; }
			}
		}
	}
	return 0;
} 
/*
2
5
1000 1010 1020 1030 1040
5
1 1
2 2
1 3
3 5
1 5
*/
