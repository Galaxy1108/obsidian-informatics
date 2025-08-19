#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch;
	while(!isnum(_ch))_ch=='-'&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=1e5+1,tzb[]={1,2,4,6,1024};
int n,m,K,flag,buff,debuff,dp[N<<1],cf[8],cg[8];
struct card{
	int w,opt;
	int type,power,spy,pos;
	V input(){
		w=getint(),opt=getint(),type=getint()-1;
		if(opt!=2)power=getint(),spy=getint();
		else{
			if(~type)type=tzb[type];
			if(!flag&&!~type)pos=1<<getint()-1;
		}
	}
	I val(int buff,int debuff){
		if(opt==2)return 0;
		if(opt==3)return power;
		int x=power,y=0;
		if(type==3){
			type=0,x=val(buff,debuff);
			type=1,y=val(buff,debuff);
			return type=3,max(x,y);
		}
		if(debuff>>type&1)x=min(x,1);
		if(buff>>type&1)x<<=1;
		return x;
	}
}a[N],b[N];
struct node{
	int v,w;
	I operator<(const node&u)const{return v>u.v;}
};
struct array_node{
	node t[N];int tot;
	V init(){sort(t+1,t+1+tot);}
	V rev(){reverse(t+1,t+1+tot);}
	V ins(const node&x){if(x.v)t[++tot]=x;}
	node&operator[](const int&x){return t[x];}
}f[8][8],g[8];
struct array_int{
	int t[N],tot;
	I&operator[](const int&x){return t[x];}
	V ins(const int&x){tot++,t[tot]=t[tot-1]+x;}
}sf[8][8],sg[8];
V input(){
	n=getint(),m=getint(),K=getint();
	FOR(i,1,m)b[i].input();
	flag=1;
	FOR(i,1,n)a[i].input();
}
V init(){
	FOR(i,1,m)if(b[i].opt==2){
		if(b[i].type==1024)debuff=0;
		else if(~b[i].type)debuff|=b[i].type;
		else buff|=b[i].pos;
	}
	FOR(i,0,7)FOR(j,1,m)
		if(b[j].spy)FOR(k,0,7)sf[i][k][0]+=b[j].val(i,k);
		else sg[i][0]+=b[j].val(buff,i);
	FOR(i,0,7)FOR(j,1,n)
		if(a[j].spy)g[i].ins((node){a[j].val(buff,i),a[j].w});
		else FOR(k,0,7)f[i][k].ins((node){a[j].val(i,k),a[j].w});
	FOR(i,0,7)FOR(j,0,7)f[i][j].init();
	FOR(i,0,7)g[i].init(),g[i].rev();
}
V cmin(int&x,int y){if(y-x>>31)x=y;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
I count(int x){return !x?0:(x&1)+count(x>>1);}
V upd(int*t,int x){ROF(i,7,0)if(!(i&x))cmin(t[i|x],t[i]+1);}
I check(int x){
	FOR(i,0,7)FOR(j,0,7)sf[i][j].tot=0;
	FOR(i,0,7)sg[i].tot=0;
	FOR(i,0,7)FOR(k,0,7)FOR(j,1,f[i][k].tot)
		if(f[i][k][j].w<=x)sf[i][k].ins(f[i][k][j].v);
	FOR(i,0,7)FOR(j,1,g[i].tot)if(g[i][j].w<=x)sg[i].ins(g[i][j].v);
	memset(cf,127,sizeof cf),memset(cg,127,sizeof cg),cg[debuff]=0;
	if(debuff)FOR(i,1,n)if(a[i].w<=x&&a[i].opt==2&&a[i].type==1024)cg[0]=1;
	int cntf=0;
	FOR(i,1,n)if(a[i].w<=x&&a[i].opt==2){
		if(!~a[i].type)cntf++;
		else if(a[i].type!=1024)upd(cg,a[i].type);
	}
	FOR(i,0,7)if(count(i)<=cntf)cf[i]=count(i);
	FOR(k,0,7)if(cg[k]<=3){
		FOR(i,0,n+K)dp[i]=0;
		FOR(i,0,7)if(cf[i]<=3)ROF(j,min(sf[i][k].tot,n+K-cf[i]-cg[k]),0)
			cmax(dp[j+cf[i]+cg[k]],sf[i][k][j]);
		FOR(i,1,n+K)cmax(dp[i],dp[i-1]);
		FOR(i,0,sg[k].tot)if(dp[K+i]>=sg[k][i])return true;
	}
	return false;
}
V work(){
	int l=0,r=1e9,mid;
	if(!check(r))return void(cout<<"SingleDog");
	while(mid=l+r>>1,l^r)
		if(check(mid))r=mid;
		else l=mid+1;
	cout<<mid;
}
int main(){
	freopen("ggo.in","r",stdin);
	freopen("ggo.out","w",stdout);
	input();
	init();
	work();
	return 0;
}
