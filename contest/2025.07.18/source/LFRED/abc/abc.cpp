#include<bits/stdc++.h>
using namespace std;
int n;
string ss;
int a[210];
int b[210];
int sum[4];
int ans = 0;
bool vis[210];
void dfs(int step){
	if(sum[1]>n||sum[2]>n||sum[3]>n) return;
	if(step == 3 * n + 1){
		for(int i = 1;i <= n * 3;++i) vis[i] = 0;
		for(int i = 1;i <= 3 * n;++i){
			if(vis[i]) continue;
			int now = i;
			if(b[i] == 1){
				while((b[now] != 2 || vis[now]) && now <= 3 * n) now++;
				if(now == 3 * n + 1) return;
				vis[now] = 1;
				while((b[now] != 3 || vis[now]) && now <= 3 * n) now++;
				if(now == 3 * n + 1) return;
				vis[now] = 1;
			}
			if(b[i] == 2){
				while((b[now] != 3 || vis[now]) && now <= 3 * n) now++;
				if(now == 3 * n + 1) return;
				vis[now] = 1;
				while((b[now] != 1 || vis[now]) && now <= 3 * n) now++;
				if(now == 3 * n + 1) return;
				vis[now] = 1;
			}
			if(b[i] == 3){
				while((b[now] != 1 || vis[now]) && now <= 3 * n) now++;
				if(now == 3 * n + 1) return;
				vis[now] = 1;
				while((b[now] != 2 || vis[now]) && now <= 3 * n) now++;
				if(now == 3 * n + 1) return;
				vis[now] = 1;
			}
		}
//		for(int i = 1;i <= 3 * n;++i) cout << b[i] << " ";
//		cout << "\n";
		ans++;
		return;
	}
	if(a[step]){
		b[step] = a[step];
		sum[a[step]]++;
		dfs(step + 1);
		sum[a[step]]--;
		return;
	}
	b[step] = 1;
	sum[1]++;
	dfs(step + 1); 
	sum[1]--;
	b[step] = 2;
	sum[2]++;
	dfs(step + 1);
	sum[2]--;
	b[step] = 3;
	sum[3]++;
	dfs(step + 1);
	sum[3]--;
}
int main(){
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	cin >> n;
	cin >> ss;
//	for(int i = 1;i <= 3 * n;++i) a[i] = ss[i - 1];
	for(int i = 1;i <= 3 * n;++i){
		if(ss[i - 1] == 'A' || ss[i - 1] == 'B' || ss[i - 1] == 'C') a[i] = ss[i - 1] - 'A' + 1;
		else a[i] = 0; 
	}
//	for(int i = 1;i <= 3 * n;++i) cout << a[i] << " ";
//	cout << "\n";
	dfs(1);
	cout << ans;
	return 0;
} 
