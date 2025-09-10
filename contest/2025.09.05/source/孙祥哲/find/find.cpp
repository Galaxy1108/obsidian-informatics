#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

int n, m;
int a[1005][1005];
vector<int> v;

int func(int x)
{
	int mul = 1;
	while (x)
	{
		mul *= x%10;
		x /= 10;
	}
	return mul <= n ? mul : 0;
}
bool cmp(int a, int y) { return a > y; }

int main()
{
	freopen("find.in", "r", stdin);
	freopen("find.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[func(i)][func(j)]++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			v.push_back(a[i][j]);
	sort(v.begin(), v.end(), cmp);
	ll sum = 0;
	for (int i = 0; i < m; i++) sum = (sum+v[i])%mod;
	cout << sum % mod;
	return 0;
}
