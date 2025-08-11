//很好的黑题,题面与数据相互呼应,性质交融,子任务灵动,即使是我,也感到只会做k=2
//评价:披着矩阵皮的图论
#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> >ans;
int k;
bool g[2001][2001];
void newEdge(int u, int v){
	if(g[u][v])return;
	ans.push_back({u, v});
	g[u][v] = true;
}
void query(int l, int r){
	if(r - l <= 1)return;
	int mid = (l + r) >> 1;
	for(int i = mid - 2; i >= l; i -= (k + 1) / 2){
		newEdge(i, mid);
		if(k > 2 && i != mid - 2)newEdge(i, i + (k + 1) / 2);
	}
	for(int i = mid + 2; i <= r; i += k / 2){
		newEdge(mid, i);
		if(k > 3 && i != mid + 2)newEdge(i - k / 2, i);
	}
	query(l, mid - 1);
	query(mid + 1, r);
}
int main(){
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	int n;
	cin >> n >> k;
	query(0, n);
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)cout << ans[i].first << " " << ans[i].second << "\n";
	return 0;
}
