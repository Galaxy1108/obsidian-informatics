#include<bits/stdc++.h>
#define il inline
#define cs const
#define ri register
#define int long long
#define clock() (clock()*1000/CLOCKS_PER_SEC)
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
cs int N=2e5+5;
int n,a[N],as,s,ss,z;
il void dfs(int inx,int ans,int sum){
	as=min(as,ans);
	if(!sum) return;
	s=ans;
	if(clock()>990){
		wt(as);
		exit(0);
	}
	if(inx<n){
		s=s-abs(a[inx+1])+abs(a[inx+1]-1);
		a[inx+1]--,dfs(inx+1,s,sum-(a[inx+1]<=0)),a[inx+1]++;
	}
	s=ans;
	if(inx>0){
		s=s-abs(a[inx])+abs(a[inx]-1);
		a[inx]--,dfs(inx-1,s,sum-(a[inx+1]<=0)),a[inx]++;
	} 
}
signed main(){
	F(walk)
	n=rd();
	for(ri int i=1;i<=n;++i){
		a[i]=rd();
		ss+=a[i];
		z+=(a[i]>0);
	} 
	as=ss;
	for(ri int i=0;i<=n;++i){
		dfs(i,ss,z);
	}
	wt(as);
	return 0;
}
