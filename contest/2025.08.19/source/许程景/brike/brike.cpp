#include <cstdio>
#include <cstring>
#include <iostream>
#define N 50
int dp[(N<<1)+1][51][1226];
int all[60][60];
void mv(int b,int &a,int val){if(b!=0x80808080&&a<b+val) a=b+val;}
int main(){
	freopen("brike.in","r",stdin);
	freopen("brike.out", "w", stdout);
	int n,m;
	std::cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=0;j<=(n-i);j++) std::cin>>all[i][j],all[i][j]+=all[i-1][j+1];
	memset(dp, 0x80, sizeof(dp));
	dp[0][0][0]=all[0][0];
	int dots=(n*(n-1))>>1,ans=0x80808080;
	for(int i=0;i<(n<<1);i++){
		// 先处理虚拟节点的特殊情况
		for(int depth=i&1;depth<=(i>n?(2*n-i):i);depth+=2){
			int xaxis=i-((depth+i)>>1);
			for(int k=0;k<=m;k++){
				if(all[depth+1][xaxis]){
					// if(dp[i][depth][k]!=0x80808080) printf("< down:<k:%d (%d,%d)>:%d,%d >\n",depth+k+1,depth,xaxis,dp[i][depth][k],all[depth+1][xaxis]);
					mv(dp[i][depth][k],dp[i+1][depth+1][k+depth+1],all[depth+1][xaxis]);
					if(dp[i+1][depth+1][m]>ans) ans=dp[i+1][depth+1][m];
				}
				if(depth!=0){
					// if(dp[i][depth][k]!=0x80808080) printf("<   up:<k:%d (%d,%d)>:%d >\n",k,depth,xaxis,dp[i][depth][k]);
					mv(dp[i][depth][k],dp[i+1][depth-1][k],0);
				}
			}
		}
	}
	std::cout<<ans;
}