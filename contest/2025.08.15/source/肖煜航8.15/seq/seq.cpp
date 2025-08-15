#include<cstdio>
#include<algorithm>
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=1e6+5;
const int mod=998244353;
int n,m,a[N],b[N];
int f[N],s[N];
int c[100005];
int d[N],op[N];
int q[400005];
void change(int l,int r,int id,int to,int v){
	if(l==r){
		q[id]=v;
		return;
	}
	int mid=l+r>>1;
	if(to<=mid) change(l,mid,id<<1,to,v);
	else change(mid+1,r,id<<1|1,to,v);
	q[id]=(q[id<<1]+q[id<<1|1])%mod;
}
int query(int L,int R,int l,int r,int id){
	if(L>R) return 0;
	if(L<=l&&r<=R) return q[id];
	int mid=l+r>>1;
	int sum=0;
	if(L<=mid) sum=(sum+query(L,R,l,mid,id<<1))%mod;
	if(R>mid) sum=(sum+query(L,R,mid+1,r,id<<1|1))%mod;
	return sum;
}
void build(int l,int r,int id){
	q[id]=0;
	if(l==r) return;
	#define mid ((l+r>>1))
	build(l,mid,id<<1);
	build(mid+1,r,id<<1|1);
	#undef mid
}
int main(){
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	m=read();
	for(int i=1;i<=m;i++) b[i]=read(); 
	for(int i=1;i<=100000;i++) c[i]=n+1;
	int sum=0;
	for(int i=n;i;i--){ 
		f[i]=sum+1;
		f[i]%=mod;
		sum=((sum-s[a[i]])%mod+mod)%mod;
		s[a[i]]=f[i];
		sum=(sum+f[i])%mod;
	} 
	int now=0;
	for(int i=1;i<=n;i++){
		if(b[now+1]==a[i]){
			now++;
			d[i]=now;
			op[now]=i;
			if(now==m) break;
		}
	}
	int ans=0;
	for(int i=n;i;i--){
		if(d[i]&&d[i]<m){
			int val=query(1,b[d[i]+1]-1,1,100000,1);
			val++;
			val%=mod;
			ans=(ans+val)%mod;
		}
		change(1,100000,1,a[i],f[i]);
	}
	ans=(ans+query(1,b[1]-1,1,100000,1))%mod;
	printf("%d",(ans+1)%mod);
	return 0;
}
