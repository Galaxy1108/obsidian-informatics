#include <bits/stdc++.h>
#define int long long
using namespace std;

int T, p, b;
int num[100], len, cur, res[100];

bool check(int x, int k)
{
	int y = x;
	len = 0, cur = 0;
	while (x) num[++len] = x%b, x/=b;
//	for (int i = len; i >= 1; i--) cout << num[i] << " ";
//	puts("");
	for (int i = 1; i <= len; i+=k)
	{
		int t = 0;
		for (int j = min(len, i+k-1); j >= i; j--) t = t*b+num[j];
		if (cur % 2 == 1) res[++cur] = t%p==0 ? 0 : p-t%p;
		else res[++cur] = t%p==0 ? 0 : t%p;
	}
	int t = 0;
	for (int i = 1; i <= cur; i++) t = t*b+res[i];
	return (t%p==0) == (y%p==0);
}

signed main()
{
	srand(time(0));
	freopen("calc.in", "r", stdin);
	freopen("calc.out", "w", stdout);
	cin >> T >> p;
	while (T--)
	{
		bool f = 0;
		cin >> b;
//		cout << check(70812, 2) << '\n';
		int r = p;
		if (p > 3 && p < 10) r = p/2;
		if (p > 10 && p <= 100) r = p/10;
		for (int i = 1; i <= r; i++)
		{
			bool t = 1;
			for (int j = 1e9; j <= 1e9+1e5 && t; j++) t &= check(j, i);
			if (t) { cout << i << '\n'; f = 1; break; }
		}
		if (!f) puts("-1");
	}
	return 0;
}
/*
10 3
22
19
11
20
19
11
7
15
29
16

*/
