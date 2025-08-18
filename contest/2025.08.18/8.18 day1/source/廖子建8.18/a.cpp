#include<bits/stdc++.h>
#define int long long
#define N 12
#define M 531441
using namespace std;
int n,m,dp[N+5][M+5],edge[N+5][N+5],uu,uv,uw,u[N+5],a[M+5][N+5],ans=INT_MAX;
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
void adfs(int x,int y){
	if(x>n){
		for(int i=1;i<=n;i++){
			if(u[i]!=2)continue;
			for(int j=1;j<=n;j++){
				if(u[j]||edge[i][j]==INT_MAX)continue;
				if(!a[y][j])a[y][j]=edge[i][j];
				else a[y][j]=min(a[y][j],edge[i][j]);
			}
		}
		for(int i=1;i<=n;i++)dp[i][y]=INT_MAX;
		return;
	}
	u[x]=0,adfs(x+1,y*3);
	u[x]=1,adfs(x+1,y*3+1);
	u[x]=2,adfs(x+1,y*3+2);
	return;
}
void bdfs(int x,int y,int z){
	if(x>n){
		if(!z)return;
		dp[1][y]=0;
		return;
	}
	if(!z)bdfs(x+1,y*3+2,x);
	bdfs(x+1,y*3,z);
	return;
}
void cdfs(int c,int x,int y){
	if(x>n){
		int sum=0,uy=0;
		for(int i=1;i<=n;i++){
			if(u[i]==2)u[i]=1;
			else if(a[y][i])u[i]=2;
			sum+=a[y][i],uy=uy*3+u[i];
		}
		dp[c+1][uy]=min(dp[c+1][uy],dp[c][y]+c*sum);
		return;
	}
	u[x]=0,cdfs(c,x+1,y*3);
	u[x]=1,cdfs(c,x+1,y*3+1);
	u[x]=2,cdfs(c,x+1,y*3+2);
	return;
}
void ddfs(int c,int x,int y){
	if(x>n){
		ans=min(ans,dp[c][y]);
		return;
	}
	ddfs(c,x+1,y*3+1);
	ddfs(c,x+1,y*3+2);
	return;
}
main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)edge[i][j]=INT_MAX;
	for(int i=1;i<=n;i++)edge[i][i]=0;
	for(int i=1;i<=m;i++){
		uu=read(),uv=read(),uw=read();
		edge[uu][uv]=edge[uv][uu]=min(edge[uu][uv],uw);
	}
	adfs(1,0),bdfs(1,0,0);
	for(int i=1;i<n;i++)cdfs(i,1,0);
	for(int i=1;i<=n;i++)ddfs(i,1,0);
	print(ans);
	return 0;
}
