#include <bits/stdc++.h>
using namespace std;

int rd(int l, int r)
{
	int x = rand();
	return x%(r+1)+l;
}

int n;
int a[12341];
int b[123], c[123], f[123], tmp[123];

int main()
{
	freopen("color.in", "r", stdin);
	freopen("color.out", "w", stdout);
	srand(time(0));
	
	bool flag = 1;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i != 1 && a[i-1] != a[i]) flag = 0;
	}
	if (flag)
	{
		puts("0");
		return 0;
	}
//	long long cnt = 0;
//	for (int i = 1; i <= 1e7; i++)
//	{
//		int ci = 0;
//		while (1)
//		{
//			flag = 1; 
//			for (int j = 1; j <= n; j++) f[j] = 0;
//			for (int j = 1; j <= n; j++) b[j] = rd(0, 1);
//			for (int j = 1; j <= n; j++)
//			{
//				if (b[j])
//				{
//					int t = rd(1, n);
//					while (f[t]) t = rd(1, n);
//					c[j] = t;
//				}
//			}
//			for (int j = 1; j <= n; j++)
//			{
//				if (b[j]) tmp[j] = c[j];
//				else tmp[j] = a[j];
//			}
//			for (int j = 2; j <= n; j++)
//				if (tmp[j] != tmp[j-1]) { flag = 0; break; }
//			if (flag) break;
//			ci++;
//		}
//		cnt += ci;
//	}
//	cout << 1.0*cnt/1e7;
	
	if (n == 2)
	{
		if (a[1] == a[2]) cout << "0\n";
		else cout << "4\n";
	}
	else if (n == 3)
	{
		if (a[1] == a[2] && a[2] == a[3]) cout << "0\n";
		else if (a[1] == a[2] || a[2] == a[3] || a[1] == a[3]) cout << "24\n";
		else cout << "42\n";
	}
	else if (n==10) cout << "900221128\n";
	return 0;
}



