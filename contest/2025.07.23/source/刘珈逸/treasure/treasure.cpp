#include<bits/stdc++.h>
using namespace std;
const int N=105,M=5040,T=128,mod=1e9+7;
int jie[]={1,1,2,6,24,120,720,5040};
int dp[M],tmp[M],cnt[M];//前6个斜线的状态 
int n,k,b[N];
int v[7];
void get(int x){
	for(int i=k;i>=2;i--)v[i-1]=x%i,x/=i;
}
int calc(){
	int ans=0;
	for(int i=2;i<=k;i++)ans=ans*i+v[i-1];
	return ans;
}
void chk(int&x,int y){x+=y;if(x>=mod)x-=mod;}
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",b+i);
	for(int i=0;i<jie[k];i++){
		get(i);
		for(int j=1;j<k;j++)cnt[i]+=v[j];
	}
	dp[0]=1;
	for(int i=1;i<=n;i++){
		memcpy(tmp,dp,sizeof(dp));
		memset(dp,0,sizeof(dp));
		for(int j=0;j<jie[k];j++)if(tmp[j])for(int l=0;l<(1<<k);l++)if(cnt[j]+__builtin_popcount(l)==b[i]){
			get(j);
			for(int w=k-1;w>=1;w--)v[w]=v[w-1];
			for(int w=1;w<k;w++)v[w]+=l>>w&1;
			chk(dp[calc()],tmp[j]);
		}
	}int ans=0;
	for(int i=0;i<jie[k];i++)chk(ans,dp[i]);
	printf("%d\n",ans);
	return 0;
}
/*
考虑状压 记录斜线上的数量即可 
5 3
2 1 2 3 2
*/
