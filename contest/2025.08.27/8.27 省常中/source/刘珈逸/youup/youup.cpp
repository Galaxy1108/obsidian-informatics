#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=998244353,M=20+5;
vector<int>G[N];
int dp[M][M][M];
int id,n,x;
int jie[N],inv[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*a*ans%mod;
		b>>=1;a=1ll*a*a%mod;
	}return ans;
}
int C(int n,int m){
	if(m>n)return 0;
	return 1ll*jie[n]*inv[n-m]%mod*inv[m]%mod;
}
int solve1(){
	for(int i=1;i<=n;i++)printf("%d ",i==1?n:0);
	return 0;
}
int ans[N],d[N];
bool fl[N];
int mxd[N];
bool flag;
void dfs(int x,int f){
	int mx=-0x3f3f3f3f,se=-0x3f3f3f3f;
	if(fl[x])mx=0;
	for(int i:G[x])if(i^f){
		dfs(i,x);
		if(mx<mxd[i]+1)se=mx,mx=mxd[i]+1;
		else if(se<mxd[i]+1)se=mxd[i]+1;
	}
	if(mx+se>::x)flag=0;
//	printf("%d %d %d %d\n",x,fl[x],mx,se);
	mxd[x]=mx;
}
int solve2(){
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		G[u].push_back(v),G[v].push_back(u);
	}
	for(int i=1;i<(1<<n);i++){
//		int i=10;
		for(int j=0;j<n;j++)fl[j+1]=i>>j&1;
		flag=1;dfs(1,0);
		ans[__builtin_popcount(i)]+=flag;
//		printf("%d %d\n",i,flag);
	}
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
} 
int solve4(){
	if(!x)return solve1();
	ans[1]=n;
	if(x==1){
		ans[2]=n-1;
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	}else{
		for(int i=1;i<=n;i++)printf("%d ",C(n,i));
	}
	return 0;
}
int solve5(){
	if(!x)return solve1();
	for(int i=1;i<=n;i++)ans[i]=(1ll*(n-x)*C(x,i-1)+C(x,i))%mod;
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	return 0;
}
int main(){
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	scanf("%d%d%d",&id,&n,&x);
	jie[0]=1;
	for(int i=1;i<=n;i++)jie[i]=1ll*jie[i-1]*i%mod;
	inv[n]=qpow(jie[n],mod-2);
	for(int i=n;i>=1;i--)inv[i-1]=1ll*inv[i]*i%mod;
	if(id==1)return solve1();
	if(id==2)return solve2();
	if(id==4)return solve4();
	if(id==5)return solve5();
	if(!x){
		for(int i=1;i<=n;i++)printf("%d ",i==1?n:0);
		return 0;
	}
	for(int i=1;i<=n;i++)printf("%d ",C(n,i));
	return 0;
}
/*
考虑dp
设dp[u][d][siz]表示u子树内 最深深度为d,选了siz个的方案数
5
5 1
1 2
2 3
3 4
4 5
*/
