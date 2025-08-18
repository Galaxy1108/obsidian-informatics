#include<bits/stdc++.h>
#define int long long
#define N 100
#define K min(n,i+10)
#define Inf (1ll*INT_MAX*10000)
#define Ins (1ll*INT_MIN*10000)
using namespace std;
int n,a[N+5],b[N+5],c[N+5],dp[N+5][N+5][N+5],ux,uy,uz;
char uc;
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
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		cin>>uc;
		a[i]=a[i-1]+(uc=='A');
		b[i]=b[i-1]+(uc=='B');
		c[i]=c[i-1]+(uc=='C');
	}
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++)for(int k=0;k<=n;k++)dp[i][j][k]=Inf;
	dp[0][0][0]=0;
	for(int i=0;i<=n;i++){
		for(ux=0;ux<=i;ux++){
			for(int uy=0;uy+ux<=i;uy++){
				uz=i-ux-uy;
				dp[a[K]][uy][uz]=min(dp[a[K]][uy][uz],dp[ux][uy][uz]+1);
				dp[ux][b[K]][uz]=min(dp[ux][b[K]][uz],dp[ux][uy][uz]+1);
				dp[ux][uy][c[K]]=min(dp[ux][uy][c[K]],dp[ux][uy][uz]+1);
			}
		}
	}
	print(dp[a[n]][b[n]][c[n]]);
	return 0;
}
