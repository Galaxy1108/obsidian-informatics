#include <bits/stdc++.h>
using namespace std;
/*
f[i][S]:前i行，从左上到右下斜着压缩前k-1列为S的方案数
时间O(n*2^{(k+1)*k/2}*k)
空间O(8*n*2^{k*(k-1)/2})
只能过到k<=6 
*/
#define N 205
#define MOD 1000000007
#define go __builtin_popcount
int n,k,b[N],ya;
long long f[N][(1<<15)];
void solve1(){
	for(int i=1;i<=n;i++){
		if(b[i]>1){
			printf("0");
			return ;
		}
	}
	printf("1");
} 
void solve2(){
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int t=0;t<(1<<k);t++){
			for(int s=0;s<2;s++){
				if(go(t)+go(s)!=b[i])continue;
				f[i][(t&1)]+=f[i-1][s];
				if(f[i][(t&1)]>=MOD)f[i][(t&1)]-=MOD;
			}
		}
	}
	long long ans=0;
	for(int s=0;s<2;s++){
		ans+=f[n][s];
		if(ans>=MOD)ans-=MOD; 
	}
	printf("%lld",ans);
}
void solve3(){
	ya=(k)*(k-1)/2;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int t=0;t<(1<<k);t++){//是从k行到1行的 
			for(int s=0;s<(1<<ya);s++){
				if(go(t)+go(s)!=b[i])continue;
				static int to;to=(s<<(k-1)&((1<<ya)-1))|(t&3);
				f[i][to]+=f[i-1][s];
				if(f[i][to]>=MOD)f[i][to]-=MOD;
			}
		}
	}
	long long ans=0;
	for(int s=0;s<(1<<ya);s++){
		ans+=f[n][s];
		if(ans>=MOD)ans-=MOD; 
	}
	printf("%lld",ans);
} 
int getto(int s,int t){
	static int g,cnt,res;
	res=(t&1);cnt=1;
	t>>=1;
	for(int i=1;i<=k-2;i++){
		g=s&((1<<i)-1);
		res|=(g<<1|(t&1))<<cnt;
		cnt+=i+1;
		s>>=i;
		t>>=1;
	}
	return res;
}
void solveot(){
	ya=(k)*(k-1)/2;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int t=0;t<(1<<k);t++){//是从k行到1行的 
			for(int s=0;s<(1<<ya);s++){
				if(go(t)+go(s)!=b[i])continue;
				static int to;to=getto(s,t);
				f[i][to]+=f[i-1][s];
				if(f[i][to]>=MOD)f[i][to]-=MOD;
			}
		}
	}
	long long ans=0;
	for(int s=0;s<(1<<ya);s++){
		ans+=f[n][s];
		if(ans>=MOD)ans-=MOD; 
	}
	printf("%lld",ans);
} 
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	switch(k){
	case 1:
		solve1();
		break;
	case 2:
		solve2();
		break;
	case 3:
		solve3();
		break;
	default:
		solveot();
		break;
	}
	return 0;
}

