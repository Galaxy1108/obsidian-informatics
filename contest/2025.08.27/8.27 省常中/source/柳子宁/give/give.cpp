#include<bits/stdc++.h>
using namespace std;
int T,n,lim,K,ans;
int mi[210],si[210],a[210];
bitset<200010> f[64],g,now;
long long m,S;
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%d",&m,&S,&n);
		for(int k=0;k<=63;++k) f[k].reset();
		g.reset();
		memset(si,0,sizeof(si));
		memset(mi,0,sizeof(mi));
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),lim=max(lim,2*a[i]);
		for(int k=0;k<=62;++k){
			if(m>>k) K=k;
			else break;
		}
		if((S>>K)<=lim) f[1][S>>K]=1;
		for(int k=K,i=1;k>=0;--k,++i){
			si[i]=S>>k&1;
			mi[i]=m>>k&1;
		}
		for(int k=K,i=1;k>=-1;--k,++i){
			if(k==-1){
				ans=f[i][0];break;
			}
			if(i!=1){
				for(int j=0;j<=lim;++j) g[j]=0;
				for(int j=0;j<=lim;++j){
					if(j*2+si[i]<=lim) g[j*2+si[i]]=f[i][j];
				}
				for(int j=0;j<=lim;++j) f[i][j]=g[j];
			}
			if(mi[i]){
				for(int j=1;j<=n;++j){
					now=f[i]>>a[j];
					f[i+1]^=now;
				}
			}
			else for(int j=0;j<=lim;++j) f[i+1][j]=f[i][j];
		}
		printf("%d\n",ans);
	}
	return 0;
}
