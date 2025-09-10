#include <bits/stdc++.h> 
using namespace std; 
const int maxn = 1010;  
int n, m; 
double dp[maxn][maxn]; 
void init() {
	cin >> n >> m; 
	for(int i = 0; i <= m; ++i) {
		dp[0][i] = 0.00;
	}
	for(int i = 0; i <= n; ++i) {
		dp[i][0] = 1.00; 
	}
	dp[0][0] = 0.00;
	return ; 
}
void work() {
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			dp[i][j] += (double) i / (i + j); 
			if(j >= 2) {
				dp[i][j] += (double) j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dp[i - 1][j - 2]; 
			}
			if(j >= 3) {
				dp[i][j] += (double) j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dp[i][j - 3]; 
			}
		}
	}
	return ;
}
int main() {
	freopen("mouse.in" , "r", stdin ); 
	freopen("mouse.out", "w", stdout); 
	init(); 
	work(); 
	printf("%.9lf\n",dp[n][m]); 
	return 0; 
}
