#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;

long long n, m[100], a[100][100], hj[100], t[100];
long long x[100], minn = 5e18;

void dfs(int p)
{
	if (p > n)
	{
		long long sum = 0, cur = 0;
		for (int i = 1; i <= n; i++)
		{
			cur = 0;
			t[++cur] = 0, t[++cur] = 2e6;
			for (int j = x[i]; j <= m[i]; j++) t[++cur] = a[i][j];
			for (int j = 1; j < x[hj[i]]; j++) t[++cur] = a[hj[i]][j];
			sort(t+1, t+1+cur);
			for (int j = 1; j < cur; j++) sum += (t[j+1]-t[j])*(t[j+1]-t[j]);
		}
		minn = min(minn, sum);
		return; 
	} 
	for (int i = 1; i <= m[p]; i++)
		x[p] = i, dfs(p+1);
}

int main()
{
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout); 
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> m[i]; hj[i] = i+1;
		for (int j = 1; j <= m[i]; j++) cin >> a[i][j];
	}
	hj[n] = 1;
	dfs(1);
	cout << minn;
	return 0;
} 
