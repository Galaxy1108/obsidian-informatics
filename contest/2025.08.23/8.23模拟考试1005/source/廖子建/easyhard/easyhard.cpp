#include<bits/stdc++.h>
#define int long long
#define N 3000
using namespace std;
int n,m,dp[2][N+5],p,ans=0;
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
int fpow(int x,int y){
    if(!y)return 1;
    if(y&1)return fpow(x*x%p,y>>1)*x%p;
    return fpow(x*x%p,y>>1);
}
main(){
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
    n=read(),m=read(),p=read();
    print(fpow(2,n+m));
    return 0;
    for(int i=0;i<=n;i++)dp[0][i]=1%p;
    // dp[0][2]=1;
    for(int i=1;i<=m;i++){
        for(int j=0;j<=n;j++){
            dp[i&1][j]=0;
            if(j<n)dp[i&1][j]=(dp[i&1][j]+dp[i&1^1][j+1])%p;
            if(j>0)dp[i&1][j]=(dp[i&1][j]+dp[i&1^1][j])%p;
            if(j<n)dp[i&1][j]=(dp[i&1][j]+dp[i&1^1][j])%p;
            if(j>0)dp[i&1][j]=(dp[i&1][j]+dp[i&1^1][j-1])%p;
            cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i&1][j]<<"\n";
        }
    }
    for(int i=0;i<=n;i++)ans=(ans+dp[m&1][i])%p;
    print(ans);
	return 0;
}
