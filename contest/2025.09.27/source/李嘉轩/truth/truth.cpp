#include<bits/stdc++.h>
using namespace std;
int n, k, m, op, p, v, a[50001], cnt[50001][31];
void next_query(){
	cin >> op;
	if(op == 1)cin >> p >> v;
}
void solve1(){
	while(m--){
		next_query();
		if(op == 2)cout << "1\n";
	}
}
void solve2(){
	int cnt = 0;
	for(int i = 1; i <= n; i++)if(a[i] == 1)cnt++;
	while(m--){
		next_query();
		if(op == 1){
			if(a[p] == 1)cnt--;
			if(v == 1)cnt++;
		}else{
			if(cnt > 0 && cnt < n)cout << "2\n";
			else cout << "-1\n";
		}
	}
}
void solve(){
	int ans, l, r, mid;
	bool h;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k; j++)cnt[i][j] = cnt[i - 1][j];
		cnt[i][a[i]]++;
	}
	while(m--){
		next_query();
		if(op == 1){
			for(int i = p; i <= n; i++){
				cnt[i][a[p]]--;
				cnt[i][v]++;
			}
			a[p] = v;
		}else{
			ans = 0x7f7f7f7f;
			l = 1;
			r = n + 1;
			while(l < r){
				mid = (l + r) >> 1;
				h = true;
				for(int i = 1; i <= k; i++)if(cnt[mid][i] == 0)h = false;
				if(h)r = mid;
				else l = mid + 1;
			}
			for(int i = r, j = 0; i <= n; i++){
				while(j <= i && cnt[i][a[j + 1]] - cnt[j][a[j + 1]] > 1)j++;
				ans = min(ans, i - j);
			}
			if(ans == 0x7f7f7f7f)cout << "-1\n";
			else cout << ans << "\n";
		}
	}
}
int main(){
	freopen("truth.in", "r", stdin);
	freopen("truth.out", "w", stdout);
	cin >> n >> k >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	if(k == 1)solve1();
	else if(k == 2)solve2();
	else solve();
	return 0;
}
