#include<bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;
int n,m,a[N+5],b[N+5],dp[2][N+5];
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
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++)b[i]=read();
	for(int i=1;i<=m;i++)dp[0][i]=1ll*INT_MAX*N;
	for(int i=1;i<=n;i++){
		dp[i&1][0]=1ll*INT_MAX*N;
		if(i==1)dp[i&1][1]=0;
		for(int j=1+(i==1);j<=m;j++)dp[i&1][j]=min(dp[i&1^1][j]+b[j],dp[i&1][j-1]+a[i]);
	}
	print(dp[n&1][m]);
	return 0;
}
