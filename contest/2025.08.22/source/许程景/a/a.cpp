#include <cstdio>
int st[100000][2];
int n,m,ans,mod;
int max(int a,int b){
	if(a>b) return a;
	else return b;
}
void dfs(int depth){
	if(depth==n+1){
		ans=(ans+1)%mod;
	}else{
		for(int i=1;i<=st[depth-1][1];i++){
			for(int j=max(i,st[depth-1][0]);j<=m;j++){
				// if(i<=st[depth-1].second&&j>=st[depth-1].first){
					st[depth][0]=i,st[depth][1]=j;
					dfs(depth+1);
				// }
			}
		}
	}
}
int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mod);
	st[0][0]=1,st[0][1]=0x3fffffff;
	ans=0,dfs(1),printf("%d",ans);
}