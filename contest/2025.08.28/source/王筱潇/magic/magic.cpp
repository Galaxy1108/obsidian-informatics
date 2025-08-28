#include<bits/stdc++.h>
#define ll long long
#define N 250010
#define mod 998244353
using namespace std;
inline int read(){
	int x=0;
	char ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x;
}
int n,m,opt,x,y,a[N][5];
struct matrix{
	int a[4][4];
	inline matrix(){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				a[i][j]=0;
			}
		}
	}
	matrix operator*(const matrix& T)const{
		matrix res;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				res.a[i][j]=((1ll*a[i][0]*T.a[0][j]%mod+1ll*a[i][1]*T.a[1][j]%mod)%mod+(1ll*a[i][2]*T.a[2][j]%mod+1ll*a[i][3]*T.a[3][j]%mod)%mod)%mod;
			}
		}
		return res;
	}
	matrix operator+(const matrix& T)const{
		matrix res;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				res.a[i][j]=(a[i][j]+T.a[i][j])%mod;
			}
		}
		return res;
	}
};
matrix a1,a2,a3,a4,a5,a6,a7;
inline void init(){
	for(int i=0;i<4;i++){
		a1.a[i][i]=a2.a[i][i]=a3.a[i][i]=a4.a[i][i]=a5.a[i][i]=a6.a[i][i]=a7.a[i][i]=1;
	}
	a1.a[1][0]=a2.a[2][1]=a3.a[0][2]=1;
	a5.a[1][1]=a6.a[2][2]=0;
	return;
}
struct segment_tree{
	int l,r,lazy;
	matrix val,tag;
}tree[N<<2];
inline void pushup(int i){
//	for(int j=0;j<4;j++) tree[i].val.a[0][j]=(tree[i<<1].val.a[0][j]+tree[i<<1|1].val.a[0][j])%mod;
	tree[i].val.a[0][0]=(tree[i<<1].val.a[0][0]+tree[i<<1|1].val.a[0][0])%mod;
	tree[i].val.a[0][1]=(tree[i<<1].val.a[0][1]+tree[i<<1|1].val.a[0][1])%mod;
	tree[i].val.a[0][2]=(tree[i<<1].val.a[0][2]+tree[i<<1|1].val.a[0][2])%mod;
	tree[i].val.a[0][3]=(tree[i<<1].val.a[0][3]+tree[i<<1|1].val.a[0][3])%mod;
	return;
}
inline void pushdown(int i){
	if(!tree[i].lazy) return;
	tree[i<<1].val=tree[i<<1].val*tree[i].tag;
	tree[i<<1|1].val=tree[i<<1|1].val*tree[i].tag;
	tree[i<<1].tag=tree[i<<1].tag*tree[i].tag;
	tree[i<<1|1].tag=tree[i<<1|1].tag*tree[i].tag;
	tree[i<<1].lazy=tree[i<<1|1].lazy=1;
	tree[i].lazy=0;
	tree[i].tag=a7;
	return;
}
void build(int i,int l,int r){
	tree[i].l=l;
	tree[i].r=r;
	tree[i].tag=a7;
	if(l==r){
		tree[i].val.a[0][0]=a[l][1]%mod;
		tree[i].val.a[0][1]=a[l][2]%mod;
		tree[i].val.a[0][2]=a[l][3]%mod;
		tree[i].val.a[0][3]=1;
	}
	else{
		int mid=(l+r)>>1;
		build(i<<1,l,mid);
		build(i<<1|1,mid+1,r);
		pushup(i);
	}
	return;
}
void change(int i,int l,int r,matrix k){
	if(tree[i].l>=l&&tree[i].r<=r){
		tree[i].val=tree[i].val*k;
		tree[i].tag=tree[i].tag*k;
		tree[i].lazy=1;
	}
	else{
		pushdown(i);
		int mid=(tree[i].l+tree[i].r)>>1;
		if(l<=mid) change(i<<1,l,r,k);
		if(r>mid) change(i<<1|1,l,r,k);
		pushup(i);
	}
	return;
}
matrix query(int i,int l,int r){
	if(tree[i].l>=l&&tree[i].r<=r) return tree[i].val;
	pushdown(i);
	int mid=(tree[i].l+tree[i].r)>>1;
	matrix ans;
	if(l<=mid) ans=ans+query(i<<1,l,r);
	if(r>mid) ans=ans+query(i<<1|1,l,r);
	return ans;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	init();
	n=read();
	for(int i=1;i<=n;i++) a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
	build(1,1,n);
	m=read();
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1) change(1,x,y,a1);
		if(opt==2) change(1,x,y,a2);
		if(opt==3) change(1,x,y,a3);
		if(opt==4) scanf("%d",&a4.a[3][0]),change(1,x,y,a4);
		if(opt==5) scanf("%d",&a5.a[1][1]),change(1,x,y,a5);
		if(opt==6) scanf("%d",&a6.a[3][2]),change(1,x,y,a6);
		if(opt==7){
			matrix ans=query(1,x,y);
			printf("%lld %lld %lld\n",ans.a[0][0],ans.a[0][1],ans.a[0][2]);
		}
	}
	return 0;
} 
