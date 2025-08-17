#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector> 
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int mod=1e9+9;
struct mat{
	int n,m,a[3][3];
	mat(){
		n=m=0;
		memset(a,0,sizeof a);
	}
};
mat operator *(mat x,mat y){
	mat z;
	z.n=x.n,z.m=y.m;
	memset(z.a,0,sizeof z.a);
	for(register int k=0;k<x.m;k++) for(register int i=0;i<z.n;i++) for(register int j=0;j<z.m;j++) z.a[i][j]=(z.a[i][j]+1ll*x.a[i][k]*y.a[k][j])%mod;
	return z;
}
bool operator ==(mat x,mat y){
	if(x.n!=y.n||x.m!=y.m) return 0;
	for(register int i=0;i<x.n;i++) for(register int j=0;j<x.m;j++) if(x.a[i][j]!=y.a[i][j]) return 0;
	return 1;
}
mat operator +(mat x,mat y){
	mat z;
	z.n=x.n;
	z.m=x.m;
	for(register int i=0;i<x.n;i++) for(register int j=0;j<x.m;j++) z.a[i][j]=(x.a[i][j]+y.a[i][j])%mod;
	return z;
}
const int N=1e5+5;
struct node{
	mat sum,tag;
}q[N<<2];
mat P;
int n,m,Q;
void build(int l,int r,int id){
	if(l==r){
		q[id].sum.n=1,q[id].sum.m=3;
		q[id].sum.a[0][2]=1;
		q[id].sum.a[0][0]=q[id].sum.a[0][0]=0;
		q[id].tag=P;
		return;
	}
	int mid=l+r>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	q[id].tag=P;
	q[id].sum=q[id<<1].sum+q[id<<1|1].sum;
}
void pd(int id){
	if(q[id].tag==P) return;
	q[id<<1].sum=q[id<<1].sum*q[id].tag;
	q[id<<1|1].sum=q[id<<1|1].sum*q[id].tag;
	q[id<<1].tag=q[id<<1].tag*q[id].tag;
	q[id<<1|1].tag=q[id<<1|1].tag*q[id].tag;
	q[id].tag=P;
}
void add(int L,int R,int l,int r,int id,mat v){
	if(L<=l&&r<=R){
		q[id].sum=q[id].sum*v;
		q[id].tag=q[id].tag*v;
		return;
	}
	pd(id);
	int mid=l+r>>1;
	if(L<=mid) add(L,R,l,mid,id<<1,v);
	if(R>mid) add(L,R,mid+1,r,id<<1|1,v);
	q[id].sum=q[id<<1].sum+q[id<<1|1].sum;
}
mat get(int L,int R,int l,int r,int id){
	if(L<=l&&r<=R) return q[id].sum;
	pd(id);
	int mid=l+r>>1;
	if(L<=mid&&R>mid) return get(L,R,l,mid,id<<1)+get(L,R,mid+1,r,id<<1|1);
	else if(L<=mid) return get(L,R,l,mid,id<<1);
	else return get(L,R,mid+1,r,id<<1|1);
}
pair<pair<int,int>,int> a[N];
int ans[N];
vector<pair<pair<int,int>,pair<int,int> > > e[N];
void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	P.n=3,P.m=3;
	P.a[0][0]=1,P.a[1][1]=1,P.a[2][2]=1;
	n=read(),m=read(),Q=read();
	build(1,n,1);
	for(register int i=1;i<=m;i++) a[i].first.first=read(),a[i].first.second=read(),a[i].second=read();
	for(register int i=1;i<=Q;i++){
		int u=read(),d=read(),l=read(),r=read();
		if(u) e[u-1].push_back(make_pair(make_pair(l,r),make_pair(i,mod-1)));
		e[d].push_back(make_pair(make_pair(l,r),make_pair(i,1))); 
	}
	mat op=P;
	op.a[0][1]=1;
	mat asd=P;
	for(register int i=1;i<=m;i++){
		op.a[2][0]=0;
		op.a[2][1]=0;
		add(1,n,1,n,1,op);
		asd.a[2][0]=a[i].second;
		asd.a[2][1]=a[i].second;
		add(a[i].first.first,a[i].first.second,1,n,1,asd);
		for(register int j=0;j<e[i].size();j++){
			mat po=get(e[i][j].first.first,e[i][j].first.second,1,n,1);
			ans[e[i][j].second.first]=(ans[e[i][j].second.first]+1ll*e[i][j].second.second*po.a[0][1]%mod)%mod;
		}
	}
	for(register int i=1;i<=Q;i++){
		write(ans[i]);
		putchar('\n');
	}
	return 0;
}
/*
10 9 1
3 10 1
2 8 1
1 10 1
2 7 1
2 9 1
2 9 1
2 6 1
2 6 1
3 10 1
5 9 2 6
*/
