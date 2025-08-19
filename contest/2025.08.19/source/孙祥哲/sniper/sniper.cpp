#include <bits/stdc++.h>
using namespace std;

int v[30] = {0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int n, w[8005], u[8005], t[8005];
int f[8005][25][2];
bool f1, f2;
vector<int> lst, now;

int main()
{
	freopen("sniper.in", "r", stdin);
	freopen("sniper.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> u[i] >> t[i];
		w[i] = v[w[i]];
	}
	f[1][u[1]][1] = w[1];
	if (w[1] == 50)
	{
		for(int i = 1; i <= 20; i++) f[1][i][0] = f[1][i][1] = -1e9;
		f[1][u[1]][1] = w[1]; f1 = 1;
	}
	now.push_back(1);
	for (int i = 2; i <= n; i++)
	{
		if (t[i] != t[i-1])
		{
			lst = now, f2 = f1, now.clear(), now.push_back(i), f1 = 0;
			if (f2)
				for (int j = 0; j < lst.size(); j++)
				{
					int tmp = f[lst[j]][u[lst[j]]][1];
					for (int k = 1; k <= 20; k++)
						f[lst[j]][k][0] = f[lst[j]][k][1] = -1e9;
					if (w[lst[j]]==50) f[lst[j]][u[lst[j]]][1] = tmp;
				}
		}
		else now.push_back(i);
		if (w[i] == 50) f1 = 1;
		for (int qwq = 0; qwq < lst.size(); qwq++)
		{
			int p = lst[qwq];
			if (t[p]+1 == t[i]) f[i][u[p]][0] = max(f[i][u[p]][0],f[p][u[p]][1]);
			for (int k = 1; k <= 20; k++)
			{
				if (abs(u[i]-k) <= 2*(t[i]-t[p]))f[i][u[i]][1] = max(f[i][u[i]][1], f[p][k][0]+w[i]);
				if (abs(u[i]-k) <= 2*(t[i]-t[p]-2))f[i][u[i]][1] = max(f[i][u[i]][1], f[p][k][1]+w[i]);
			}
			for (int j = 1; j <= 20; j++)
			{
				for (int k = 1; k <= 20; k++)
				{
					if (abs(j-k) <= 2*(t[i]-t[p]))f[i][j][0] = max(f[i][j][0], f[p][k][0]);
					if (abs(j-k) <= 2*(t[i]-t[p]-2))f[i][j][0] = max(f[i][j][0], f[p][k][1]);
				}
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= 8; j++) cout << f[i][j][0] << " ";
//		cout << '\n';
//		for (int j = 1; j <= 8; j++) cout << f[i][j][1] << " ";
//		cout << "\n---------\n";
//	}
	int maxn = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 20; j++)
			maxn = max(maxn, max(f[i][j][0], f[i][j][1]));
	cout << maxn;
	return 0;
} 
