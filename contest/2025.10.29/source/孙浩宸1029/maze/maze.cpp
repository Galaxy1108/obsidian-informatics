#include<bits/stdc++.h>
using namespace std;
bool mg[15][15];
int dis[15][15];
int vis[15][15];
struct st{
	int x,y;
};
int cnt=0;
int n,m,x,y;
void bfs(){
	deque <st> de;
	de.push_back({1,1});
	dis[1][1] = 0;
	vis[1][1] = 1;
	while(!de.empty()){
		auto cl = de.front();
//		cout << cl.x <<" "<< cl.y << endl;
		if(cl.x == x && cl.y == y){
			break;
		}
/*		if(cl.x == x && cl.y == y){
			while(dis[de.front().x][de.front().y] == dis[cl.x][cl.y]){
				de.pop_front();
				cnt ++;
			}
			break;
		}*/
		de.pop_front();
		if(cl.x + 1 <= n && mg[cl.x + 1][cl.y] == 0 && vis[cl.x + 1][cl.y] == 0){
			de.push_back({cl.x + 1,cl.y});
			vis[cl.x + 1][cl.y] = 1;
			dis[cl.x + 1][cl.y] = dis[cl.x][cl.y] + 1;
		}
		if(cl.x - 1 >= 1 && mg[cl.x - 1][cl.y] == 0 && vis[cl.x - 1][cl.y] == 0){
			de.push_back({cl.x - 1,cl.y});
			vis[cl.x - 1][cl.y] = 1;
			dis[cl.x - 1][cl.y] = dis[cl.x][cl.y] + 1;
		}
		if(cl.y + 1 <= m && mg[cl.x][cl.y + 1] == 0 && vis[cl.x][cl.y + 1] == 0){
			de.push_back({cl.x,cl.y + 1});
			vis[cl.x][cl.y + 1] = 1;
			dis[cl.x][cl.y + 1] = dis[cl.x][cl.y] + 1;
		}
		if(cl.y - 1 >= 1 && mg[cl.x][cl.y - 1] == 0 && vis[cl.x][cl.y - 1] == 0){
			de.push_back({cl.x,cl.y - 1});
			vis[cl.x][cl.y - 1] = 1;
			dis[cl.x][cl.y - 1] = dis[cl.x][cl.y] + 1;
		}
	}
	return ;
}
void dfs(int dep,st pos){
	if(pos.x == x && pos.x == y && dep == dis[x][y]){
		cnt ++;
	}
	if(dep > dis[x][y]){
		return ;
	}
	if(pos.x + 1 <= n && mg[pos.x + 1][pos.y] == 0 && vis[pos.x + 1][pos.y] == 0){
		vis[pos.x + 1][pos.y] = 1;
		dfs(dep + 1,{pos.x + 1,pos.y});
		vis[pos.x + 1][pos.y] = 0;
	}
	if(pos.x - 1 >= 1 && mg[pos.x - 1][pos.y] == 0 && vis[pos.x - 1][pos.y] == 0){
		vis[pos.x - 1][pos.y] = 1;
		dfs(dep + 1,{pos.x - 1,pos.y});
		vis[pos.x - 1][pos.y] = 0;
	}
	if(pos.y + 1 <= m && mg[pos.x][pos.y + 1] == 0 && vis[pos.x][pos.y + 1] == 0){
		vis[pos.x][pos.y + 1] = 1;
		dfs(dep + 1,{pos.x,pos.y + 1});
		vis[pos.x][pos.y + 1] = 0;
	}
	if(pos.y - 1 >= 1 && mg[pos.x][pos.y - 1] == 0 && vis[pos.x][pos.y - 1] == 0){
		vis[pos.x][pos.y - 1] = 1;
		dfs(dep + 1,{pos.x,pos.y - 1});
		vis[pos.x][pos.y - 1] = 0;
	}
	return;
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
//	ios::sync_with_stdio(NULL);
//	cin.tie(0),cout.tie(0);
	cin >> n >> m >> x >> y;
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= m;j++){
			cin >> mg[i][j];
		}
	}
	bfs();
	memset(vis,0,sizeof(vis));
	dfs(0,{1,1});
	cout << cnt;
	return 0;
}
