#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,s,t,x,y,op;
int deg[110],deg0[110],u[10010],v[10010],OP[10010],tag[110];
long long inv[110],ans1,ans2;
long long f0[110],f1[110],f2[110];
long long a[110][110],ans[110];
vector<int> line[110],line0[110];
long long fastpow(long long x,int y){
	long long ans=1;
	while(y){
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
void calc(int n){
	for(int i=1;i<=n;++i){
		int p=-1;
		for(int j=i;j<=n;++j){
			if(a[j][i]) {p=j;break;}
		}
		if(p==-1){
			cerr<<"wa";
			continue;
		}
		if(p!=i){
			for(int j=i;j<=n+1;++j){
				swap(a[p][j],a[i][j]);
			}
		}
		for(int j=1;j<=n;++j){
			if(a[j][i]==0||i==j) continue;
			long long v=a[j][i]*fastpow(a[i][i],mod-2)%mod;
			for(int k=i;k<=n+1;++k){
				a[j][k]=(a[j][k]-a[i][k]*v)%mod;
				if(a[j][k]<0) a[j][k]+=mod;
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(a[i][i]){
			ans[i]=a[i][n+1]*fastpow(a[i][i],mod-2)%mod;
		}
	}
	return;
}
void dfs(int x){
	if(tag[x]) return;
	tag[x]=1;
	for(auto v:line[x]) dfs(v);
	return;
}
int main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&op);
		if(x==t) continue;
		++deg[x];
		if(op==1) line[y].push_back(x);
		line0[y].push_back(x);
	}
	for(int i=1;i<=n;++i){
		inv[i]=fastpow(deg[i],mod-2);
	}
	for(int i=1;i<=n;++i){
		for(auto v:line0[i]){
			a[i][v]=(a[i][v]+inv[v])%mod;
		}
		a[i][i]=(a[i][i]+mod-1)%mod;
		if(i==s) a[i][n+1]=(a[i][n+1]+mod-1)%mod;
	}
	calc(n);
	for(int i=1;i<=n;++i) f0[i]=ans[i];

	memset(a,0,sizeof(a));
	for(int i=1;i<=n;++i){
		for(auto v:line[i]){
			a[i][v]=(a[i][v]+inv[v])%mod;
			a[i][n+1]=(a[i][n+1]-inv[v]*f0[v])%mod;
			if(a[i][n+1]<0) a[i][n+1]+=mod;
		}
		a[i][i]=(a[i][i]+mod-1)%mod;
	}
	calc(n);
	for(int i=1;i<=n;++i) f1[i]=ans[i];

	memset(a,0,sizeof(a));
	for(int i=1;i<=n;++i){
		for(auto v:line[i]){
			a[i][v]=(a[i][v]+inv[v])%mod;
			a[i][n+1]=(a[i][n+1]-inv[v]*(f0[v]+2ll*f1[v]))%mod;
			if(a[i][n+1]<0) a[i][n+1]+=mod;
		}
		a[i][i]=(a[i][i]+mod-1)%mod;
	}
	calc(n);
	for(int i=1;i<=n;++i) f2[i]=ans[i];

	ans1=f1[t];
	ans2=ans1*ans1-2ll*ans1*f1[t]+f2[t];
	ans2%=mod;
	if(ans2<0) ans2+=mod;
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}