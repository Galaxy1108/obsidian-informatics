#include<bits/stdc++.h>
#define int long long
#define N 8000
#define M 25000
#define K 20
using namespace std;
int n,val[25]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2},a[M+5][K+5],uu,uv,uw,ans=INT_MIN;
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
void dfs(int x,int y,int sum,bool f){
//	cout<<x<<" "<<y<<" "<<sum<<" "<<f<<"\n";
	if(y<1||y>K)return;
	if(x>5){
		ans=max(ans,sum);
		return;
	}
	if(f==0){
		if(flag[x]&&!b[x][y])return;
		dfs(x+1,y+2,sum+val[a[x][y]],1);
		dfs(x+1,y+1,sum+val[a[x][y]],1);
		dfs(x+1,y,sum+val[a[x][y]],1);
		dfs(x+1,y-1,sum+val[a[x][y]],1);
		dfs(x+1,y-2,sum+val[a[x][y]],1);
		if(flag[x])return;
		dfs(x+1,y+2,sum,0);
		dfs(x+1,y+1,sum,0);
		dfs(x+1,y,sum,0);
		dfs(x+1,y-1,sum,0);
		dfs(x+1,y-2,sum,0);
		return;
	}
	else if(!flag[x])dfs(x+1,y,sum,0);
	return;
}
main(){
	freopen("data.in","r",stdin);
	freopen("sniper.ans","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		uu=read(),uv=read(),uw=read();
//		cout<<uu<<" "<<uv<<" "<<uw<<"\n";
		a[uw][uv]=uu;
		if(uu==15)flag[uw]=1,b[uw][uv]=1;
	}
	for(int i=1;i<=K;i++)dfs(0,i,0,0);
	print(ans);
	return 0;
}
