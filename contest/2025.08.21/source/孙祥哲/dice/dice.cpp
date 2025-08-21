#include <iostream>
#include <cstring>
#include <queue>
#define mod 1000000007ll
#define int long long
using namespace std;

int qp(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b&1) res = (res*a)%mod;
		a = (a*a)%mod, b >>= 1;
	}
	return res;
}
int inv(int x) { return qp(x, mod-2); }

int n, a[5005], sum;

void dfs(int x, int maxn)
{
	if (x > n) { sum += maxn; return; }
	for (int i = 1; i <= a[x]; i++) dfs(x+1, max(maxn, i));
}

signed main()
{
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	cin >> n;
	int mul = 1;
	for (int i = 1; i <= n; i++) cin >> a[i], mul *= a[i];
	dfs(1, 0);
	cout << sum * inv(mul) % mod;
	return 0;
} 
