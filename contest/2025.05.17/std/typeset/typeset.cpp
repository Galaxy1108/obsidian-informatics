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
const int N=1e5+1;
int T,n,m,a[N];
V input(){
	n=getint(),m=getint();
	FOR(i,1,n)a[i]=getint();
}
I calc(int x){return x&1?0:1+calc(x>>1);}
V init(){
	FOR(i,1,n)a[i]=calc(a[i]);
	sort(a+1,a+1+n);
}
V work(){
	int l=1,r=n,dl=1,dr=0;
	while(l<r){
		if(a[l]+a[r]<m)return void(cout<<"No\n");
		l+=dl,r-=dr,dl^=1,dr^=1;
	}
	cout<<"Yes\n";
}
int main(){
	freopen("typeset.in","r",stdin);
	freopen("typeset.out","w",stdout);
	for(T=getint();T--;){
		input();
		init();
		work();
	}
	return 0;
}
