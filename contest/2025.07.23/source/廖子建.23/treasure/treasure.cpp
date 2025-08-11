#include<bits/stdc++.h>
#define int long long
#define N 200
#define M 21
#define Mod 1000000007
using namespace std;
int n,a[N+5],k,f[N+5]={},ux,dp[2][(1ll<<M)+5]={},ans=0;
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
int bcnt(int x){
	int cnt=0;
	while(x)cnt+=x&1,x>>=1ll;
	return cnt;
}
int revise(int x){
	x>>=k;
	for(int i=1;i<=k;i++)x=x-(x>>(f[i]-1)<<(f[i]-1))+(x>>(f[i]-1)<<f[i]);
//	int y=x;
//	while(y)cout<<(y&1),y>>=1ll;
//	cout<<"\n";
	return x;
}
void dfs(int x,int y,int v,int d){
	if(d>k){
		dp[x&1][y]=(dp[x&1][y]+dp[(x-1)&1][v])%Mod;
		return;
	}
	dfs(x,y,v,d+1),dfs(x,y,v+(1ll<<(f[d]-1)),d+1);
	return;
}
main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		if(i<=k)f[i]=f[i-1]+(k-i+1);
		else f[i]=f[i-1];
		a[i]=read();
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=(1ll<<f[i])-1;j++){
			dp[i&1][j]=0;
			if(bcnt(j)!=a[i])continue;
			ux=revise(j),dfs(i,j,ux,1);
			if(i==n)ans=(ans+dp[i&1][j])%Mod;
		}
	}
	print(ans);
	return 0;
}
