#include<bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define F(s) \
	freopen(s".in","r",stdin);\
	freopen(s".out","w",stdout);
using namespace std;
inline int rd(){
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-f;c=getchar();}
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
inline void wt(int x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) wt(x/10);
	putchar(x%10+48);
	return;
}
int w,b;
double ans;
double dp[1005][1005][2];
double dfs(int lw,int lb,int aorb){
	if(!lw) return 0;
	if(!lb) return aorb;
	if(dp[lw][lb][aorb]>=0) return dp[lw][lb][aorb];
	double cnt=0;
	if(aorb==1){
		cnt+=double(lw*1.0/(1.0*lw+1.0*lb));
		if(lb) cnt+=double(1.0*lb/(1.0*lw+1.0*lb))*dfs(lw,lb-1,0);
	}
	else{
		if(lb>=2) cnt+=double(1.0*lb/(1.0*lw+1.0*lb))*double(1.0*(lb-1)/(1.0*lw+1.0*lb-1.0))*dfs(lw,lb-2,1);
		if(lb) cnt+=double(1.0*lb/(1.0*lw+1.0*lb))*double(1.0*lw/(1.0*lw+1.0*lb-1.0))*dfs(lw-1,lb-1,1);
	}
	dp[lw][lb][aorb]=cnt;
	return cnt;
}
signed main(){
	F("mouse");
	w=rd(),b=rd();
	for(int i=0;i<=w;i++){
		for(int j=0;j<=b;j++){
			dp[i][j][0]=dp[i][j][1]=-1.0;
		} 
	}
	printf("%.9lf",dfs(w,b,1));
	return 0;
}

