//±©Á¦ÅÜ²»¹ın=10
#include<bits/stdc++.h>
using namespace std;
int n, k, ans = 114514;
int check(string s, int &t, int sp[]){
	int cnt = 0, now = 0;
	bool f = true;
	for(int i = 0; i < (n << 1); i++){
		if(s[i] == 'B')cnt++;
		if(cnt > now){
			sp[++t] = i;
			now = i - cnt + 1;
			if(cnt > now)f = false;
		}
	}
	return t <= k && f;
}
void dfs(string s, int cnt){
	if(cnt >= ans)return;
	int t = 0, sp[101];
	if(check(s, t, sp)){
		ans = cnt;
		return;
	}
	for(int i = 1; i <= t; i++){
		for(int j = sp[i] + 1; j < s.size(); j++){
			if(s[j] == 'A'){
				swap(s[sp[i]], s[j]);
				dfs(s, cnt + j - sp[i]);
				swap(s[sp[i]], s[j]);
				break;
			}
		}
	}
} 
int main(){
	freopen("transfer.in", "r", stdin);
	freopen("transfer.out", "w", stdout);
	string s;
	cin >> n >> k >> s;
	dfs(s, 0);
	cout << ans;
	return 0;
}
