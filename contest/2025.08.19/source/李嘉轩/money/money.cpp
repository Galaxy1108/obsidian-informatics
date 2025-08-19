#include<bits/stdc++.h>
using namespace std;
int w[2001];
long double c[2001], d[2001], dp[2001];
int main(){
	//43413269619200.4688
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	int n, cost;
	long double sum1, sum2, maxn;
	cin >> n >> cost;
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> c[i] >> d[i];
		sum1 = sum2 = maxn = 0;
		dp[i] = dp[i - 1] + w[i];
		for(int j = i; j >= 1; j--){
			maxn = max(maxn, c[j]);
			if(c[j] * d[i] < 1)sum1 += w[j];
			else sum2 += w[j] * c[j];
			dp[i] = max(dp[i], sum1 + d[i] * (dp[j - 1] * maxn + sum2) - cost);
		}
	}
	printf("%.4lf", (double)(dp[n]));
	return 0;
}
