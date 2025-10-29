#include<bits/stdc++.h>
using namespace std;
using ll =long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=200+5;
int n,p[maxn];
ll mod,c[maxn*maxn];
int main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	//我有一个绝妙的做法（真的有）
	//可惜现在时间不够写不完（真的写不完）
	n=read();
	mod=read();
	for(int i=1;i<=n;i++) p[i]=i;
	ll ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++) cnt+=p[i]>p[j];
		c[cnt]=(c[cnt]+1)%mod;
		for(int i=cnt+1;i<=n*(n-1)/2;i++) ans=(ans+c[i])%mod;
	}while(next_permutation(p+1,p+n+1));
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}