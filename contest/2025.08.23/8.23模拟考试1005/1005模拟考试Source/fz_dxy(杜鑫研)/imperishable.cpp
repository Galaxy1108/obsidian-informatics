#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
#define re int
inline int read(){
	int x=0,ff=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')ff=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*ff;
}
const int mn=998244353;
int t,n,a[200005],p[200005];
inline int md(int x){return x>=mn?x-mn:x;}
long long s[200005];
#define lz (i<<1)
#define rz (i<<1|1)
#define mid ((l+r)>>1)
long long f[800005];
int mx[800005];
inline void push_up(int i){f[i]=f[lz]+f[rz];mx[i]=max(mx[lz],mx[rz]);}
void build(int i,int l,int r){
	if(l==r){mx[i]=f[i]=a[l];return;}
	build(lz,l,mid);build(rz,mid+1,r);
	push_up(i);
}
void update(int i,int l,int r,int x,int y){
	if(l==r){f[i]=mx[i]=y;return;}
	if(mid>=x)update(lz,l,mid,x,y);
	else update(rz,mid+1,r,x,y);
	push_up(i);
}
int awa,opt;
void query(int i,int l,int r,int y,long long ls,int rmx){
	if(l==r){opt=l;return;}
	if(r<=y){
		if(f[lz]+ls<max(mx[rz]-awa,rmx))query(rz,mid+1,r,y,ls+f[lz],rmx);
		else query(lz,l,mid,y,ls,max(mx[rz]-awa,rmx));
		return;
	}
	if(mid<y){
		if(f[lz]+ls<max(mx[rz]-awa,rmx)){
			query(rz,mid+1,r,y,ls+f[lz],rmx);return;
		}
	}
	query(lz,l,mid,y,ls,max(rmx,mx[rz]-awa));
}
int main(){
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	t=read();n=read();p[0]=1;
	for(re i=1;i<=n;i++)a[i]=read(),p[i]=md(p[i-1]<<1),s[i]=s[i-1]+a[i];
	int la=0,ss=0,qwq=0;
	for(re i=n;i;i--){
		la=max(la,a[i]-qwq);
		if(s[i-1]<la){
			ss=md(ss+p[i]);la-=a[i];qwq+=a[i];
		}
	}
	build(1,1,n);
	cout<<ss<<endl;
	int q=read(),now,x,y;
	for(re i=1;i<=q;i++){
		now=n;x=read();y=read();a[x]=y;
		update(1,1,n,x,y);awa=0;ss=0;
		while(23333){
			opt=0;query(1,1,n,now,0,0);now=opt;
			if(now==1){
				if(mx[1]>awa)ss=md(ss+p[1]);
				break;
			}
			ss=md(ss+p[now]);awa+=a[now];now--;
		}
		printf("%d\n",ss);
	}
	return 0;
}