#include<bits/stdc++.h>
#define int long long
#define N 8000
#define M 25000
#define K 20
using namespace std;
int n,val[25]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2},dp[M+5][K+5][2]={},a[M+5][K+5],uu,uv,uw,ans=INT_MIN;
bool flag[M+5]={},b[M+5][N+5];
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
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		uu=read(),uv=read(),uw=read();
//		cout<<uu<<" "<<uv<<" "<<uw<<"\n";
		a[uw][uv]=uu;
		if(uu==15)flag[uw]=1,b[uw][uv]=1;
	}
	for(int i=1;i<=K;i++)dp[0][i][1]=val[a[0][i]];
	for(int i=1;i<=M;i++){
		for(int j=1;j<=K;j++){
			dp[i][j][1]=/*max(dp[i-1][j][1],dp[i-1][j][0])*/dp[i-1][j][0]+val[a[i][j]];
			if(j>1)dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][0]+val[a[i][j]]);
			if(j<K)dp[i][j][1]=max(dp[i][j][1],dp[i-1][j+1][0]+val[a[i][j]]);
			if(j>2)dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-2][0]+val[a[i][j]]);
			if(j<K-1)dp[i][j][1]=max(dp[i][j][1],dp[i-1][j+2][0]+val[a[i][j]]);
			dp[i][j][0]=max(dp[i-1][j][1],dp[i-1][j][0]);
			if(j>1)dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-1][0]);
			if(j<K)dp[i][j][0]=max(dp[i][j][0],dp[i-1][j+1][0]);
			if(j>2)dp[i][j][0]=max(dp[i][j][0],dp[i-1][j-2][0]);
			if(j<K-1)dp[i][j][0]=max(dp[i][j][0],dp[i-1][j+2][0]);
			if(flag[i]&&!b[i][j])dp[i][j][0]=dp[i][j][1]=INT_MIN;
			else if(flag[i])dp[i][j][0]=INT_MIN;
//			cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<"\n";
		}
	}
	for(int i=1;i<=K;i++)ans=max(ans,max(dp[M][i][0],dp[M][i][1]));
	print(ans);
	return 0;
}
