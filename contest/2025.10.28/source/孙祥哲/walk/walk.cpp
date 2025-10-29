#include <bits/stdc++.h>
using namespace std;

int n, a[200005], s[200005], cnt[200005];

int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= 2;
        s[i] = s[i-1] + a[i];
    }
	int ans = 1e9;
    if (n <= 1e3)
    {
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j = max(j+1, i-ans))
				ans = min(ans, j-i+1-2*(s[j]-s[i-1]));
	}
	else
	{
		mt19937 rd(1919810);
		for (int _ = 1; _ <= 1.5e8; _++)
		{
			int i = rd() % n;
			int j = i + rd() % (n-i+1);
			ans = min(ans, j-i+1-2*(s[j]-s[i-1]));
		}
	}
	cout << s[n]+ans;
    return 0;
}
