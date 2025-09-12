#include <bits/stdc++.h>
using namespace std;

void read(int &n)
{
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x=x*10+ch-'0', ch=getchar();
	n = x;
}
void read(long long &n)
{
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x=x*10+ch-'0', ch=getchar();
	n = x;
}
void write(int x) {if(x>9)write(x/10);putchar(x%10+'0');}
void write(long long x) {if(x>9)write(x/10);putchar(x%10+'0');}

int T, n, m;
long long a[1000005];
vector<pair<int,int> > v[200005];

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	read(T);
	while (T--)
	{
		for (int i = 1; i <= n; i++) v[i].clear(), a[i] = 0;
		read(n), read(m);
		int _ = 1;
		for (int i = 1, x, y, z; i <= m; i++)
		{
			read(x), read(y), read(z);
			v[x].push_back({y,z}), v[y].push_back({x,z});
			a[y] += z;
			if (x != 1) _ = 0;
		}
		if (_)
		{
			sort(a+2, a+1+n);
			long long sum1 = a[1], sum2 = 0;
			for (int i = n; i >= 2; i--)
			{
				if ((n-i+1) % 2 == 1) sum2 += a[i];
				else sum1 += a[i];
			}
			write(sum1), putchar('\n');
		}
	}
	return 0;
} 
