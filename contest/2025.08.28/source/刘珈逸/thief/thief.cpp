#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
mt19937 rd(time(0));
int tag[N],rnd[N],siz[N],val[N];
int ls[N],rs[N],fa[N];
int from[N];
void pushup(int p){
	siz[p]=siz[ls[p]]+siz[rs[p]]+1;
	if(ls[p])fa[ls[p]]=p;
	if(rs[p])fa[rs[p]]=p; 
}
void upd(int p,int v){
	if(!p)return;
	tag[p]+=v;
	val[p]+=v;
}
void pushdown(int p){
	if(!tag[p])return;
	if(ls[p])upd(ls[p],tag[p]);
	if(rs[p])upd(rs[p],tag[p]);
	tag[p]=0; 
}
void pushall(int p){
	if(!p)return;
	pushall(fa[p]);
	pushdown(p);
}
int tot;
int New(int v){
	tot++;
	rnd[tot]=rd();
	val[tot]=v;
	pushup(tot);
	return tot;
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	pushdown(x),pushdown(y); 
	if(rnd[x]<rnd[y]){
		rs[x]=merge(rs[x],y);
		pushup(x);
		return x;
	}ls[y]=merge(x,ls[y]);
	pushup(y);
	return y;
}
void split(int x,int v,int&k1,int&k2){//<=v k1
	if(!x){
		k1=k2=0;
		return;
	}pushdown(x);
	if(val[x]<=v){
		k1=x;
		split(rs[k1],v,rs[k1],k2);
		pushup(k1);
	}else{
		k2=x;
		split(ls[k2],v,k1,ls[k2]);
		pushup(k2);
	}
}
struct Query{int id,op;};
vector<Query>q[N];
int n,m,ans[N],rt,a[N];
int read(){
	int t=0;char c=getchar();
	while(c<'0'||'9'<c)c=getchar();
	while('0'<=c&&c<='9')t=c-'0'+t*10,c=getchar();
	return t;
}
int main(){
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=m;i++){
		int l,r,c;l=read(),r=read(),c=read();
		q[l].push_back({i,c});
		q[r+1].push_back({i,-1});
	}
	for(int i=1;i<=n+1;i++){
		for(auto j:q[i]){
			if(j.op==-1){
				int v=from[j.id];
				pushall(v);
				ans[j.id]=val[v];
			}else{
				from[j.id]=New(j.op);
				int k1,k2;
				split(rt,j.op,k1,k2);
				rt=merge(merge(k1,from[j.id]),k2);
			}
		}
		int k1,k2,k3;
		split(rt,a[i],k1,k3);
		split(k1,a[i]-1,k1,k2);
		upd(k1,1);upd(k3,-1);
		rt=merge(merge(k1,k2),k3);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}
/*
10 3
3 5 5 4 3 6 10 0 4 7
2 10 9
6 6 2
2 8 4
*/
