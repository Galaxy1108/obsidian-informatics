#include<bits/stdc++.h>
#define inf 1000000000000000000
using namespace std;
int n,MN,id,tot,Sum;
int m[200010];
long long val,ans;
multiset<int> S;
multiset<int>::iterator it;
vector<int> A[200010],a[200010];
vector<long long> f[200010];
void add(int x){
	it=S.lower_bound(x);
	int y=*it,z;
	if(y==x) return;
	z=(*prev(it));
	val-=1ll*(z-y)*(z-y);
	S.insert(x);
	val+=1ll*(x-z)*(x-z);
	val+=1ll*(y-x)*(y-x);
	return;
}
void solve(int x,int l,int r,int L,int R){
	if(l>r) return;
	int mid=(l+r)>>1;
	long long V=val;
	
	long long ans=inf;int p=-1;
	for(int i=l;i<mid;++i) add(a[x][i]);
	for(int i=R;i>=L;--i){
		add(a[x-1][i]);
		if(ans>=f[x-1][i]+val) ans=f[x-1][i]+val,p=i;
	}
	f[x][mid]=ans;
	val=V;
	for(int i=l;i<mid;++i){
		S.erase(S.lower_bound(a[x][i]));
	}
	for(int i=R;i>=L;--i) S.erase(S.lower_bound(a[x-1][i]));

	for(int i=p+1;i<=R;++i) add(a[x-1][i]);
	solve(x,l,mid-1,L,p);
	for(int i=p+1;i<=R;++i) S.erase(S.lower_bound(a[x-1][i]));
	
	val=V;
	for(int i=l;i<=mid;++i) add(a[x][i]);
	solve(x,mid+1,r,p,R);
	for(int i=l;i<=mid;++i){
		S.erase(S.lower_bound(a[x][i]));
	}
}
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	scanf("%d",&n);
	MN=1e9;ans=inf;
	for(int i=1;i<=n;++i){
		scanf("%d",&m[i]);
		if(m[i]<MN) MN=m[i],id=i;
		A[i].resize(m[i]+1);
		Sum+=m[i];
		for(int j=1;j<=m[i];++j) scanf("%d",&A[i][j]);
	}
	for(int i=id;i<=n;++i) a[++tot]=A[i];
	for(int i=1;i<id;++i) a[++tot]=A[i];
	for(int i=1;i<=n;++i) m[i]=(int)a[i].size()-1,A[i].clear();
	for(int i=1;i<=n;++i) f[i].resize(m[i]+1);
	for(int x=1;x<=m[1];++x){
		for(int j=1;j<=m[1];++j) f[1][j]=inf;
		f[1][x]=0;
		for(int i=2;i<=n;++i){
			if(Sum<=1000){
				for(int k=1;k<=m[i];++k) f[i][k]=inf;
				for(int j=1;j<=m[i-1];++j){
					S.clear(),S.insert(0),S.insert(2000000);
					val=1ll*2000000*2000000;
					for(int k=j;k<=m[i-1];++k){
						add(a[i-1][k]);
					}
					for(int k=1;k<=m[i];++k){
						f[i][k]=min(f[i][k],f[i-1][j]+val);
						add(a[i][k]);
					}
				}
			}
			else{
				S.clear(),S.insert(0),S.insert(2000000);
				val=1ll*2000000*2000000;
				for(int k=1;k<=m[i];++k) f[i][k]=inf;
				solve(i,1,m[i],1,m[i-1]);
			}
		}
		S.clear(),S.insert(0),S.insert(2000000);
		val=1ll*2000000*2000000;
		for(int j=1;j<x;++j) add(a[1][j]);
		for(int j=m[n];j>=1;--j){
			add(a[n][j]);
			ans=min(ans,val+f[n][j]);
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
