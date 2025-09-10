#include<bits/stdc++.h>
#define ll unsigned long long
#define F(i,a,b) for(int i(a);i<=b;++i)
#define R(i,a,b) for(int i(a);i>=b;--i)
#define _ 0
using namespace std;
int w,b;
long double dp[1001][1001];
int main(){
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	scanf("%d%d",&w,&b);
	F(i,1,w) dp[i][0]=1;
	F(i,1,w) F(j,1,b){
		dp[i][j]=1.0*i/(i+j);
		long double help=1.0*j/(i+j)*(j-1)/(i+j-1);
		if(j>1) dp[i][j]+=help*i/(i+j-2)*dp[i-1][j-2];
		if(j>2) dp[i][j]+=help*(j-2)/(i+j-2)*dp[i][j-3];
	}
	printf("%.9Lf",dp[w][b]);
	return ~~(0^_^0);
}
