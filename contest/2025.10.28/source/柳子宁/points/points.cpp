#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n,m,M,ql,qr;
int l[200010],r[200010],tag[200010];
long long x,y,ans;
long long v[200010],L[200010],R[200010],F[200010];
pair<long long,long long> p[200010];
bool cmp(pair<long long,long long> x,pair<long long,long long> y){
	if(x.first!=y.first) return x.first>y.first;
	return x.second<y.second;
}
void solve(int l,int r){
	if(!ql){
		ql=l,qr=r;
		return;
	}
	long long rx=(::r[qr]),lx=(::l[l]);
	if(rx==lx){
		rx=v[rx],lx=v[lx];
		long long mn1=inf,mn2=inf,mn=inf;
		for(int i=ql;i<=qr;++i){
			mn1=min(mn1,F[i-1]-R[i]); 
			mn2=min(mn2,F[i-1]-2ll*R[i]); 
			mn=min(mn,F[i-1]+rx-R[i]); 
		}
		for(int i=l;i<=r;++i){
			F[i]=min(F[i],mn1+2ll*L[i]-lx);
			F[i]=min(F[i],mn2+L[i]+lx);
			F[i]=min(F[i],F[qr]+L[i]-lx);
		}
		F[qr]=min(mn,F[qr]);
	}
	else{
		rx=v[rx],lx=v[lx];
		long long mn=inf;
		for(int i=ql;i<=qr;++i){
			mn=min(mn,F[i-1]+rx-R[i]); 
		}
		mn=min(mn,F[qr]);
		for(int i=l;i<=r;++i){
			F[i]=min(F[i],mn+L[i]-lx);
		}
		F[qr]=min(mn,F[qr]);
	}
	ql=l,qr=r;
	return;
}
int main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	
	scanf("%d%d",&n,&M);
	for(int i=1;i<=n;++i) scanf("%lld",&v[i]);
	sort(v+1,v+n+1);
	for(int i=1;i<=M;++i){
		long long l=0,r=0;
		scanf("%lld%lld",&l,&r);
		if(v[n]<l){
			p[++m]=make_pair(l,r);
			continue;
		}
		int a=lower_bound(v+1,v+n+1,l)-v;
		if(v[a]<=r) continue;
		p[++m]=make_pair(l,r);
	}
	sort(p+1,p+m+1,cmp);
	long long mn=inf;
	M=m,m=0;
	for(int i=1;i<=M;++i){
		if(p[i].second<mn){
			mn=p[i].second;
			L[++m]=p[i].first,R[m]=p[i].second;
		}
	}
	reverse(L+1,L+m+1);
	reverse(R+1,R+m+1);
	
	ans=inf;
	for(int i=1;i<=m;++i){
		if(L[i]<=v[1]) l[i]=-1;
		else l[i]=lower_bound(v+1,v+n+1,L[i])-v-1;
		if(R[i]>=v[n]) r[i]=-1;
		else r[i]=lower_bound(v+1,v+n+1,R[i])-v;
		F[i]=inf;
		if(l[i]!=-1) tag[l[i]]=1;
		if(r[i]!=-1) tag[r[i]]=1;
	}
	
	int N=n;n=0;
	for(int i=1;i<=N;++i){
		if(tag[i]) v[++n]=v[i];
	}
	
//	for(int i=1;i<=n;++i) cerr<<v[i]<<' ';
//	cerr<<'\n';
//	for(int i=1;i<=m;++i) cerr<<L[i]<<' '<<R[i]<<'\n';
//	cerr<<'\n';
	
	for(int i=1;i<=m;++i){
		if(L[i]<=v[1]) l[i]=-1;
		else l[i]=lower_bound(v+1,v+n+1,L[i])-v-1;
		if(R[i]>=v[n]) r[i]=-1;
		else r[i]=lower_bound(v+1,v+n+1,R[i])-v;
	}
	
	if(l[1]!=-1){
		for(int i=1;i<=m;++i){
			if(v[l[1]]<=L[i]) F[i]=L[i]-v[l[1]];
		}
	}
	
	for(int i=2;i<=m+1;++i){
		if(l[i-1]!=l[i]||i==m+1) solve(qr+1,i-1);
	}
	long long ans=F[m];
	if(r[m]!=-1){
		for(int i=1;i<=m;++i) ans=min(ans,F[i-1]+v[r[m]]-R[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
