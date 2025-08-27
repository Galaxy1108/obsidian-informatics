#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int Tid,n,x,y,D,rt,tag;
int dis[2010][2010],Dis[300010];
long long ans[300010];
long long fac[300010],invfac[300010];
vector<int> son[300010];
long long fastpow(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
} 
long long C(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
void Init(){
	int N=300002;fac[0]=1;
	for(int i=1;i<=N;++i) fac[i]=fac[i-1]*i%mod;
	invfac[N]=fastpow(fac[N],mod-2);
	for(int i=N;i>=1;--i) invfac[i-1]=invfac[i]*i%mod;
	return;
}
void workdis(int x,int fa,int D){
	Dis[x]=D;
	for(auto v:son[x]){
		if(v==fa) continue;
		workdis(v,x,D+1);
	}
	return;
}
int main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	scanf("%d%d%d",&Tid,&n,&D);
	if(D==0){
		ans[1]=n;
		for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
		return 0;
	}
	if(D==1){
		ans[1]=n;
		ans[2]=n-1;
		for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
		return 0;
	}
	Init();
	for(int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		son[x].push_back(y);
		son[y].push_back(x);
	}
	if(46<=Tid&&Tid<=49){
		ans[1]=n;
		ans[2]=n-1;
		if(D>=2){
			for(int i=1;i<=n;++i) ans[i]=C(n,i);
		}
		for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
		return 0;
	}
	if(n<=20){
		for(int i=1;i<=n;++i){
			workdis(i,0,0);
			for(int j=1;j<=n;++j) dis[i][j]=Dis[j];
		}
		for(int S=1;S<(1<<n);++S){
			int tag=1,siz=0;
			for(int i=1;i<=n;++i){
				if(S>>(i-1)&1) ++siz;
				else continue;
				for(int j=i+1;j<=n;++j){
					if((S>>(j-1)&1)&&dis[i][j]>D) tag=0;
				}
			}
			if(tag) ++ans[siz];
		} 
		for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
		return 0;
	}
	tag=1;
	workdis(1,0,0);
	for(int j=1;j<=n;++j) if(Dis[j]>Dis[rt]) rt=j;
	workdis(rt,0,0);
	for(int j=1;j<=n;++j) if(Dis[j]>D) tag=0;
	if(tag){
		for(int i=1;i<=n;++i) ans[i]=C(n,i);
		for(int i=1;i<=n;++i) printf("%lld ",ans[i]);
		return 0;
	}
	return 0;
} 
