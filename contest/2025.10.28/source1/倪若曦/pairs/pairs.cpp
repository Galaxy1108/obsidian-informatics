#include<bits/stdc++.h>
#define il inline
#define cs const
#define ri register
#define int long long
#define F(s) freopen(#s".in","r",stdin),freopen(#s".out","w",stdout);
using namespace std;
namespace Q{
	il int rd(){
		ri int x=0,f=1;ri char c=getchar();
		while(c<'0'||c>'9') f=(c=='-')?-1:1,c=getchar();
		while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();
		return x*f;
	}
	il void wt(int x){
		if(x<0) x=-x,putchar('-');
		if(x>=10) wt(x/10);
		return putchar(x%10+48),void();
	}
}
using namespace Q;
cs int N=205;
int n,mod,p[N],q[N],as;
bool v1[N],v2[N];
il void d2(int inx,int cnt,bool lim,int nw){
	if(cnt<=nw) return;
	if(inx>n){ 
		as++,as%=mod;
		return;
	}
	int minn=lim?p[inx]:1;
	for(ri int i=minn;i<=n;++i){
		if(!v2[i]){
			v2[i]=1,q[inx]=i;
			int c=0;
			for(ri int j=1;j<inx;++j){
				c+=(q[j]>q[inx]); 
			}
			if(nw+c<cnt) d2(inx+1,cnt,(lim&&i==minn),nw+c);
			v2[i]=0,q[inx]=0;
		}
	}
}
il void d1(int inx,int cnt){
	if(inx>n){
		d2(1,cnt,1,0);
		return;
	}
	for(ri int i=1;i<=n;++i){
		if(!v1[i]) {
			v1[i]=1,p[inx]=i;
			int c=0;
			for(ri int j=1;j<inx;++j){
				c+=(p[j]>p[inx]);
			}
			d1(inx+1,cnt+c);
			v1[i]=0,p[inx]=0;
		}
	}
}
signed main(){
	F(pairs)
	n=rd(),mod=rd();
	d1(1,0);
	wt(as);
	return 0;
}
