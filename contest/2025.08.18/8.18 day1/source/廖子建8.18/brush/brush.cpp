#include<bits/stdc++.h>
//#define int long long
#define N 10000
#define M 100
#define Inf (1000000010)
#define Ins (-1000000010)
#define min(x,y) ((x)<(y)?(x):(y))
using namespace std;
int n,m,a[N+5],dp[2][M+5][M+5],ans=Inf,uu,uv;
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
main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	n=read(),m=read();
//	return 0;
	for(int i=1;i<=n;i++)a[i]=read()/*,maxn=max(maxn,a[i])*/;
//	cout<<maxn;
//	return 0;
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)dp[1][i][j]=Inf;
	dp[1][1][1]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)for(int k=1;k<=m;k++)dp[i&1^1][j][k]=Inf;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=j;k++){
				uu=i&1,uv=i&1^1;
				if(dp[uu][j][k]==Inf)continue;
				if(j<m)dp[uv][j+1][k+1]=min(dp[uv][j+1][k+1],dp[uu][j][k]);
				dp[uv][k+1][1]=min(dp[uv][k+1][1],dp[uu][j][k]+a[i]);
			}
		}
	}
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)ans=min(ans,dp[n&1^1][i][j]);
	print(ans);
//	cout<<"\n"<<clock()*1.0/CLOCKS_PER_SEC<<"\n";
	return 0;
}
