//一大坨完全找不到性质的东西
//还有这个暴力怎么这么长
//一个很神奇的事情,这个复杂度O(n^6n)的check只用0.02秒跑过了第2个大样例
#include<bits/stdc++.h>
using namespace std;
bool check(int n, string s){
	if(s == "#")return true;
	for(int i = 2; i < n; i++){
		if(s[1] <= 'B' && s[i] != s[1] + 1)continue;
		if(s[1] == 'C' && s[i] != 'A')continue;
		for(int j = i + 1; j <= n; j++){
			if(s[i] <= 'B' && s[j] != s[i] + 1)continue;
			if(s[i] == 'C' && s[j] != 'A')continue;
			if(check(n - 3, "#" + s.substr(2, i - 2) + s.substr(i + 1, j - i - 1) + s.substr(j + 1, n - j)))return true;
		}
	}
	return false;
}
int n, ans = 0;
string s;
void dfs(int x, int a, int b, int c){
	if(a > n || b > n || c > n)return;
	if(x > n * 3){
		ans += check(n * 3, s);
		return;
	}
	if(s[x] != '?'){
		if(s[x] == 'A')dfs(x + 1, a + 1, b, c);
		else if(s[x] == 'B')dfs(x + 1, a, b + 1, c);
		else dfs(x + 1, a, b, c + 1);
		return;
	}
	s[x] = 'A';
	dfs(x + 1, a + 1, b, c);
	s[x] = 'B';
	dfs(x + 1, a, b + 1, c);
	s[x] = 'C';
	dfs(x + 1, a, b, c + 1);
	s[x] = '?';
}
int main(){
	freopen("abc.in", "r", stdin);
	freopen("abc.out", "w", stdout);
	cin >> n >> s;
	s = "#" + s;
	dfs(1, 0, 0, 0);
	cout << ans;
	return 0;
}
