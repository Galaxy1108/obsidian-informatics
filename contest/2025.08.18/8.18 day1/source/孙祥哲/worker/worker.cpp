#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, a[105];
int f[105][15][15][15], cnt[105][10];
char ch;

int fc(int x, int y, int z)
{
	return (x!=0)+(y!=0)+(z!=0);
}
int dfs(int p, int x, int y, int z)
{
	if (x + y + z > 10 || x < 0 || y < 0 || z < 0) return 0x3f3f3f3f;
	if (f[p][x][y][z] != 0x3f3f3f3f) return f[p][x][y][z];
	for (int i = max(10, p-10); i < p; i++)
	{
		int a=cnt[p][1]-cnt[i][1],b=cnt[p][2]-cnt[i][2],c=cnt[p][3]-cnt[i][3];
		if (p == n || x + y + z == 10)
		{
			if (a > x || b > y || c > z) continue;
			a = x-a, b = y-b, c = z-c;
			if (fc(a,b,c) > fc(x,y,z)) continue;
			f[p][x][y][z] = min(f[p][x][y][z], dfs(i,a,b,c));
		}
	}
    if (x) f[p][0][y][z] = min(f[p][0][y][z], f[p][x][y][z]+1);
    if (y) f[p][x][0][z] = min(f[p][x][0][z], f[p][x][y][z]+1);
    if (z) f[p][x][y][0] = min(f[p][x][y][0], f[p][x][y][z]+1);
	return f[p][x][y][z];
}

int main()
{
	 freopen("worker.in", "r", stdin);
	 freopen("worker.out", "w", stdout);
	memset(f, 0x3f, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ch;
        for (int j = 1; j <= 3; j++) cnt[i][j] = cnt[i-1][j];
        a[i] = ch-'A'+1, cnt[i][a[i]]++;
    }
    if (n <= 10)
    {
    	cout << fc(cnt[n][1],cnt[n][2],cnt[n][3]);
    	return 0;
	}
    f[10][cnt[10][1]][cnt[10][2]][cnt[10][3]] = 0;
    if (cnt[10][1]!=0) f[10][0][cnt[10][2]][cnt[10][3]] = 1;
    if (cnt[10][2]!=0) f[10][cnt[10][1]][0][cnt[10][3]] = 1;
    if (cnt[10][3]!=0) f[10][cnt[10][1]][cnt[10][2]][0] = 1;
//    cout << cnt[10][1] << cnt[10][2] << cnt[10][3] << '\n';
    int ans = 2e9;
    for (int i = 11; i <= n; i++)
    for (int x = 0; x <= 10; x++)
    for (int y = 0; y <= 10; y++)
    for (int z = 0; z <= 10; z++)
    {
    	dfs(i, x, y, z);
    	if (i == n) ans = min(ans, dfs(n,x,y,z)+fc(x,y,z));
//		printf("(%d,%d,%d,%d)=%d\n",n,x,y,z,dfs(n,x,y,z));
	}
    cout << ans;
	return 0;
}
/*
18
A B C B C B C A B C C C C B C A C A
*/
