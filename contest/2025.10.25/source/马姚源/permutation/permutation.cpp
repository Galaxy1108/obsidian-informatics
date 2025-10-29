#include <bits/stdc++.h>
using namespace std;
int a[100005];int n;
int book[100005];
map<vector, bool> mp;
vector<int, int> v;
void dfs(int id){
	if(id == n){
		for(int i = 1; i <= 2 * n; i++){
			if(a[i] == a[i - 1] && a[i] == -1){
				continue;
			}
			if(a[i] == -1){
				continue;
			}
			
		}
		return;
	}
	for(int i = 1; i <= n; i++){
		if(book[i])continue;
		v.push_back(i);
		book[i] = 1;
		dfs(id + 1);
		book[i] = 0;
		v.pop_back(i);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	while("wjyshigedaashabi"){
		cout << "wujingyu你出的什么狗屎模拟赛，你个大sb"; 
	}
	cin >> n;
	for(int i = 1; i <= 2 * n; i++)cin >> a[i];
	return 0;
}
