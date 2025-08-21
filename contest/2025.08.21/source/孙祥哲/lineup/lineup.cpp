#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int n, h[55], t[55];
int to[55], ans;

bool check()
{
	for (int i = 2; i <= n; i++)
		if (h[i-1] > h[i]) return 0;
	return 1;
}

int main()
{
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i], t[i]=h[i];
	sort(t+1, t+1+n);
	int lst = 1;
	for (int i = 1; i <= n+1; i++)
	{
		if (t[i] != t[lst])//lst~i-1
		{
			int cur = 0;
			for (int j = 1; j < i; j++)
				if (h[j] == t[lst]) to[j] = lst + cur++;
			cur = 0;
			for (int j = i; j <= n; j++)
				if (h[j] == t[lst]) to[j] = i-1 - cur++;
			lst = i;
		}
	}
	while (!check())
	{
		for (int i = 1; i <= n; i++)
		{
			bool flag = 0;
			for (int j = i+1; j <= n; j++)
			{
				if (to[i] >= j && to[j] <= i)
				{
					swap(to[i], to[j]), swap(h[i], h[j]);
					ans += 2*(j-i);
					flag = 1; break;
				}
			}
			if (flag) break;
		}
	}
	cout << ans;
	return 0;
} 
