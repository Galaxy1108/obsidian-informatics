#include <bits/stdc++.h>
#define ll long long
#define lll __int128
using namespace std;

int T, m, s, n, a[300], cnt = 0;

void dfs(int x, int sum)
{
	if (x > m)
	{
		if (sum == s) cnt++;
		return;
	}
	for (int i = 1; i <= n; i++)
		dfs(x+1, sum+a[i]);
}

int main()
{
	freopen("give.in", "r", stdin);
	freopen("give.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> m >> s >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		if (n > 5 && m > 5) cout << "0\n";
		else 
		{
			cnt = 0;
			dfs(1, 0);
			cout << cnt%2 << '\n';
		}
	}
	return 0;
} 
