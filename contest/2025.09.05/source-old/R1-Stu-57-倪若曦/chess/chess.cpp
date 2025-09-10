
#include<bits/stdc++.h>
#define F(s) \
	freopen(s".in","r",stdin);\
	freopen(s".out","w",stdout);
using namespace std;
const int mod=9999973;
int m,n,ans;
int l[105],l1,l2;
int dp[105][105][105][105][3];
int dfs(int x,int y,int l1,int l2,int hx){
	if(!x) return ((l1+l2)>0);
	if(~dp[x][y][l1][l2][hx]) return dp[x][y][l1][l2][hx];
	int cnt=0;
	for(int j=1;j<y;j++){
		if(hx>=2) break;
		if(l[j]<2){
			l[j]++;
			int ll1=l1,ll2=l2;
			if(l[j]==2) ll2=l2+1,ll1=l1-1;
			if(l[j]==1) ll1=l1+1;
			int d=dfs(x,j,ll1,ll2,hx+1);
			if(!d) cnt=(cnt+1)%mod;
			else cnt=(cnt+d)%mod;
			l[j]--;
		}
	}
	cnt=(cnt+dfs(x-1,m+1,l1,l2,0))%mod;
	dp[x][y][l1][l2][hx]=cnt;
	return cnt;
}
int main(){
	//F("1")
	F("chess")
	scanf("%d%d",&n,&m);
	memset(dp,-1,sizeof(dp));
	ans=dfs(n,m+1,0,0,0);
	cout<<ans+1<<'\n';		

	return 0;
}
