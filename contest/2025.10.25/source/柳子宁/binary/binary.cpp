#include<bits/stdc++.h>
using namespace std;
int n,Q,l,r,x,op;
int a[100010];
struct Data{
	int l,r;
	int a0,b0,p0,q0;
	int a1,b1,p1,q1;
	long long ans;
}E[2];
Data operator *(Data x,Data y){
	if(x.l==-1) return y;
	Data ans={x.l,y.r,0,0,0,0,0,0,0,0,0};
	if(x.a0==-1) ans.a0=y.a0,ans.b0=y.b0;
	else if(x.b0==-1) ans.a0=x.a0,ans.b0=y.a0;
	else ans.a0=x.a0,ans.b0=x.b0;
	
	if(x.a1==-1) ans.a1=y.a1,ans.b1=y.b1;
	else if(x.b1==-1) ans.a1=x.a1,ans.b1=y.a1;
	else ans.a1=x.a1,ans.b1=x.b1;
	
	if(y.q0==-1) ans.q0=x.q0,ans.p0=x.p0;
	else if(y.p0==-1) ans.q0=y.q0,ans.p0=x.q0;
	else ans.q0=y.q0,ans.p0=y.p0;

	if(y.q1==-1) ans.q1=x.q1,ans.p1=x.p1;
	else if(y.p1==-1) ans.q1=y.q1,ans.p1=x.q1;
	else ans.q1=y.q1,ans.p1=y.p1;

	ans.ans=x.ans+y.ans;
	long long l1=0,l2=0,r1=0,r2=0;
	if(x.q0!=-1){
		l1=x.r-x.q0;
		if(x.p0!=-1) l2=x.q0-x.p0;
		else l2=x.q0-x.l+1;
	}
	else l1=x.r-x.l+1;
	if(y.a0!=-1){
		r1=y.a0-y.l;
		if(y.b0!=-1) r2=y.b0-y.a0;
		else r2=y.r-y.a0+1;
	}
	else r1=y.r-y.l+1;

	long long ox=0,ex=0,oy=0,ey=0;
	if(l1&&r1){
		ex=l1/2,ox=l1-ex;
		ey=r1/2,oy=r1-ey;
		ans.ans+=ex*oy+ox*ey;
	}
	if(l2&&r1){
		ex=l2/2,ox=l2-ex; if(l1%2==0) swap(ex,ox); 
		ey=r1/2,oy=r1-ey;
		ans.ans+=ex*oy+ox*ey;
	}
	if(l1&&r2){
		ex=l1/2,ox=l1-ex; 
		ey=r2/2,oy=r2-ey; if(r1%2==0) swap(ey,oy);
		ans.ans+=ex*oy+ox*ey;
	}

	l1=0,l2=0,r1=0,r2=0;
	if(x.q1!=-1){
		l1=x.r-x.q1;
		if(x.p1!=-1) l2=x.q1-x.p1;
		else l2=x.q1-x.l+1;
	}
	else l1=x.r-x.l+1;
	if(y.a1!=-1){
		r1=y.a1-y.l;
		if(y.b1!=-1) r2=y.b1-y.a1;
		else r2=y.r-y.a1+1;
	}
	else r1=y.r-y.l+1;

	ans.ans=ans.ans+l1*r2+l2*r1;

	int X=0,Y=0;
	if(x.q0==x.r) X=0;
	else X=1;
	if(y.a0==y.l) Y=0;
	else Y=1;
	if(X^Y) --ans.ans;
	return ans;
}
namespace Segtree{
	struct Node{
		int l,r;
		Data val;
	}tree[400010];
	void Build(const int p,const int l,const int r){
		tree[p].l=l,tree[p].r=r;
		if(l==r){
			if(a[l]) tree[p].val=(Data){l,l,-1,-1,-1,-1,l,-1,-1,l,1};
			else tree[p].val=(Data){l,l,l,-1,-1,l,-1,-1,-1,-1,0};
			return;
		}
		const int mid=(l+r)>>1;
		Build(p<<1,l,mid);
		Build(p<<1|1,mid+1,r);
		tree[p].val=tree[p<<1].val*tree[p<<1|1].val;
		return;
	}
	void Modify(const int p,const int l,const int r){
		if(l<=tree[p].l&&tree[p].r<=r){
			if(a[l]) tree[p].val=(Data){l,l,-1,-1,-1,-1,l,-1,-1,l,1};
			else tree[p].val=(Data){l,l,l,-1,-1,l,-1,-1,-1,-1,0};
			return;
		}
		const int mid=(tree[p].l+tree[p].r)>>1;
		if(l<=mid) Modify(p<<1,l,r);
		if(r>mid) Modify(p<<1|1,l,r);
		tree[p].val=tree[p<<1].val*tree[p<<1|1].val;
		return;
	}
	Data Query(const int p,const int l,const int r){
		if(l<=tree[p].l&&tree[p].r<=r) return tree[p].val;
		Data ans=(Data){-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
		const int mid=(tree[p].l+tree[p].r)>>1;
		if(l<=mid) ans=ans*Query(p<<1,l,r);
		if(r>mid) ans=ans*Query(p<<1|1,l,r);
		return ans;
	}
}
//long long solve(int l,int r){
//	long long ans=0;
//	for(int i=l;i<=r;++i){
//		int cnt0=0,cnt1=0;
//		for(int j=i;j<=r;++j){
//			if(!a[j]) ++cnt0;
//			else ++cnt1;
//			if(cnt1%2==0||(cnt1>=3&&cnt0>=2)) ++ans;
//		}
//	}
//	return ans;
//}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);

	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	Segtree::Build(1,1,n);
	scanf("%d",&Q);
	for(int i=1;i<=Q;++i){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&x),a[x]^=1;
			Segtree::Modify(1,x,x);
		}
		else{
			scanf("%d%d",&l,&r);
			Data val=Segtree::Query(1,l,r);
			long long Ans=1ll*(r-l+1)*(r-l+2)/2;
			printf("%lld\n",Ans-val.ans);
		}
	}
	return 0;
}
