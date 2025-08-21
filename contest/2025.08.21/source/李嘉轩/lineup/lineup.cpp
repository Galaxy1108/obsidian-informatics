#include<bits/stdc++.h>
using namespace std;
int n, h[9], w[9], s1 = 0x7f7f7f7f, s2;
void dfs(int sm, int ss){
	if(sm > s1 || (sm == s1 && ss >= s2))return;
	for(int i = 1; i < n; i++)for(int j = i + 1; j <= n; j++)if(h[i] > h[j])goto skip;
	s1 = sm;
	s2 = ss;
	return;
	skip:;
	for(int i = 1; i < n; i++){
		for(int j = i + 1; j <= (n > 8 ? i + 1 : n); j++){
			if(h[i] <= h[j])continue;
			swap(h[i], h[j]);
			w[i] += j - i;
			w[j] += j - i;
			dfs(max({sm, w[i], w[j]}), ss + j - i);
			swap(h[i], h[j]);
			w[i] -= j - i;
			w[j] -= j - i;
		}
	}
}
int main(){
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> h[i];
	dfs(0, 0);
	cout << (s2 << 1);
	return 0;
}
