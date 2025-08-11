#include <iostream>
#include <algorithm>
#include <cstring> 
using namespace std;

int n, m, t1[20], t2[20];
bool del[2000]; 
char a[2000][2000];

void print(int u, int cen, int x, int y)
{
	if (cen == 2)
	{
		a[x][y+2] = 'o';
		if (!del[u*2]) a[x+2][y] = 'o', a[x+1][y+1] = '/';
		if (!del[u*2+1]) a[x+2][y+4] = 'o', a[x+1][y+3] = '\\';
		return;
	}
	int t = y + t2[cen-1];
	a[x][t] = 'o';
	for (int i = x+1; i <= x+t1[cen-1]-1; i++)
	{
		if (!del[u*2]) a[i][t-(i-x)] = '/';
		if (!del[u*2+1]) a[i][t+(i-x)] = '\\';
	}
	if (!del[u*2]) print(u*2, cen-1, x+t1[cen-1], y);
	if (!del[u*2+1]) print(u*2+1, cen-1, x+t1[cen-1], t+1);
}

int main()
{
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout); 
	cin >> m >> n;
	for (int i = 1, x, y; i <= n; i++)
		cin >> x >> y, del[(1<<(x-1))+y-1] = 1;
	t1[2] = 3, t2[2] = 5;
	for (int i = 3; i <= m; i++) t1[i] = t1[i-1]*2, t2[i] = t2[i-1]*2+1;
	for (int i = 1; i <= t1[m]; i++)
		for (int j = 1; j <= t2[m]; j++) a[i][j] = ' ';
	print(1, m, 1, 1);
	for (int i = 1; i <= t1[m]; i++)
	{
		for (int j = 1; j <= t2[m]; j++) putchar(a[i][j]);
		putchar('\n');
	}
	return 0;
} 
