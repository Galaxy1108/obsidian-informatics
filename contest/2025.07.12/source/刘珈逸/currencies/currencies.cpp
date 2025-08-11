#include<bits/stdc++.h>
#define l(p) t[p].ls
#define r(p) t[p].rs
#define s(p) t[p].sum
#define c(p) t[p].cnt 
#define pb push_back
#define fi first
#define se second
using namespace std;
const int N=1e5+5,mx=1e9;
typedef pair<int,int>pii;
typedef long long ll;
bool ST;
struct Node{
	int ls,rs,cnt;
	ll sum;	
}t[N*30];
int rt[N],tot;
vector<int>G[N],opt[N];
void change(int&p,int q,int l,int r,int k){
	p=++tot;t[p]=t[q];s(p)+=k,c(p)++;
	if(l==r)return;
	int mid=l+r>>1;
	if(k<=mid)change(l(p),l(q),l,mid,k);
	else change(r(p),r(q),mid+1,r,k);
}
int query(int p1,int p2,int p3,int l,int r,ll sum){
	if(l==r){
		ll k=min(sum/l,(ll)c(p1)+c(p2)-2*c(p3));
		return k;
	}int mid=l+r>>1;
	if(sum<=s(l(p1))+s(l(p2))-2*s(l(p3)))return query(l(p1),l(p2),l(p3),l,mid,sum);
	sum-=s(l(p1))+s(l(p2))-2*s(l(p3));
	return c(l(p1))+c(l(p2))-2*c(l(p3))+query(r(p1),r(p2),r(p3),mid+1,r,sum);
}
int dfn[N],lg[N],cnt,d[N],dep[N];
pii st[20][N];
void dfs(int x,int f){
	dfn[x]=++cnt;d[x]=d[f]+1;st[0][cnt]={d[x],f};
	for(int v:G[x])if(v^f)dfs(v,x);
}
void dfs1(int x,int f){
	rt[x]=rt[f];dep[x]=dep[f];
	for(int k:opt[x])change(rt[x],rt[x],1,mx,k),dep[x]++;
	for(int v:G[x])if(v^f)dfs1(v,x);
}
int LCA(int x,int y){
	if(x==y)return x;
	x=dfn[x],y=dfn[y];
	if(x>y)swap(x,y);x++;
	int k=lg[y-x+1];
	return min(st[k][x],st[k][y-(1<<k)+1]).se;
}
int n,m,q;
pii edge[N];
bool ED;
int main(){
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<n;i++)scanf("%d%d",&edge[i].fi,&edge[i].se),G[edge[i].fi].pb(edge[i].se),G[edge[i].se].pb(edge[i].fi);
	dfs(1,0);
	for(int i=1;i<=19;i++)for(int j=1;j+(1<<i)-1<=n;j++)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	while(m--){
		int p,c;
		scanf("%d%d",&p,&c);
		if(d[edge[p].fi]>d[edge[p].se])opt[edge[p].fi].pb(c);
		else opt[edge[p].se].pb(c);
	}
	dfs1(1,0);
	while(q--){
		int s,t;scanf("%d%d",&s,&t);
		int lca=LCA(s,t);
		int x;ll y;scanf("%d%lld",&x,&y);
		int w1=query(rt[s],rt[t],rt[lca],1,mx,y);
		int w2=dep[s]+dep[t]-2*dep[lca];
		if(w1>=w2)printf("%d\n",x);
		else printf("%d\n",max(-1,x+w1-w2));
	}
	return 0;
}
