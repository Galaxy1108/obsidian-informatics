//к╣╨ц╣двово╨з╨здь(
#include<bits/stdc++.h>
using namespace std;
char mp[5001][5001];
bool ban[11][513];
int m, f[11];
void dfs(int dep, int id, int x, int y){
	mp[x][y] = 'o';
	if(dep >= m)return;
	if(!ban[dep + 1][id << 1]){
		for(int i = 1; i < f[dep]; i++)mp[x + i][y - i] = '/';
		dfs(dep + 1, id << 1, x + f[dep], y - f[dep]);
	}
	if(!ban[dep + 1][id << 1 | 1]){
		for(int i = 1; i < f[dep]; i++)mp[x + i][y + i] = '\\';
		dfs(dep + 1, id << 1 | 1, x + f[dep], y + f[dep]);
	}
}
int main(){
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	int n, x, y, sum = 3;
	cin >> m >> n;
	if(m > 2)sum = 6;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		ban[x][y - 1] = true;
	}
	f[m - 1] = 2;
	f[m - 2] = 3;
	for(int i = m - 3; i >= 1; i--){
		f[i] = (f[i + 1] << 1);
		sum += f[i];
	}
	if(!ban[1][0])dfs(1, 0, 1, 3 << (m - 2));
	for(int i = 1; i <= sum; i++){
		for(int j = 1; j <= (3 << (m - 1)) - 1; j++){
			if(mp[i][j])putchar(mp[i][j]);
			else putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
