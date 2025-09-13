#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read() {int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}

int n, q, lk, rk, s[2000005], x, y;
int f[2000005], pos[2000005], cur;
char a[2000005];

int find(int x) { if (f[x] != x) f[x] = find(f[x]); return f[x]; }
void merge(int x, int y) { f[find(y)] = find(x);  }

int main()
{
	freopen("virtual.in", "r", stdin);
	freopen("virtual.out", "w", stdout);
	n = read(), lk = read(), rk = read();
	scanf("%s", a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 'a') pos[++cur] = i+1;
		s[i+1] = s[i] + (a[i]=='a'), f[i+1] = i+1;
	}
	int lst = 0; a[n] = 'a';
	for (int i = 1; i <= n+1; i++)
	{
		if (a[i-1] == 'a')
		{
			for (int j = lst+2; j < i; j++) merge(lst+1, j);
			lst = i;
		}
	}
	for (int qwq = 0; (1<<qwq) <= rk-lk+1; qwq++)
	{
		int k = lk + (1<<qwq) - 1;
		for (int i = 1; i+k-1 <= cur; i++)
		{
			int l1 = pos[i-1]+1, r1 = pos[i];
			int l2 = pos[i+k-1], r2 = pos[i+k]-1;
			if (i+k > cur) r2 = n;
			merge(r1, l2);
			if (l1 < r1) merge(r1, l1);
			if (l2 < r2) merge(r1, l2+1);
		}
	}
	q = read();
	while (q--)
	{
		x = read(), y = read();
		if (find(x) == find(y)) puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
16 3 3
bbbbaabbbbaabbbb
0
*/
