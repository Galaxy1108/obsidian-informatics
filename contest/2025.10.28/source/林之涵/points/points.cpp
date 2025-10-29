#include<bits/stdc++.h>
using namespace std;
using ll =long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,m;
ll a[maxn],l[maxn],r[maxn];
int ord[maxn],m2=0;
ll tmp[maxn];
const ll inf=9e18;
int main(){
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++){
		l[i]=read();
		r[i]=read();
	}
	sort(a+1,a+n+1);
	n=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=m;i++) ord[i]=i;
	sort(ord+1,ord+m+1,[](int a,int b){
		if(r[a]!=r[b]) return r[a]<r[b];
		return l[a]>l[b];
	});
	for(int i=1;i<=m;i++)
		if(i==1||l[ord[i]]>l[ord[m2]]) ord[++m2]=ord[i];
	m=m2;
	for(int i=1;i<=m;i++) tmp[i]=l[ord[i]];
	for(int i=1;i<=m;i++) l[i]=tmp[i];
	for(int i=1;i<=m;i++) tmp[i]=r[ord[i]];
	for(int i=1;i<=m;i++) r[i]=tmp[i];
	ll mn1=max(a[1]-r[1],0ll)-a[1],mn2=max(a[1]-r[1],0ll)*2-a[1];
	int c=0;
	while(c<m&&r[c+1]<a[1]) c++;
	for(int i=2;i<=n;i++){
		ll f11=inf,f12=inf,f21=inf,f22=inf;
		while(c<m&&r[c+1]<a[i]){
			if(l[c+1]>a[i-1]){
				f11=min(f11,a[i]-r[c+1]+(c?max(l[c]-a[i-1],0ll):0));
				f12=min(f12,(a[i]-r[c+1])*2ll+(c?max(l[c]-a[i-1],0ll):0));
				f21=min(f21,a[i]-r[c+1]+(c?max(l[c]-a[i-1],0ll)*2:0));
				f22=min(f22,(a[i]-r[c+1])*2ll+(c?max(l[c]-a[i-1],0ll)*2:0));
			}
			c++;
		}
		f11=min(f11,(c?max(l[c]-a[i-1],0ll):0))+a[i-1]+mn2;
		f12=min(f12,(c?max(l[c]-a[i-1],0ll):0))+a[i-1]+mn2;
		f21=min(f21,(c?max(l[c]-a[i-1],0ll)*2:0))+a[i-1]+mn1;
		f22=min(f22,(c?max(l[c]-a[i-1],0ll)*2:0))+a[i-1]+mn1;
		mn1=min(mn1,min(f11,f21)-a[i]);
		mn2=min(mn2,min(f12,f22)-a[i]);
	}
	printf("%lld\n",min(max(l[m]-a[n],0ll)+a[n]+mn2,max(l[m]-a[n],0ll)*2+a[n]+mn1));
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}