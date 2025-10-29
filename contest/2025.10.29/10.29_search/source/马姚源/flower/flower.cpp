#include <bits/stdc++.h>
using namespace std;
const int N = 65;
int a[N], vis[N], lst[N];
int n;
string s[50];
void dfs(int id){
	if(id > 2 * n){
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= 2 * n; i++){
			vis[a[i]] = 1; 
		}
		for(int i = 1; i <= n; i++){
			if(!vis[i])return;
		}
		for(int i = 1; i <= 2 * n; i++){
			cout << s[a[i]] << endl;
		}
		exit(0);
	}
//	cout << id << endl;
//	for(int i = 1; i <= id; i++)cout << a[i] << " ";
//	cout << endl;
	for(int i = n; i >= 1; i--){
		if(!lst[i]){
			a[id] = i;
			int t = lst[i];
			lst[i] = id;
			dfs(id + 1);
			a[id] = 0;
			lst[i] = t;
			
		}
		else{
			if(id - lst[i] - 1 >= i){
				a[id] = i;
				int t = lst[i];
				lst[i] = id;
				dfs(id + 1);
				a[id] = 0;
				lst[i] = t;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> s[i];
//	for(int i = 1; i <= n; i++){
		memset(a, 0, sizeof(a));
		memset(lst, 0, sizeof(lst));
		dfs(1);
//	} 
	return 0;
} 
