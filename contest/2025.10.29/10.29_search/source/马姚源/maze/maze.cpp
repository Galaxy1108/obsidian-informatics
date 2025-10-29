#include <bits/stdc++.h>
using namespace std;
const int N = 50;
int g[N][N];
struct Node{
	int x, y, step;
};
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool book[N][N];
int main(){
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n, m, sx, sy;
	cin >> n >> m >> sx >> sy;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)cin >> g[i][j];
	queue<Node> q;
	q.push({1, 1, 0});
	int maxn = -1, ans = 0;
	while(q.size()){
		Node now = q.front();
		q.pop();
		if(now.x == sx && now.y == sy){
			int res = now.step;
			if(res > maxn){
				ans = 1;
				maxn = res;
				continue;
			}
			if(res == maxn){
				ans++;
			}
			continue;
		}
		for(int i = 0; i < 4; i++){
			int nx = now.x + dx[i], ny = now.y + dy[i];
			if(book[nx][ny] || nx < 1 || ny < 1 || nx > n || ny > m || g[nx][ny])continue;
			if(nx != sx && ny != sy)book[nx][ny] = 1;
			q.push({nx, ny, now.step + 1});
		}
	}
	cout << ans << endl;
	return 0;
}
