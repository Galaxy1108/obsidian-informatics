#include<cstdio>
#include<algorithm>
#include<set>
#define ll long long
using namespace std;
const int N=1e6+5;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
struct node{
	int cnt[N<<2];
	ll sum[N<<2];
	void add(int l,int r,int id,int to,int v){
		cnt[id]+=v;
		if(l==r){
			if(v==1) sum[id]+=l;
			else sum[id]-=l;
			return;
		}
		int mid=l+r>>1;
		if(to<=mid) add(l,mid,id<<1,to,v);
		else add(mid+1,r,id<<1|1,to,v);
		sum[id]=sum[id<<1]+sum[id<<1|1];
	}
	pair<ll,ll> query(int l,int r,int id,ll k){
		if(sum[id]<=k) return {0,k-sum[id]};
		if(l==r){
			ll ct=k/l;
			return {2ll*(cnt[id]-ct),k-1ll*ct*l};
		}
		int mid=l+r>>1;
		if(sum[id<<1]<=k){
			k-=sum[id<<1];
			return query(mid+1,r,id<<1|1,k);			
		}
		else{
			pair<ll,ll> op=query(l,mid,id<<1,k);
			op.first+=2ll*cnt[id<<1|1];
			return op;
		}
	}
}q1,q2;
int n,m,Q,a[N];
int c1,c2,sum;
set<int> b;
void add(int l,int r){
	if((a[l]&1)&&(a[r]&1)){
		if(r-l>1) q1.add(1,n,1,r-l-1,1);
	}
	else if(!(a[l]&1)&&!(a[r]&1)){
		if(r-l>1) q2.add(1,n,1,r-l-1,1);
	}
	else{
		sum++;
	}
}
void delet(int l,int r){
	if((a[l]&1)&&(a[r]&1)){
		if(r-l>1) q1.add(1,n,1,r-l-1,-1);
	}
	else if(!(a[l]&1)&&!(a[r]&1)){
		if(r-l>1) q2.add(1,n,1,r-l-1,-1);
	}
	else{
		sum--;
	}
}
void inst(int x){
	b.insert(x);
	auto u=b.lower_bound(x);
	int l=0,r=0;
	if(u!=b.begin()){
		u--;
		l=*u;
		u++;
	}
	u++;
	if(u!=b.end()){
		r=*u;
	}
	if(l&&r){
		delet(l,r);
	}
	if(l){
		add(l,x);
	}
	if(r){
		add(x,r);
	}
}
void del(int x){
	auto u=b.lower_bound(x);
	int l=0,r=0;
	if(u!=b.begin()){
		u--;
		l=*u;
		u++;
	}
	u++;
	if(u!=b.end()){
		r=*u;
	}
	if(l&&r){
		add(l,r);
	}
	if(l){
		delet(l,x);
	}
	if(r){
		delet(x,r);
	}
	a[x]=-1;
	b.erase(x);
}
int c[5],d[5],t1,t2;
ll solve(){
	pair<ll,ll> op1=q1.query(1,n,1,c1),op2=q2.query(1,n,1,c2);
	ll ans=op1.first+op2.first+sum;
	int n1=op1.second,n2=op2.second;
	auto u=b.begin();
	int p=*u;
	t1=t2=0;
	if(a[p]&1){
		c[++t1]=p-1;
	}
	else{
		d[++t2]=p-1;
	}
	u=b.end();
	u--;
	p=*u;
	if(a[p]&1){
		c[++t1]=n-p;
	}
	else{
		d[++t2]=n-p;
	}
	if(t1>1&&c[1]>c[2]) swap(c[1],c[2]);
	if(t2>1&&d[1]>d[2]) swap(d[1],d[2]);
	for(int i=1;i<=t1;i++){
		if(n1>=c[i]){
			n1-=c[i];
		}
		else ans++;
	}
	for(int i=1;i<=t2;i++){
		if(n2>=d[i]){
			n2-=d[i];
		}
		else ans++;
	}
	return ans;
}
void write(ll x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	n=read(),m=read(),Q=read();
	for(int i=1;i<=n;i++){
		int x=read();
		if(x&1) c1++;
		else c2++;
		a[i]=-1;
	} 
	while(m--){
		int x=read(),y=read();
		a[x]=y;
		if(y&1) c1--;
		else c2--;
		inst(x);
	}
	while(Q--){
		int opt=read(),x=read(),y;
		if(opt==1){
			y=a[x];
			if(y&1) c1++;
			else c2++;
			del(x);
		}
		else{
			y=read();
			a[x]=y;
			if(y&1) c1--;
			else c2--;
			inst(x);
		}
		write(solve());
		putchar('\n');
	}
	return 0;
}
