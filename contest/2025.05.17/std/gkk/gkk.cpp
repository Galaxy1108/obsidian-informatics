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
const int N=1e6+1;
ll ans;
int n,m,tot,fa[N];
V nxt(int&x){x=(x+1)%n;}
struct node{
	int x,y,w;
	V upd(){nxt(x),nxt(y),w+=2;}
	I operator<(const node&u)const{return w>u.w;}
};
priority_queue<node>q;
V input(){
	n=getint(),m=getint();
	for(int x,y,w;m--;q.push((node){x,y,w})){
		x=getint(),y=getint(),w=getint();
		q.push((node){x,y,w}),nxt(x),w++;
	}
}
I find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
V init(){FOR(i,0,n-1)fa[i]=i;}
I merge(int x,int y,int w){
	if((x=find(x))==(y=find(y)))return 0;
	return ans+=w,fa[x]=y,1;
}
V work(){
	for(node v;!q.empty();){
		v=q.top(),q.pop();
		if(merge(v.x,v.y,v.w))v.upd(),q.push(v);
	}
	cout<<ans;
}
int main(){
	freopen("gkk.in","r",stdin);
	freopen("gkk.out","w",stdout);
	input();
	init();
	work();
	return 0;
}
