#include<bits/stdc++.h>
using namespace std;
const int N=75,mod=1e9+7;
int n;
int prime[N],tot;
bool isp[N];
int cnt[N];
int p2[100005];
int dp[1<<19],f[1<<19];
void chk(int&x,int y){x+=y;if(x>=mod)x-=mod;}
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	p2[0]=1;
	for(int i=1;i<=100000;i++)p2[i]=p2[i-1]*2%mod;
	for(int i=2;i<=70;i++){
		if(!isp[i])prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<=70;j++){
			isp[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	scanf("%d",&n);
	while(n--){
		int x;scanf("%d",&x);cnt[x]++;
	}dp[0]=1;
	for(int i=1;i<=70;i++)if(cnt[i]){
		int S=0,x=i;
		for(int j=1;j<=tot;j++){
			int c=0;
			while(x%prime[j]==0)c++,x/=prime[j];
			if(c&1)S|=1<<(j-1);
		}
		memcpy(f,dp,sizeof(f));
		for(int j=0;j<(1<<19);j++)dp[j]=1ll*dp[j]*p2[cnt[i]-1]%mod;
		for(int j=0;j<(1<<19);j++)chk(dp[j],1ll*f[j^S]*p2[cnt[i]-1]%mod);
	}printf("%d\n",(dp[0]+mod-1)%mod);
	return 0;
} 
