#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int mod=998244353;
struct mat{
	int a[4][4];
	mat(){
		memset(a,0,sizeof a);
	}
};
inline int add(int x,int y){
	x+=y;
	if(x>mod) x-=mod;
	return x;
}
inline int mul(int x,int y){return 1ll*x*y%mod;}
inline int sub(int x,int y){
	x-=y;
	if(x<0) x+=mod;
	return x;
}
inline mat operator *(mat x,mat y){
	mat z;
	z.a[0][0]=add(add(add(mul(x.a[0][0],y.a[0][0]),mul(x.a[0][1],y.a[1][0])),mul(x.a[0][2],y.a[2][0])),mul(x.a[0][3],y.a[3][0]));
	z.a[0][1]=add(add(add(mul(x.a[0][0],y.a[0][1]),mul(x.a[0][1],y.a[1][1])),mul(x.a[0][2],y.a[2][1])),mul(x.a[0][3],y.a[3][1]));
	z.a[0][2]=add(add(add(mul(x.a[0][0],y.a[0][2]),mul(x.a[0][1],y.a[1][2])),mul(x.a[0][2],y.a[2][2])),mul(x.a[0][3],y.a[3][2]));
	z.a[0][3]=add(mul(x.a[0][0],y.a[0][3]),mul(x.a[0][3],y.a[3][3]));
	z.a[1][0]=add(add(mul(x.a[1][0],y.a[0][0]),mul(x.a[1][1],y.a[1][0])),mul(x.a[1][2],y.a[2][0]));
	z.a[1][1]=add(add(mul(x.a[1][0],y.a[0][1]),mul(x.a[1][1],y.a[1][1])),mul(x.a[1][2],y.a[2][1]));
	z.a[1][2]=add(add(mul(x.a[1][0],y.a[0][2]),mul(x.a[1][1],y.a[1][2])),mul(x.a[1][2],y.a[2][2]));
	z.a[2][0]=add(add(mul(x.a[2][0],y.a[0][0]),mul(x.a[2][1],y.a[1][0])),mul(x.a[2][2],y.a[2][0]));
	z.a[2][1]=add(add(mul(x.a[2][0],y.a[0][1]),mul(x.a[2][1],y.a[1][1])),mul(x.a[2][2],y.a[2][1]));
	z.a[2][2]=add(add(mul(x.a[2][0],y.a[0][2]),mul(x.a[2][1],y.a[1][2])),mul(x.a[2][2],y.a[2][2]));
	z.a[3][0]=add(add(add(mul(x.a[3][0],y.a[0][0]),mul(x.a[3][1],y.a[1][0])),mul(x.a[3][2],y.a[2][0])),mul(x.a[3][3],y.a[3][0]));
	z.a[3][1]=add(add(add(mul(x.a[3][0],y.a[0][1]),mul(x.a[3][1],y.a[1][1])),mul(x.a[3][2],y.a[2][1])),mul(x.a[3][3],y.a[3][1]));
	z.a[3][2]=add(add(add(mul(x.a[3][0],y.a[0][2]),mul(x.a[3][1],y.a[1][2])),mul(x.a[3][2],y.a[2][2])),mul(x.a[3][3],y.a[3][2]));
	z.a[3][3]=x.a[3][3];
	return z;
}
inline mat operator +(mat x,mat y){
	x.a[0][0]=add(x.a[0][0],y.a[0][0]);
	x.a[0][1]=add(x.a[0][1],y.a[0][1]);
	x.a[0][2]=add(x.a[0][2],y.a[0][2]);
	x.a[0][3]=add(x.a[0][3],y.a[0][3]);
	return x;
}
inline bool operator ==(mat x,mat y){
	return x.a[0][0]==y.a[0][0]&&x.a[0][1]==y.a[0][1]&&x.a[0][2]==y.a[0][2]&&x.a[0][3]==y.a[0][3]&&x.a[1][0]==y.a[1][0]&&x.a[1][1]==y.a[1][1]&&x.a[1][2]==y.a[1][2]&&x.a[1][3]==y.a[1][3]&&x.a[2][0]==y.a[2][0]&&x.a[2][1]==y.a[2][1]&&x.a[2][2]==y.a[2][2]&&x.a[2][3]==y.a[2][3]&&x.a[3][0]==y.a[3][0]&&x.a[3][1]==y.a[3][1]&&x.a[3][2]==y.a[3][2]&&x.a[3][3]==y.a[3][3];
}
const int N=250005;
struct node{
	mat sum,tag;
}q[N<<2];
int n,Q;
int a[N],b[N],c[N];
mat P;
inline void pd(int id){
	if(q[id].tag==P) return;
	q[id<<1].sum=q[id<<1].sum*q[id].tag;
	q[id<<1|1].sum=q[id<<1|1].sum*q[id].tag;
	q[id<<1].tag=q[id<<1].tag*q[id].tag;
	q[id<<1|1].tag=q[id<<1|1].tag*q[id].tag;
	q[id].tag=P;
}
inline void change(int L,int R,int l,int r,int id,mat v){
	if(L<=l&&r<=R){
		q[id].sum=q[id].sum*v;
		q[id].tag=q[id].tag*v;
		return;	
	}
	pd(id);
	int mid=l+r>>1;
	if(L<=mid) change(L,R,l,mid,id<<1,v);
	if(R>mid) change(L,R,mid+1,r,id<<1|1,v);
	q[id].sum=q[id<<1].sum+q[id<<1|1].sum;
}
inline mat query(int L,int R,int l,int r,int id){
	if(L<=l&&r<=R) return q[id].sum;
	pd(id);
	int mid=l+r>>1;
	if(L<=mid&&R>mid) return query(L,R,l,mid,id<<1)+query(L,R,mid+1,r,id<<1|1);
	else if(L<=mid) return query(L,R,l,mid,id<<1);
	else return query(L,R,mid+1,r,id<<1|1);
}
inline void build(int l,int r,int id){
	q[id].tag=P;
	if(l==r){
		q[id].sum.a[0][0]=a[l];
		q[id].sum.a[0][1]=b[l];
		q[id].sum.a[0][2]=c[l];
		q[id].sum.a[0][3]=1;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	q[id].sum=q[id<<1].sum+q[id<<1|1].sum;
}
inline void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	for(register int i=0;i<4;i++) P.a[i][i]=1;
	n=read();
	for(register int i=1;i<=n;i++) a[i]=read(),b[i]=read(),c[i]=read();
	build(1,n,1);
	Q=read();
	while(Q--){
		int opt=read(),l=read(),r=read(),v;
		mat p=P;
		if(opt==1){
			p.a[1][0]=1;
			change(l,r,1,n,1,p);
		}
		else if(opt==2){
			p.a[2][1]=1;
			change(l,r,1,n,1,p);
		}
		else if(opt==3){
			p.a[0][2]=1;
			change(l,r,1,n,1,p);
		}
		else if(opt==4){
			v=read();
			p.a[3][0]=v;
			change(l,r,1,n,1,p);
		}
		else if(opt==5){
			v=read();
			p.a[1][1]=v;
			change(l,r,1,n,1,p);
		}
		else if(opt==6){
			v=read();
			p.a[3][2]=v;
			p.a[2][2]=0;
			change(l,r,1,n,1,p);
		}
		else{
			p=query(l,r,1,n,1);
			write(p.a[0][0]);
			putchar(' ');
			write(p.a[0][1]);
			putchar(' ');
			write(p.a[0][2]);
			putchar('\n');
		}
	}
	return 0;
}
