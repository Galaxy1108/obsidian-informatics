#include<bits/stdc++.h>
#define int long long
#define l(p) t[p].ls
#define r(p) t[p].rs
#define tag(p) t[p].tag
#define mx(p) t[p].mx
using namespace std;
const int N=2e5+5,mx=1e9;
bool ST;
typedef long long ll;
struct Node{
	int ls,rs;
	ll tag,mx;
}t[N<<6];
int tot;
void pushup(int p){
	mx(p)=max(mx(l(p)),mx(r(p)));
}
void upd(int p,ll v){
	tag(p)+=v,mx(p)+=v;
}
void pushdown(int p){
	if(tag(p)){
		if(l(p))upd(l(p),tag(p));
		if(r(p))upd(r(p),tag(p));
		tag(p)=0;
	}
}
int merge(int x,int y,int l,int r,ll&mxx,ll&mxy){//取后缀max 
	if(!x&&!y)return 0;
	if(!x){
		mxy=max(mxy,mx(y));
		upd(y,mxx);
		return y;
	}
	if(!y){
		mxx=max(mxx,mx(x));
		upd(x,mxy);
		return x;
	}
	if(l==r){
		mxy=max(mxy,mx(y));
		mxx=max(mxx,mx(x));
		mx(x)=mxx+mxy;
		return x;
	}int mid=l+r>>1;pushdown(x),pushdown(y);
	r(x)=merge(r(x),r(y),mid+1,r,mxx,mxy);
	l(x)=merge(l(x),l(y),l,mid,mxx,mxy);
	pushup(x);return x;
}
ll query(int p,int l,int r,int l1,int r1){
	if(l1<=l&&r<=r1)return mx(p);
	int mid=l+r>>1;pushdown(p);ll ans=0;
	if(l1<=mid)ans=max(ans,query(l(p),l,mid,l1,r1));
	if(r1>mid)ans=max(ans,query(r(p),mid+1,r,l1,r1));
	return ans;
}
void change(int&p,int l,int r,int k,int v){
	if(!p)p=++tot;
	if(l==r){
		mx(p)=v;
		return;
	}int mid=l+r>>1;pushdown(p);
	if(k<=mid)change(l(p),l,mid,k,v);
	else change(r(p),mid+1,r,k,v);
	pushup(p);
}
vector<int>G[N];
int deg[N],n;
queue<int>q;
int fa[N],h[N],c[N];
ll sum;
bool vis[N];
void work(){
	for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
	while(q.size()){
		int x=q.front();q.pop();
		deg[fa[x]]--;
		if(!deg[fa[x]])q.push(fa[x]);
	}
}
void find(int x,vector<int>&tmp){
	if(vis[x])return;
	vis[x]=1;tmp.push_back(x);
	for(int i:G[x])if(deg[i])find(i,tmp);
}
int rt[N];
void dfs(int x){
	change(rt[x],1,mx,1,0);
	for(int i:G[x])if(!deg[i]){
		dfs(i);
		ll mxx=0,mxy=0;
		rt[x]=merge(rt[x],rt[i],1,mx,mxx,mxy);
	}ll val=query(rt[x],1,mx,h[x],mx);
	if(!deg[x])change(rt[x],1,mx,h[x],val+c[x]);
}
bool cmp(int x,int y){
	return h[x]<h[y];
}
bool ED;
signed main(){
//	cerr<<(&ED-&ST)/1024.0/1024;
	freopen("reporter.in","r",stdin);
	freopen("reporter.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld%lld",fa+i,h+i,c+i),G[fa[i]].push_back(i),sum+=c[i],deg[fa[i]]++;
	work();
	for(int i=1;i<=n;i++)if(deg[i])dfs(i);
	for(int i=1;i<=n;i++)if(deg[i]&&!vis[i]){
		vector<int>cir;find(i,cir);
		int rt=0;
		for(int j:cir){
			ll mxx=0,mxy=0;
			rt=merge(rt,::rt[j],1,mx,mxx,mxy);
		}
		sort(cir.begin(),cir.end(),cmp);
		ll ans=mx(rt);
		for(vector<int>::iterator j=cir.begin(),k;j!=cir.end();j=k){
			k=j;ll now=0;
			while(k!=cir.end()&&h[*j]==h[*k])now+=c[*k],k++;
			ans=max(ans,now+query(rt,1,mx,h[*j],mx)); 
		}sum-=ans;
	}
	printf("%lld\n",sum);
	return 0;
}
/*
合并时取后缀max
先让sum=x
求h[i]总和的最大值 
*/
