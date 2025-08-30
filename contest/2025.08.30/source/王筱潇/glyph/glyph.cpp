#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q,xo,xt,yo,yt,a[310][310],i,j;
ll dp[310][310];
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar(); 
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	n=read();q=read();
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	while(q--){
		xo=read();xt=read();yo=read();yt=read();
		dp[xo+1][yo+1]=1e14;
		for(i=yo;i<=yt;i++) dp[xo-1][i]=1e14;
		for(i=xo;i<=xt;i++) dp[i][yo-1]=1e14;
		dp[xo-1][yo]=0;
		for(i=xo;i<=xt;i++){
			for(j=yo;j<=yt;j++){
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+(ll)a[i][j];
			}
		}
		printf("%lld\n",dp[xt][yt]);
	}
	return 0;
} 
