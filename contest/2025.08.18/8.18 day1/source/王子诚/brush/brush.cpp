#include <bits/stdc++.h>
using namespace std;

int a[10005];
int dp[10005][105];

int main(){
    freopen("brush.in", "r", stdin);
    freopen("brush.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if(m>n){
    	cout << 0;
	}
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    memset(dp, 0x7f, sizeof(dp));
    int ans = INT_MAX;
    for (int i = 0; i <= m; i++){
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n;i++){
        int minans = INT_MAX;
        for (int j = 1; j < m;j++){
            if(i-j<0){
                dp[i][j] = min(minans, dp[i][j - 1]) + a[i];
                continue;
            }
            minans = min(minans, dp[i - j][m - j]);
            dp[i][j] = min(minans, dp[i][j - 1]) + a[i];
            if(i-j>n-m){
                ans = min(ans, dp[i][j]);
            }
        }
    }
    cout << ans;
}