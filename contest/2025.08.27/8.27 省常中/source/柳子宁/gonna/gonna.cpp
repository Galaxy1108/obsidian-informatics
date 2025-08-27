#include<bits/stdc++.h>
using namespace std;
int n,mod,cntp;
int prime[20010],id[20010],cnt[3010],sum[3010],lst[20010];
long long ans[20010],Ans;
long long val[3010][21],pw[3010][21],now[20010];
vector<pair<int,int> > V[300010]; 
long long fastpow(long long x,long long y){
	long long ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
void calc(int x){
	for(int j=2;j*j<=x;++j){
		while(x%j==0) cnt[id[j]]++,x/=j;
	}
	if(x>1) cnt[id[x]]++;
	return;
}
void Init(){
	int N=20000;
	for(int i=2;i<=N;++i){
		int tag=1;
		for(int j=2;j*j<=i;++j){
			if(i%j==0) tag=0;
		}
		if(tag) prime[++cntp]=i,id[i]=cntp;
	}
	for(int i=1;i<=cntp;++i){
		val[i][0]=pw[i][0]=1;
		for(int k=1;k<=20;++k){
			val[i][k]=(val[i][k-1]*prime[i]+1)%mod;
			pw[i][k]=(pw[i][k-1]*prime[i])%mod;
		}
	}
	return;
}
long long calc(long long x,long long y){
	if(!y) return 1;
	if(y&1) return (fastpow(x,(y+1)/2)+1)*calc(x,y>>1)%mod;
	return (calc(x,y-1)*x+1)%mod;
}
int main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	clock_t st=clock();
	scanf("%d%d",&n,&mod);
	Init();
	for(int i=1;i<=n;++i){
		calc(i);
		for(int j=1;j<=cntp;++j) sum[j]=sum[j]+cnt[j];
		for(int j=1;j<=cntp;++j){
			if(cnt[j]*(i+1)-2*sum[j]){
				V[cnt[j]*(i+1)-2*sum[j]].push_back(make_pair(j,i));
			}
		}
		ans[i]=1;
	}
	for(int i=1;i<=cntp;++i) now[i]=1;
	for(int i=1;i<=300000;++i){
		for(auto v:V[i]){
			if(i-lst[v.first]<=20&&i-lst[v.first]>0){
				now[v.first]=now[v.first]*pw[v.first][i-lst[v.first]]%mod;
				now[v.first]=(now[v.first]+val[v.first][i-lst[v.first]-1])%mod;
			}
			else if(i-lst[v.first]!=0){
				now[v.first]=now[v.first]*fastpow(prime[v.first],i-lst[v.first])%mod;
				now[v.first]=(now[v.first]+calc(prime[v.first],i-lst[v.first]-1))%mod;
			}
			ans[v.second]=(ans[v.second]*now[v.first])%mod;
			lst[v.first]=i;
		}
	}
	for(int i=1;i<=n;++i){
		Ans=(Ans+ans[i])%mod;
	}
	cerr<<(clock()-st)*1.0/CLOCKS_PER_SEC<<'\n';
	printf("%lld\n",Ans);
	return 0;
}
