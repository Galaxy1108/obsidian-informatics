#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

long long T, s, k, ans[1000005], cur;
bool f[1000005];

int main()
{
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	cin >> T;
	while (T--)
	{
		cin >> s >> k;
		if (s % 2 == 1)
		{
			if (k*2 >= s) cout << "-1\n";
			else cout << k * 2 << endl;
		}
		else
		{
			cur = 0;
			for (int i = 1; i <= s; i++) f[i] = s%i==0;
			for (int i = 3; i <= s; i++)
			{
				if (f[i]) continue;
				ans[++cur] = i;
				for (int j = 1; i*j <= s; j++) f[s-i*j] = 1;
			}
			cout << (k>cur?-1:ans[k]) << endl;
		}
	}
	return 0;
} 
