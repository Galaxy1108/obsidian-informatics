#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
int p[N], q[N];
int k[N];
int t[N];int ti,book[N];
void dfs(int cnt){
	if(cnt == n){
		int res[100] = {0}, t1[100] = {0};
		for(int i = 1; i <= n; i++){
			res[i] = p[t[i]];
		}
		for(int i = 1; i <= n; i++){
			t1[t[i]] = i; 
		}
		for(int i = 1; i <= n; i++){
			if(t1[res[i]] != q[i])return;
		}
		cout << "YES\n";
		for(int i = 1; i <= n; i++)cout << t[i] << " ";
		exit(0);
		return;
	}
	for(int i = 1; i <= n; i++){
		if(!book[i]){
			book[i] = 1;
			t[++ti] = i;
			dfs(cnt + 1);
			book[i] = 0;
			ti--;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		k[i] = i;
	}
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> q[i];
	}
	if(n <= 10){
		dfs(0);
		cout << "NO";	
	}
	else{
		for(int i = 1; i <= n; i++){
			if(p[i] != q[i]){
				cout << "NO";
				return 0;
			}
		}
		cout << "YES\n";
		for(int i = 1;i <= n ; i ++){
			cout << k[i] << " ";
		}
	}
	return 0;
} 
  
