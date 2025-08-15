#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,V,f1;
int a[1000010],b[1000010],lst[1000010],id[1000010],lim[1000010];
long long ans;
long long f[1000010],tree[1000010],sum[1000010];
void Add(int x,long long val){
	if(val<0) val+=mod;
	while(x){
		tree[x]+=val;
		if(tree[x]>=mod) tree[x]-=mod;
		x-=(x&(-x));
	}
	return;
}
long long Ask(int x){
	long long ans=0;
	while(x<=V){
		ans+=tree[x];
		if(ans>=mod) ans-=mod;
		x+=(x&(-x));
	}
	return ans;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		V=max(V,a[i]);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i) scanf("%d",&b[i]);
	for(int i=1;i<=n;++i){
		if(f1<m&&b[f1+1]==a[i]){
			++f1;
			lim[i]=b[f1+1];
		}
		else lim[i]=V;
	}
	for(int i=1;i<=n;++i){
		lst[i]=id[a[i]];
		if(lst[i]==0&&a[i]<=b[1]) ++f[i];
		long long val=Ask(a[i]);
		f[i]=(f[i]+val-sum[a[i]])%mod;
		sum[a[i]]=val;
		if(f[i]<0) f[i]+=mod;
		Add(lim[i],1),Add(V,f[i]-1);
		id[a[i]]=i;
		ans=ans+f[i];
		if(ans>=mod) ans-=mod;
	}
	printf("%lld\n",ans);
	return 0;
}
