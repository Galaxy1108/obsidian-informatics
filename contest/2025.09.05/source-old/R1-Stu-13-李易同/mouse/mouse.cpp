#include <iostream>
using namespace std;
int w,b;
bool vis[1010][1010][2];
double dp[1010][1010][2];
double dfs(int wh,int bl,int who)
{
	if(vis[wh][bl][who]) return dp[wh][bl][who];
	vis[wh][bl][who]=1;
	if(wh==0) return dp[wh][bl][who]=0,0;
	if(who==0)
	{
		if(bl==0) return dp[wh][bl][who]=1,1;
		dp[wh][bl][who]=1.0*wh/(wh+bl);
		if(bl) dp[wh][bl][who]+=1.0*bl/(wh+bl)*dfs(wh,bl-1,1);
		return dp[wh][bl][who];
	}
	if(bl==0) return dp[wh][bl][who]=0,0;
	double t2=(bl>=2?1.0*(bl-1)/(wh+bl-1)*dfs(wh,bl-2,0):0);
	dp[wh][bl][who]=1.0*bl/(wh+bl)*(1.0*wh/(wh+bl-1)*dfs(wh-1,bl-1,0)+t2);
	return dp[wh][bl][who];
}
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	cin>>w>>b;
	printf("%.9lf",dfs(w,b,0));
	return 0;
}
