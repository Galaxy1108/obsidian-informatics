#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int n,m,op,l,r,V;
int A[250010],B[250010],C[250010];
struct Matrix{
	long long a[4][4];
	Matrix operator *(const Matrix &x) const{
		Matrix ans;
		for(int i=0;i<=3;++i){
			for(int j=0;j<=3;++j){
				ans.a[i][j]=0;
				for(int k=0;k<=3;++k){
					ans.a[i][j]+=a[i][k]*x.a[k][j];
				}
				ans.a[i][j]%=mod;
			}
		}
		return ans;
		// #define Mul(x,y,p,q) (a[x][y]*x.a[p][q]) 
		// #define Get(x,y) (Mul(x,0,0,y)+Mul(x,1,1,y)+Mul(x,2,2,y)+Mul(x,3,3,y))
		// ans.a[0][0]=Get(0,0)%mod;
		// ans.a[0][1]=Get(0,1)%mod;
		// ans.a[0][2]=Get(0,2)%mod;
	}
}E,tag;
struct Vector{
	long long a[4];
	Vector operator +(const Vector &x) const{
		Vector ans;
		ans.a[0]=a[0]+x.a[0];if(ans.a[0]>=mod) ans.a[0]-=mod;
		ans.a[1]=a[1]+x.a[1];if(ans.a[1]>=mod) ans.a[1]-=mod;
		ans.a[2]=a[2]+x.a[2];if(ans.a[2]>=mod) ans.a[2]-=mod;
		ans.a[3]=a[3]+x.a[3];
		return ans;
	}
	Vector operator *(const Matrix &x) const{
		Vector ans;
		for(int i=0;i<=3;++i){
			ans.a[i]=0;
			for(int j=0;j<=3;++j){
				ans.a[i]+=a[j]*x.a[j][i];
			}
			ans.a[i]%=mod;
		}
		return ans;
	}
};
struct Segtree{
	int l,r;
	Vector val;
	Matrix tag;
}tree[1000010];
void Pushdown(const int p){
	tree[p<<1].val=tree[p<<1].val*tree[p].tag;
	tree[p<<1|1].val=tree[p<<1|1].val*tree[p].tag;
	tree[p<<1].tag=tree[p<<1].tag*tree[p].tag;
	tree[p<<1|1].tag=tree[p<<1|1].tag*tree[p].tag;
	tree[p].tag=E;
	return;
}
void Build(const int p,const int l,const int r){
	tree[p].l=l,tree[p].r=r,tree[p].tag=E;
	if(l==r){
		tree[p].val=(Vector){A[l],B[l],C[l],1};
		return;
	}
	const int mid=(l+r)>>1;
	Build(p<<1,l,mid);Build(p<<1|1,mid+1,r);
	tree[p].val=tree[p<<1].val+tree[p<<1|1].val;
	return;
}
void Modify(const int p,const int l,const int r,const Matrix tag){
	if(l<=tree[p].l&&tree[p].r<=r){
		tree[p].tag=tree[p].tag*tag;
		tree[p].val=tree[p].val*tag;
		return;
	}
	Pushdown(p);
	const int mid=(tree[p].l+tree[p].r)>>1;
	if(l<=mid) Modify(p<<1,l,r,tag);
	if(r>mid) Modify(p<<1|1,l,r,tag);
	tree[p].val=tree[p<<1].val+tree[p<<1|1].val;
	return;
}
Vector Query(const int p,const int l,const int r){
	if(l<=tree[p].l&&tree[p].r<=r){
		return tree[p].val;
	}
	Pushdown(p);
	const int mid=(tree[p].l+tree[p].r)>>1;
	Vector ans=(Vector){0,0,0,0};
	if(l<=mid) ans=ans+Query(p<<1,l,r);
	if(r>mid) ans=ans+Query(p<<1|1,l,r);
	return ans;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	clock_t st=clock();
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>A[i]>>B[i]>>C[i];
	E.a[0][0]=1;E.a[1][1]=1;E.a[2][2]=1;E.a[3][3]=1;
	Build(1,1,n);
	cin>>m;
	for(int i=1;i<=m;++i){
		cin>>op>>l>>r;
		if(op>=4&&op<=6) cin>>V;
		tag=E;
		if(op==1) tag.a[1][0]=1;
		if(op==2) tag.a[2][1]=1;
		if(op==3) tag.a[0][2]=1;
		if(op==4) tag.a[3][0]=V;
		if(op==5) tag.a[1][1]=V;
		if(op==6) tag.a[2][2]=0,tag.a[3][2]=V;
		if(op<=6) Modify(1,l,r,tag);
		else{
			Vector Ans=Query(1,l,r);
			cout<<Ans.a[0]<<' '<<Ans.a[1]<<' '<<Ans.a[2]<<'\n';
		}
	}
	cerr<<(clock()-st)*1.0/CLOCKS_PER_SEC<<'\n';
	return 0;
}