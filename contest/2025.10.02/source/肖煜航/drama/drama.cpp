#include<cstdio>
#include<algorithm>
#define ll long long
#define i8 __int128
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=2e6+5;
int mx[N<<2];
int a[N];
void build(int l,int r,int id){
	if(l==r){
		mx[id]=a[l];
		return;
	}
	int mid=l+r>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	mx[id]=max(mx[id<<1],mx[id<<1|1]);
}
int n;
int l[N],r[N];
int s[N],top;
void write(i8 x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int query(int L,int R,int l,int r,int id){
	if(L<=l&&r<=R) return mx[id];
	int mid=l+r>>1;
	int ans=-1;
	if(L<=mid) ans=max(ans,query(L,R,l,mid,id<<1));
	if(R>mid) ans=max(ans,query(L,R,mid+1,r,id<<1|1));
	return ans;
}
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	build(1,n,1);
	a[0]=-1e9;
	top=1;
	s[1]=0;
	for(int i=1;i<=n;i++){
		while(a[s[top]]>=a[i]) top--;
		l[i]=s[top]+1;
		s[++top]=i;
	}
	top=1;
	s[1]=n+1;
	a[n+1]=-1e9;
	for(int i=n;i;i--){
		while(a[s[top]]>=a[i]) top--;
		r[i]=s[top]-1;
		s[++top]=i;
	}
	i8 ans=0;
	for(int i=1;i<=n;i++){
		i8 nw=a[i];
		nw=nw*query(l[i],r[i],1,n,1);
		nw=nw*(r[i]-l[i]+1);
		ans=max(ans,nw);
	}
	write(ans);
	return 0;
} 
