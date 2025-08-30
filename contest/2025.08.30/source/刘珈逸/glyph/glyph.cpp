#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=3e2+5,M=2e5+5;
#define y1 qaq
struct Query{int x1,y1,x2,y2,id;};
int a[N][N];
int n,m;
int ans[M];
int dp[N][N][N];//走左上/走右下 
void solve(int l1,int r1,int l2,int r2,vector<Query>&q){
	if(!q.size())return;
	if(l1==r1){
		for(int i=l2;i<=r2;i++){
			dp[i][l1][i]=a[l1][i];
			for(int j=i+1;j<=r2;j++)
				dp[i][l1][j]=dp[i][l1][j-1]+a[l1][j];
		}
		for(auto it:q){
			ans[it.id]=dp[it.y1][l1][it.y2];
		}
		return;
	}
	if(l2==r2){
		for(int i=l1;i<=r1;i++){
			dp[i][i][l2]=a[i][l2];
			for(int j=i+1;j<=r1;j++)
				dp[i][j][l2]=dp[i][j-1][l2]+a[j][l2];
		}
		for(auto it:q){
			ans[it.id]=dp[it.x1][it.x2][l2];
		}
		return;
	}
	if(r1-l1>=r2-l2){
		int mid=l1+r1>>1;
		for(int i=l2;i<=r2;i++){
			dp[i][mid][i]=a[mid][i];
			for(int j=mid;j>=l1;j--)
				for(int k=i;k>=l2;k--)
					if(j!=mid&&k!=i)dp[i][j][k]=min(dp[i][j+1][k],dp[i][j][k+1])+a[j][k];
					else if(j!=mid)dp[i][j][k]=dp[i][j+1][k]+a[j][k];
					else if(k!=i)dp[i][j][k]=dp[i][j][k+1]+a[j][k];
			dp[i][mid+1][i]=a[mid+1][i];
			for(int j=mid+1;j<=r1;j++)
				for(int k=i;k<=r2;k++)
					if(j!=mid+1&&k!=i)dp[i][j][k]=min(dp[i][j-1][k],dp[i][j][k-1])+a[j][k];
					else if(j!=mid+1)dp[i][j][k]=dp[i][j-1][k]+a[j][k];
					else if(k!=i)dp[i][j][k]=dp[i][j][k-1]+a[j][k];
		}
		vector<Query>q1,q2;
		for(auto it:q){
			if(it.x2<=mid)q1.pb(it);
			else if(it.x1>mid)q2.pb(it);
			else for(int i=l2;i<=r2;i++)if(it.y1<=i&&i<=it.y2)ans[it.id]=min(ans[it.id],dp[i][it.x1][it.y1]+dp[i][it.x2][it.y2]);
		}
		solve(l1,mid,l2,r2,q1);
		solve(mid+1,r1,l2,r2,q2);
	}else{
		int mid=l2+r2>>1;
		for(int i=l1;i<=r1;i++){
			dp[i][i][mid]=a[i][mid];
			for(int j=i;j>=l1;j--)
				for(int k=mid;k>=l2;k--)
					if(j!=i&&k!=mid)dp[i][j][k]=min(dp[i][j+1][k],dp[i][j][k+1])+a[j][k];
					else if(j!=i)dp[i][j][k]=dp[i][j+1][k]+a[j][k];
					else if(k!=mid)dp[i][j][k]=dp[i][j][k+1]+a[j][k];
			dp[i][i][mid+1]=a[i][mid+1];
			for(int j=i;j<=r1;j++)
				for(int k=mid+1;k<=r2;k++)
					if(j!=i&&k!=mid+1)dp[i][j][k]=min(dp[i][j-1][k],dp[i][j][k-1])+a[j][k];
					else if(j!=i)dp[i][j][k]=dp[i][j-1][k]+a[j][k];
					else if(k!=mid+1)dp[i][j][k]=dp[i][j][k-1]+a[j][k];
		}
		vector<Query>q1,q2;
		for(auto it:q){
			if(it.y2<=mid)q1.pb(it);
			else if(it.y1>mid)q2.pb(it);
			else for(int i=l1;i<=r1;i++)if(it.x1<=i&&i<=it.x2)ans[it.id]=min(ans[it.id],dp[i][it.x1][it.y1]+dp[i][it.x2][it.y2]);
		}
		solve(l1,r1,l2,mid,q1);
		solve(l1,r1,mid+1,r2,q2);
	}
}
signed main(){
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	vector<Query>q;
	memset(ans,0x3f,sizeof(ans));
	for(int i=1;i<=m;i++){
		int x1,y1,x2,y2;
		scanf("%lld%lld%lld%lld",&x1,&x2,&y1,&y2);
		q.pb({x1,y1,x2,y2,i});
	}
	solve(1,n,1,n,q);
	for(int i=1;i<=m;i++)printf("%lld\n",ans[i]);
	return 0;
}
/*
平面图分治 
*/
