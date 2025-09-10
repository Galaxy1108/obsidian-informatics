#include <bits/stdc++.h>
using namespace std;
double w, b;
int sum = 0;
double ans = 0;
void dfs(double white, double black, int cnt, double now){
	if(white <= 0)return;
	cnt = cnt % 2;
//	cout << white << " " << black << " " << now << " " << ans << endl;
	if(cnt % 2 == 0){
		ans += (white) / (white + max(black, 1.0)) * 1.0 * now;
//		printf("%.9f\n", now * (black) / (white + black) * 1.0);
		if(black > 0)dfs(white, black - 1, cnt + 1, now * (black) / (white + black) * 1.0);
	}
	else{
		if(black > 0 && white > 0)dfs(white - 1, black - 1, cnt + 1, now * (black) / (white + black + ) * 1.0);
		if(black > 1)dfs(white, black - 2, cnt + 1,  now * (black) / (white + black) * 1.0);
	}
}
int main(){
	freopen("mouse.in", "r", stdin);
	freopen("mouse.out", "w", stdout);
	cin >> w >> b;
	dfs(w * 1.0, b * 1.0, 0, 1.0);
//	dp[1][0] = 1.0;
//	for(int i = 1; i <= w; i++){
//		for(int j = 1; j <= b; j++){
//			dp[i][j] = dp[i][j - 1] * 1.0 * (i) / (i + j);
//		}
//	}
//	cout << dp[int(w)][int(b)] << endl;
//	cout << ans << " " << sum << endl;
	printf("%.9f", ans);
	return 0;
}
