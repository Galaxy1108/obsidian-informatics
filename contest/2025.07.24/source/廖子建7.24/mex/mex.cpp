#include<bits/stdc++.h>
#define int long long
#define N 5000
#define M 20
#define Mod 998244353
using namespace std;
int n,m,dp[M+5][(1<<M)+5]={},a[N+5]={},ans=0,c=0,f,dp2[N+5][N+5]={};
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
	while(x)cnt+=(x&1),x>>=1;
	return cnt;
}
int fpow(int x,int y){
	if(!y)return 1;
	if(y&1)return fpow(x*x%Mod,y>>1)*x%Mod;
	return fpow(x*x%Mod,y>>1);
}
main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),c+=a[i];
	if(n<m){
		print(fpow(m,n-c));
		return 0;
	}
	dp2[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,m+1);j++){
			if(a[i]){
				if(j>0)dp2[i][j]=dp2[i-1][j-1];
				continue;
			}
			dp2[i][j]=dp2[i-1][j]*j%Mod;
			if(j>0)dp2[i][j]=(dp2[i][j]+dp2[i-1][j-1]*(m+1-j)%Mod)%Mod;
		}
	}
	for(int i=0;i<=m+1;i++)ans=(ans+dp2[n][i])%Mod;
	print(ans);
	return 0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=(1<<min(n,m+1))-1;j++){
			if(!a[i])dp[i][j]=dp[i-1][j]*((bcnt(j)+(m>=n?m-n+1:0))%Mod)%Mod,f=0;
			else f=1;
//			cout<<i<<" ";
//			for(int k=0;k<min(n,m+1);k++)cout<<((j>>k)&1);
//			cout<<" "<<dp[i][j]<<"\n";
			for(int k=0;k<min(n,m+1);k++){
				if((j>>k)&1^1){
					if(a[i])break;
					else{
						f=1;
						continue;
					}
				}
				if(f)dp[i][j]=(dp[i][j]+dp[i-1][j^(1<<k)])%Mod;
			}
//			cout<<i<<" ";
//			for(int k=0;k<min(n,m+1);k++)cout<<((j>>k)&1);
//			cout<<" "<<dp[i][j]<<"\n";
			if(i==n)ans=(ans+dp[i][j])%Mod;
		}
	}
	print(ans);
	return 0;
}
