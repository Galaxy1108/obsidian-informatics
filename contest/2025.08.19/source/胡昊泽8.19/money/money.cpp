#include<iostream>
#define File(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)
using namespace std ;
double dp[2005][2] = {} ;
int cos = 0 , n = 0 ;
int w[2005] = {} ;
long long sum[2005] = {} ;
double c[2005] = {} , d[2005] = {} ;
int main()
{
	File("money") ;
	scanf("%d%d" , &n , &cos) ;
	for(int i = 1 ; i <= n ; ++i)
		scanf("%d%lf%lf" , &w[i] , &c[i] , &d[i]) , sum[i] = sum[i - 1] + w[i] ;
	for(int i = 1 ; i <= n ; ++i)
	{
		dp[i][0] = dp[i - 1][0] + w[i] ;
		dp[i][1] = dp[i - 1][1] + w[i] * c[i] ;
		for(int j = 1 ; j < i ; ++j)
		{
			dp[i][0] = max(dp[i][0] , dp[j][1] * d[i] - cos + sum[i] - sum[j]) ;
			dp[i][1] = max(dp[i][1] , (dp[j][0] + sum[i] - sum[j]) * c[i]) ;
//			这里就很奇怪，没有下面那一行大样例就能过，但是很明显没有的话状态就转移不全，正确性就不对，也许样例有误？ 
			dp[i][1] = max(dp[i][1] , dp[j][1] + (sum[i] - sum[j]) * c[i]) ;
		}
	}
	printf("%.4lf\n" , dp[n][0]) ;
	return 0 ;
}
