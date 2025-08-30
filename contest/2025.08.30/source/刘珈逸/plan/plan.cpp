#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=5e2+5,M=1e6+5;
typedef pair<int,int>pii; 
int n,k;
vector<int>G[N];
unordered_map<int,int>dp[N][N],tmp[N];
int a[N],siz[N];
void chk(int&x,int y){
	if(x<y)x=y;
}
void dfs(int x,int f){
	for(int i:G[x])if(i^f)dfs(i,x);
	siz[x]=1;
	for(int i=1;i*i<=a[x];i++)if(a[x]%i==0){
		dp[x][0][i]=0;
		dp[x][0][a[x]/i]=0;
	}
	for(int v:G[x])if(v^f){
		for(int i=0;i<siz[x];i++)tmp[i]=dp[x][i],dp[x][i].clear();
		for(int i=0;i<siz[x];i++)for(int j=0;j<siz[v];j++){
			int res=0;
			for(auto it:dp[v][j])res=max(res,it.fi+it.se);
			for(auto k:tmp[i]){
				chk(dp[x][i+j+1][k.fi],tmp[i][k.fi]+res);
				if(dp[v][j].count(k.fi))chk(dp[x][i+j][k.fi],tmp[i][k.fi]+dp[v][j][k.fi]);
			}
		}siz[x]+=siz[v];
	}
}
int main(){
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	dfs(1,0);
	int ans=0;
	for(auto it:dp[1][k])ans=max(ans,it.fi+it.se);//,puts("QAQ");
	printf("%d\n",ans);
	return 0;
}
/*
设dp[x][v]表示x子树内根结点的连通块的gcd=v,权值最大值
复杂度O(n^2 sqrt(V)) 
4 1
1 2
2 3
3 4
10 10
*/
