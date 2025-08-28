#include<cstdio>
#include<set>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
} 
const int N=2e6+5;
struct node{
	int sum;
	bool can;
}q[N<<2];
void change(int l,int r,int id,int to,int v){
	if(l==r){
		q[id].sum+=v;
		if(q[id].sum>0) q[id].can=1;
		else q[id].can=0;
		return;
	}
	int mid=l+r>>1;
	if(to<=mid) change(l,mid,id<<1,to,v);
	else change(mid+1,r,id<<1|1,to,v);
	q[id].can=q[id<<1].can&q[id<<1|1].can;
}
int query(int l,int r,int id){
	if(l==r) return l;
	int mid=l+r>>1;
	if(q[id<<1].can) return query(mid+1,r,id<<1|1);
	else query(l,mid,id<<1);
}
struct edge{
	int to,nxt;
}e[N];
int head[N],tot;
void add(int u,int v){
	e[++tot]={v,head[u]};
	head[u]=tot;
}
int T,ans;
int n;
int sg[N];
void dfs1(int u,int nw){
	int al=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		al^=sg[v];
	}
	change(0,n,1,nw^al,1);
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		int op=al;
		op^=sg[v];
		dfs1(v,nw^op);
	}
}
void dfs3(int u,int nw){
	int al=0;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		al^=sg[v];
	}
	change(0,n,1,nw^al,-1);
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		int op=al;
		op^=sg[v];
		dfs3(v,nw^op);
	}
}
void dfs(int u){
	if(head[u]==0){
		sg[u]=1;
		return;
	}
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		dfs(v);
	}
	dfs1(u,0);
	sg[u]=query(0,n,1);
	dfs3(u,0);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		tot=0;
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=2;i<=n;i++){
			int x=read();
			add(x,i);
		}
		dfs(1);
		ans^=sg[1];
	}
	printf("%d",ans);
	return 0;
}
