#include<bits/stdc++.h>
using namespace std;
const int N=2.5e5+5,mod=998244353;
int a[N],b[N],c[N];
struct Matrix{
	int a[4][4];
	int*operator[](int x){
		return a[x];
	}
	Matrix(){
		memset(a,0,sizeof(a));
	}
//	void operator=(Matrix y){
//		memcpy(a,y.a,sizeof(a));
//	}
}tag[N<<2],I;
struct Line{
	int a[4];
	Line(){
		memset(a,0,sizeof(a));
	}
	int&operator[](int x){
		return a[x];
	}
}t[N<<2];
Line operator*(Matrix a,Line b){
	Line res;
	for(int i=0;i<4;i++)
		for(int k=0;k<4;k++)
			res[i]=(res[i]+1ll*a[i][k]*b[k])%mod;
	return res;
}
Line operator+(Line a,Line b){
	Line res;
	for(int i=0;i<4;i++)res[i]=(a[i]+b[i])%mod;
	return res;
}
Matrix operator*(Matrix a,Matrix b){
	Matrix res;
//	for(int i=0;i<4;i++)assert(a[i][i]);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++)
				res[i][j]=(res[i][j]+1ll*a[i][k]*b[k][j])%mod;
//	for(int i=0;i<4;i++)assert(res[i][i]);
	return res;
}
bool operator==(Matrix a,Matrix b){
	for(int i=0;i<4;i++)for(int j=0;j<4;j++)if(a[i][j]!=b[i][j])return 0;
	return 1;
}
void upd(int p,Matrix v){
	t[p]=v*t[p];
	tag[p]=v*tag[p];
}
void pushup(int p){
	t[p]=t[p<<1]+t[p<<1|1];
}
void pushdown(int p){
	if(tag[p]==I)return;//puts("QAQ");
	upd(p<<1,tag[p]);
	upd(p<<1|1,tag[p]);
	tag[p]=I;
}
void change(int p,int l,int r,int l1,int r1,Matrix v){
	if(l1<=l&&r<=r1)return upd(p,v);
	int mid=l+r>>1;pushdown(p);
	if(l1<=mid)change(p<<1,l,mid,l1,r1,v);
	if(r1>mid)change(p<<1|1,mid+1,r,l1,r1,v);
	pushup(p);
}
Line query(int p,int l,int r,int l1,int r1){
	if(l1<=l&&r<=r1)return t[p];
	int mid=l+r>>1;Line res;pushdown(p);
	if(l1<=mid)res=res+query(p<<1,l,mid,l1,r1);
	if(r1>mid)res=res+query(p<<1|1,mid+1,r,l1,r1);
	return res;
}
void build(int p,int l,int r){
	tag[p]=I;
	if(l==r){
		t[p][0]=a[l];t[p][1]=b[l];t[p][2]=c[l];t[p][3]=1;
		return;
	}int mid=l+r>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
int n,m;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<4;i++)I[i][i]=1;
	for(int i=1;i<=n;i++)scanf("%d%d%d",a+i,b+i,c+i);
	scanf("%d",&m);
	build(1,1,n);
	while(m--){
		int op,l,r,val;scanf("%d%d%d",&op,&l,&r);
		if(op==7){
			auto res=query(1,1,n,l,r);
			printf("%d %d %d\n",res[0],res[1],res[2]);
			continue;
		}
		Matrix v;
		if(op==1){
			for(int i=0;i<4;i++)v[i][i]=1;
			v[0][1]=1;
		}
		if(op==2){
			for(int i=0;i<4;i++)v[i][i]=1;
			v[1][2]=1;
		}
		if(op==3){
			for(int i=0;i<4;i++)v[i][i]=1;
			v[2][0]=1;
		}
		if(op==4){
			scanf("%d",&val);
			for(int i=0;i<4;i++)v[i][i]=1;
			v[0][3]=val;
		}
		if(op==5){
			scanf("%d",&val);
			for(int i=0;i<4;i++)v[i][i]=1;
			v[1][1]=val;
		}
		if(op==6){
			scanf("%d",&val);
			for(int i=0;i<4;i++)v[i][i]=1;
			v[2][2]=0;
			v[2][3]=val;
		}change(1,1,n,l,r,v);
	}
	return 0;
}
/*
2
2 3 3
6 6 6
4
7 1 2
1 1 2
4 1 2 3
7 1 2

*/ 
