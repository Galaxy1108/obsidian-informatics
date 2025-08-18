#include<bits/stdc++.h>
#define int long long
#define N 2000
#define Inf (1ll*INT_MAX*10000)
#define Ins (1ll*INT_MIN*10000)
using namespace std;
int dp[N+5][4],n,a[N+5],b[N+5],ans=Ins;
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
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read(),a[i]+=b[i]/*,cout<<a[i]<<" "<<b[i]<<"\n"*/;
	for(int i=0;i<=n;i++)dp[i][1]=dp[i][2]=dp[i][3]=Ins;
	for(int i=1;i<=n;i++){
		dp[i][1]=max(a[i],dp[i-1][1]+a[i]);
		dp[i][2]=max(dp[i-1][1]+b[i],dp[i-1][2]+b[i]);
		dp[i][3]=max(dp[i-1][2]+a[i],dp[i-1][3]+a[i]);
		ans=max(ans,dp[i][3]);
//		cout<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<"\n";
	}
	print(ans);
	return 0;
}
