#include <cstdio>
#define mod 998244353

using namespace std;

int a[200005], sum[200005], pow2[200005];

int main()
{
	freopen("imperishable.in", "r", stdin);
	freopen("imperishable.out", "w", stdout);
	int t, n, i, q, mx, ans = 0, x, y;
	pow2[0] = 1;
	scanf("%d%d", &t, &n);
	for(i = 1; i <= n; i++)
		pow2[i] = 2ll * pow2[i - 1] % mod;
	for(i = 1; i <= n; i++)
		scanf("%d", a + i);
	for(i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + a[i];
		if(a[i] > mx)
			mx = a[i];
	}
	for(i = n; i >= 1; i--)
		if(sum[i - 1] < mx)
		{
			mx -= a[i];
			ans = (ans + pow2[i]) % mod;
		}
	printf("%d\n", ans);
	scanf("%d", &q);
	while(q--)
	{
		scanf("%d%d", &x, &y);
		a[x] = y;
		ans = mx = 0;
		for(i = 1; i <= n; i++)
		{
			sum[i] = sum[i - 1] + a[i];
			if(a[i] > mx)
				mx = a[i];
		}
		for(i = n; i >= 1; i--)
			if(sum[i - 1] < mx)
			{
				mx -= a[i];
				ans = (ans + pow2[i]) % mod;
			}
		printf("%d\n", ans);
	}
	return 0;
}