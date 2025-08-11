#include<cstdio>
#include<algorithm>
#include<cmath>
#define ll long long
#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
using namespace std;
char buf[1<<21],*p1=buf,*p2=buf;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
const int mod=1e9+7;
const int N=1e6+5;
bool ko;
struct node{
	ll sum,mi,tag;
}q[N<<2];
int n,k,a[N];
int st[N],top,s[N];
ll f[N];
void build(int l,int r,int id){
	q[id]={0,0,0};
	if(l==r) return;
	int mid=l+r>>1;
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
}
inline void pd(int id){
	if(!q[id].tag) return;
	q[id<<1].tag=q[id].tag;
	q[id<<1|1].tag=q[id].tag;
	q[id<<1].sum=q[id<<1].mi+q[id].tag;
	q[id<<1|1].sum=q[id<<1|1].mi+q[id].tag;
	q[id].tag=0;
}
ll get(int L,int R,int l,int r,int id){
	if(L<=l&&r<=R) return q[id].sum;
	pd(id);
	int mid=l+r>>1;
	ll ans=1e18;
	if(L<=mid) ans=min(ans,get(L,R,l,mid,id<<1));
	if(R>mid) ans=min(ans,get(L,R,mid+1,r,id<<1|1));
	return ans;
}
void change(int l,int r,int id,int to,ll v){
	if(l==r){
		q[id]={v,v,0};
		return;
	}
	pd(id);
	int mid=l+r>>1;
	if(to<=mid) change(l,mid,id<<1,to,v);
	else change(mid+1,r,id<<1|1,to,v);
	q[id].mi=min(q[id<<1].mi,q[id<<1|1].mi);
	q[id].sum=min(q[id<<1].sum,q[id<<1|1].sum);
} 
void add(int L,int R,int l,int r,int id,ll v){
	if(L<=l&&r<=R){
		q[id].sum=q[id].mi+v;
		q[id].tag=v;
		return;
	}
	pd(id);
	int mid=l+r>>1;
	if(L<=mid) add(L,R,l,mid,id<<1,v);
	if(R>mid) add(L,R,mid+1,r,id<<1|1,v);
	q[id].mi=min(q[id<<1].mi,q[id<<1|1].mi);
	q[id].sum=min(q[id<<1].sum,q[id<<1|1].sum);
}
bool ed;
int main(){
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	n=Qread(),k=Qread();
	for(register int i=1;i<=n;i++) a[i]=Qread();
	top++;
	st[1]=0;
	a[0]=1e9;
	for(register int i=1;i<=n;i++){
		while(top&&a[i]>=a[st[top]]) top--;
		s[i]=st[top];
		st[++top]=i;
	}
	build(0,n-1,1);
	for(register int i=1;i<=n;i++){
		add(s[i],i-1,0,n-1,1,a[i]);
		f[i]=get(max(0,i-k),i-1,0,n-1,1);
		change(0,n-1,1,i,f[i]);
	}
	int fac=1;
	int ans=0;
	for(register int i=1;i<=n;i++){
		f[n-i+1]%=mod;
		ans=(ans+1ll*f[n-i+1]*fac%mod)%mod;
		fac=1ll*fac*23ll%mod;
	}
	printf("%d",ans);
	return 0;
} 
