#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
const int P=998244353;
long long p2[MAXN];
int a[MAXN];
int n;
struct segtree{
	struct{
		int lef,rig;
		long long sum,ma;
	}t[MAXN];
	void updata(int u){
		t[u].sum=(t[u<<1].sum+t[u<<1|1].sum)%P;
		t[u].ma=max(t[u<<1].ma,t[u<<1|1].ma);
		return;
	}
	void build(int u,int l,int r){
		if(l<r){
			int mid=(l+r)>>1;
			build(u<<1,l,mid);
			build(u<<1|1,mid+1,r);
			updata(u);
		}
		else
			t[u].sum=t[u].ma=a[l];
		t[u].lef=l,t[u].rig=r;
		return;
	}
	void modify(int u,int p,int k){
		if(t[u].lef==p&&t[u].rig==p){
			t[u].sum=t[u].ma=k;
			return;
		}
		if(t[u<<1].rig>=p)
			modify(u<<1,p,k);
		if(t[u<<1|1].lef<=p)
			modify(u<<1|1,p,k);
		updata(u);
		return;
	}
	long long qprs(int u,int p){
		if(t[u].rig<=p)
			return t[u].sum;
		long long s=qprs(u<<1,p);
		if(t[u<<1|1].lef<=p)
			s=(s+qprs(u<<1|1,p))%P;
		return s;
	}
	int qsfm(int u,int p){
		if(t[u].lef>=p)
			return t[u].ma;
		int s=qsfm(u<<1|1,p);
		if(t[u<<1].rig>=p)
			s=max(s,qsfm(u<<1,p));
		return s;
	}
}T;
long long calc(){
	long long ans;
	int l=0,r=n,mid,tmp;
	while(l+1<r){
		mid=(l+r)>>1;
		if(T.qprs(1,mid)-T.qsfm(1,mid+1)>=0){
			r=mid;
		}
		else
			l=mid;
	}
//	cout<<"max:"<<r<<' '<<endl;
	ans=p2[r];
	if(a[r]>=T.qsfm(1,r+1))
		return ans;
	tmp=T.qsfm(1,r+1)-a[r];
	l=0,r=r-1;
	while(l+1<r){
		mid=(l+r)>>1;
		if(T.qprs(1,mid)>=tmp)
			r=mid;
		else
			l=mid;
	}
	tmp=T.qprs(1,r)-tmp;
//	cout<<"m2:"<<r<<' '<<ans<<' '<<tmp<<endl;;
	ans=(ans+p2[r+1]-2)%P;
	for(int i=r-1;i>=1;i--){
		if(a[i]<=tmp){
			tmp-=a[i];
			ans-=p2[i];
		}
	}
	return (ans%P+P)%P;
}
int main(){
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	int num,q;
	scanf("%d%d",&num,&n);
	p2[0]=1;
	for(int i=1;i<=n;i++)
		p2[i]=(p2[i-1]<<1)%P;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	T.build(1,1,n);
	scanf("%d",&q);
//	for(int i=1,o,x,y;i<=q;i++){
//		scanf("%d%d",&o,&x);
//		if(o==1){
//			scanf("%d",&y);
//			T.modify(1,x,y); 
//		}
//		if(o==2)
//			cout<<T.qprs(1,x)<<endl;
//		if(o==3)
//			cout<<T.qsfm(1,x)<<endl;
//	}
//	return 0;
	for(int i=0,x,y;i<=q;i++){
		printf("%lld\n",calc());
		if(i!=q){
			scanf("%d%d",&x,&y);
			T.modify(1,x,y);
			a[x]=y;
		}
	}
	return 0;
}
