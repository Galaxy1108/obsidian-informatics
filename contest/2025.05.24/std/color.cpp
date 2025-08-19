#include <bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();int z=0,f=1;
	while((c>'9'||c<'0')&&c!='-') c=getchar();
	if(c=='-') c=getchar(),f=-1;
	while(c>='0'&&c<='9') z=z*10+c-'0',c=getchar();
	return z*f; 
}
const int inf=1e9;
void gmx(int &x,int y){if(x<y) x=y;}
void gmn(int &x,int y){if(x>y) x=y;}
const int N=1e5+5;
long long ans;
int n,c[N],v[N],fa[N],tp[N],Siz[N],son[N],cnt,id[N],ln[N],rn[N];
vector <int> e[N];
void add(int x,int y){e[x].push_back(y);e[y].push_back(x);}
void dfs1(int x){
	Siz[x]=1;
	for(auto y:e[x])
		if(y!=fa[x]) fa[y]=x,dfs1(y),Siz[x]+=Siz[y],son[x]=(Siz[y]>Siz[son[x]]?y:son[x]);
}
int tot,ch[N*48][2],siz[N*48];
int rt[N];//全局每种颜色的线段树的根 
#define lc ch[o][0]
#define rc ch[o][1]
int sum[N*48][20];
void change(int &o,int l,int r,int d,int val,int pos){
	if(!o) o=++tot;
	siz[o]+=d;
	for(int i=0;i<20;i++)
		if(val&(1<<i)) sum[o][i]+=d;
	if(l==r) return;
	int mid=l+r>>1;
	if(pos<=mid) change(lc,l,mid,d,val,pos);
	else change(rc,mid+1,r,d,val,pos);
}
long long ask(int o,int l,int r,int val,int L,int R){
	if(!o) return 0;
	if(l>R||r<L) return 0;
	if(L<=l&&r<=R){
		long long ret=0;
		for(int i=0;i<20;i++)
		if(val&(1<<i)) ret+=(siz[o]-sum[o][i])*(1ll<<i);
		else ret+=sum[o][i]*(1ll<<i);
		return ret;
	}
	int mid=l+r>>1;
	return ask(lc,l,mid,val,L,R)+ask(rc,mid+1,r,val,L,R);
}
long long pa(int x,int C,int V){
	if(!x) return 0;
	return ask(rt[C],1,n,V,id[tp[x]],id[x])+pa(fa[tp[x]],C,V);
}
void dfs2(int x,int topf){
	id[x]=++cnt;tp[x]=topf;
	ln[x]=cnt;
	ans+=ask(rt[c[x]],1,n,v[x],1,n)-pa(x,c[x],v[x]);
	change(rt[c[x]],1,n,1,v[x],id[x]);
	if(!son[x]) return;
	dfs2(son[x],topf);
	for(auto y:e[x])
		if(y!=fa[x]&&y!=son[x]) dfs2(y,y);
	rn[x]=cnt;
}
int main (){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++) v[i]=read();
	for(int i=1;i<n;i++) add(read(),read());
	dfs1(1);
	dfs2(1,1);
	cout<<ans<<'\n';
	int Q=read();
	for(int i=1,opt,x,V;i<=Q;i++){
		opt=read();x=read();V=read();
		if(opt==1){
			ans-=ask(rt[c[x]],1,n,v[x],1,n)-pa(x,c[x],v[x])-ask(rt[c[x]],1,n,v[x],ln[x],rn[x]);
			change(rt[c[x]],1,n,-1,v[x],id[x]);
			v[x]=V;
			ans+=ask(rt[c[x]],1,n,v[x],1,n)-pa(x,c[x],v[x])-ask(rt[c[x]],1,n,v[x],ln[x],rn[x]);
			change(rt[c[x]],1,n,1,v[x],id[x]);
		}
		else {
			ans-=ask(rt[c[x]],1,n,v[x],1,n)-pa(x,c[x],v[x])-ask(rt[c[x]],1,n,v[x],ln[x],rn[x]);
			change(rt[c[x]],1,n,-1,v[x],id[x]);
			c[x]=V;
			ans+=ask(rt[c[x]],1,n,v[x],1,n)-pa(x,c[x],v[x])-ask(rt[c[x]],1,n,v[x],ln[x],rn[x]);
			change(rt[c[x]],1,n,1,v[x],id[x]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
*/
