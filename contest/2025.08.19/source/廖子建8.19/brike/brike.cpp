#include<bits/stdc++.h>
#define int long long
#define N 50
#define M 500
using namespace std;
int n,m,dp[N+5][N+5][M+5],a[N+5][N+5],sum[N+5][N+5],ans=INT_MIN;
bool ver[N+5][N+5][M+5];
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
int dfs(int x,int y,int v){
	if(v<0||y>(n-x+1)||y<0)return INT_MIN;
	if(x==n){
		if(v!=0)return INT_MIN;
		return 0;
	}
	if(ver[x][y][v])return dp[x][y][v];
	ver[x][y][v]=1;
	dp[x][y][v]=INT_MIN;
	for(int i=max(y-1,0ll);i<=n-x;i++)dp[x][y][v]=max(dp[x][y][v],dfs(x+1,i,v-i)+sum[i][x+1]);
//	cout<<x<<" "<<y<<" "<<v<<" "<<dp[x][y][v]<<"\n";
	return dp[x][y][v];
}
main(){
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(n-i+1);j++){
			a[i][j]=read(),sum[i][j]=sum[i-1][j]+a[i][j];
//			cout<<sum[i][j]<<" ";
		}
//		cout<<"\n";
	}
	for(int i=1;i<=n;i++)ans=max(ans,dfs(1,i,m-i)+sum[i][1]);
	print(ans);
	return 0;
}
