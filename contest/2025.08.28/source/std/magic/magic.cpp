#include <bits/stdc++.h>
#define Mod 998244353
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int chk(int a){return a>=Mod?a-Mod:a;}
struct Matrix{
	int num[4][4];
};
Matrix operator*(Matrix A,Matrix B)
{
	Matrix C;
	memset(C.num,0,sizeof(C.num));
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
	for(int k=0;k<4;k++)
		C.num[i][k]=(C.num[i][k]+(long long)A.num[i][j]*B.num[j][k])%Mod;
	return C;
}
struct Vector{
	int num[4];
	void init(int a,int b,int c,int d){num[0]=a,num[1]=b,num[2]=c,num[3]=d;}
};
Vector operator*(Vector A,Matrix B)
{
	Vector C;
	memset(C.num,0,sizeof(C.num)); 
	for(int i=0;i<4;i++)
	for(int j=0;j<4;j++)
		C.num[j]=(C.num[j]+(long long)A.num[i]*B.num[i][j])%Mod;
	return C;
}
Vector operator+(Vector A,Vector B)
{
	Vector C;
	for(int i=0;i<4;i++)
		C.num[i]=chk(A.num[i]+B.num[i]);
	return C;
}
Matrix E,Tr[7];
Vector rem;
int n;
int a[250010],b[250010],c[250010];
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid ((l+r)>>1)
struct Node{
	Vector num;
	bool hv_laz;
	Matrix laz;
}s[1000010];
void update(int pos){s[pos].num=s[ls].num+s[rs].num;}
void giv_laz(int pos,Matrix A)
{
	s[pos].hv_laz=true;
	s[pos].num=s[pos].num*A;
	s[pos].laz=s[pos].laz*A;
}
void pushdown(int pos)
{
	if(s[pos].hv_laz)
	{
		giv_laz(ls,s[pos].laz),giv_laz(rs,s[pos].laz);
		s[pos].laz=E;
	}
}
void Range_mul(int L,int R,int typ,int pos=1,int l=1,int r=n)
{
	if(L<=l&&r<=R) return giv_laz(pos,Tr[typ]);
	if(r<L||R<l) return;
	return pushdown(pos),Range_mul(L,R,typ,ls,l,mid),Range_mul(L,R,typ,rs,mid+1,r),update(pos);
}
Vector Range_sum(int L,int R,int pos=1,int l=1,int r=n)
{
	if(L<=l&&r<=R) return s[pos].num;
	pushdown(pos);
	if(R<=mid) return Range_sum(L,R,ls,l,mid);
	if(mid<L) return Range_sum(L,R,rs,mid+1,r);
	return Range_sum(L,R,ls,l,mid)+Range_sum(L,R,rs,mid+1,r);
}
void init(int pos=1,int l=1,int r=n)
{
	s[pos].laz=E;
	if(l==r) return s[pos].num.init(1,a[l],b[l],c[l]),void();
	init(ls,l,mid),init(rs,mid+1,r),update(pos);
}
#undef ls
#undef rs
#undef mid
int m,op,l,r;
int main() 
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	
	E.num[0][0]=E.num[1][1]=E.num[2][2]=E.num[3][3]=1;
	Tr[1]=Tr[2]=Tr[3]=Tr[4]=Tr[5]=Tr[6]=E;
	Tr[1].num[2][1]=1,Tr[2].num[3][2]=1,Tr[3].num[1][3]=1;
	Tr[6].num[3][3]=0;
	
	n=Qread();
	for(int i=1;i<=n;i++)
		a[i]=Qread(),b[i]=Qread(),c[i]=Qread();
	init();
	m=Qread();
	for(int i=1;i<=m;i++)
	{
		op=Qread(),l=Qread(),r=Qread();
		if(op==7)
		{
			rem=Range_sum(l,r);
			printf("%d %d %d\n",rem.num[1],rem.num[2],rem.num[3]);
		}
		else
		{
			if(op==4) Tr[4].num[0][1]=Qread();else
			if(op==5) Tr[5].num[2][2]=Qread();else
			if(op==6) Tr[6].num[0][3]=Qread();
			Range_mul(l,r,op);
		}
	}
	return 0;
}