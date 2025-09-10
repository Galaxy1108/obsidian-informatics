#include<bits/stdc++.h>
#define ld long double
using namespace std;
int a,b;
ld dp[1001][1001];
ld dfs(int x,int y){
	if(x==0)return 0.0;
	if(y==0)return 1.0;
	if(dp[x][y]>0)return dp[x][y];
	ld ans=(ld)x/(x+y);
	if(y==2)ans+=(ld)y/(x+y)*(y-1)/(x+y-1)*dfs(x-1,y-2);
	else if(y>=3){
		ans+=(ld)y/(x+y)*(y-1)/(x+y-1)*((ld)x/(x+y-2)*dfs(x-1,y-2)+(ld)(y-2)/(x+y-2)*dfs(x,y-3));
	}
//	cout<<x<<" "<<y<<" "<<ans<<endl;
	return dp[x][y]=ans;
}
int main(){
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	cin>>a>>b;
	printf("%.9Lf\n",dfs(a,b));
	return 0;
}
