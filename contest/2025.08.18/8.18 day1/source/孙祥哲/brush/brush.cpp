#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, a[10005], f[10005];
long long sum;
int min1 = 1e9, min2 = 1e9, p1, p2;

int gm(int l, int r)
{
	int minn = 1e9, p;
	for (int i = l; i <= r; i++)
		if (a[i] < minn) minn = a[i], p = i;
	return p;
}

int main()
{
	 freopen("brush.in", "r", stdin);
	 freopen("brush.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
    	cin >> a[i]; sum += a[i];
    	if (i > m) continue;
    	if (a[i] <= min1) min2 = min1, p2 = p1, min1 = a[i], p1 = i;
    	else if (a[i] <= min2) min2 = a[i], p2 = i;
	}
	if (m == 2) {cout << sum; return 0;}
	f[m] = a[p1]+a[p2];
	if (p1 > p2) swap(p1, p2);
	for (int r = m+1; r <= n; r++)
	{
		int l = r-m+1, t = 0;
		if (p1 < l) p1 = p2, p2 = gm(p1+1, r), t = 1;
		f[r] = f[r-1] + t*a[p2];
	}
	cout << f[n];
	return 0;
}
