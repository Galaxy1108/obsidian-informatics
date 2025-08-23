#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define int long long
#define mod 998244353
using namespace std;

int n, num, q;
long long a[2000005], s[2000005], mul[2000005];

int find(int x, int y)//1~xÕÒy
{
	if (x == 1 || !y) return 0;
	int p = lower_bound(s+1, s+1+x, y)-s;
	return (find(p, y-a[p])+mul[p])%mod; 
} 

signed main()
{
	freopen("imperishable.in", "r", stdin);
	freopen("imperishable.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> num >> n; mul[0] = 1;
	for (int i = 1; i <= n; i++) cin >> a[i], mul[i] = mul[i-1]*2%mod;
	cin >> q;
	for (int _ = 0, x, y; _ <= q; _++)
	{
		if (_ > 0) cin >> x >> y, a[x] = y;
		long long maxn = 0, p;
		for (int i = 1; i <= n; i++)
		{
			s[i] = s[i-1] + a[i];
			if (a[i] > maxn) maxn = a[i], p = i;
		}
		cout << find(p, maxn)%mod << '\n';
	}
	return 0;
}
