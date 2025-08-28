#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
inline int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=5e5+5;
struct query{
	int l,r,c,id;
}b[N];
int n,m,a[N];
int ans[N];
inline bool cmp(query x,query y){
	return x.r<y.r;
}
int rt;
struct node{
	int ls,rs,p,val,pos,mi,sz,tag;
}q[N];
int idx;
inline int New(int x,int y){
	idx++;
	q[idx]={0,0,rand(),x,y,y,1,0};
	return idx;
}
inline void pu(int id){
	q[id].sz=q[q[id].ls].sz+q[q[id].rs].sz+1;
	q[id].mi=min(q[id].pos,min(q[q[id].ls].mi,q[q[id].rs].mi));
}
inline void app(int id,int p){
	q[id].tag+=p;
	q[id].val+=p;
}
inline void pd(int id){
	if(q[id].tag==0) return;
	if(q[id].ls) app(q[id].ls,q[id].tag);
	if(q[id].rs) app(q[id].rs,q[id].tag);
	q[id].tag=0;
}
inline void split(int id,int k,int &x,int &y){
	if(!id){
		x=y=0;
		return;
	}
	pd(id);
	if(q[id].val<=k){
		x=id;
		split(q[id].rs,k,q[id].rs,y);
	}
	else{
		y=id;
		split(q[id].ls,k,x,q[id].ls);
	}
	pu(id);
} 
inline int merge(int x,int y){
	if(!x||!y) return x^y;
	if(q[x].p<q[y].p){
		pd(x);
		q[x].rs=merge(q[x].rs,y);
		pu(x);
		return x;
	}
	else{
		pd(y);
		q[y].ls=merge(x,q[y].ls);
		pu(y);
		return y;
	}
}
inline void insert(int v1,int v2){
	int x,y,z;
	split(rt,v1,y,z);
	split(y,v1-1,x,y);
	y=merge(y,New(v1,v2));
	rt=merge(x,merge(y,z));
} 
inline void solve(int v){
	int x,y,z;
	split(rt,v,y,z);
	split(y,v-1,x,y);
	if(x) app(x,1);
	if(z) app(z,-1);
	rt=merge(x,merge(y,z));
}
inline int get_pos(int id,int v){
	pd(id); 
	if(q[id].pos==v) return id;
	if(q[q[id].ls].mi==v) return get_pos(q[id].ls,v);
	else return get_pos(q[id].rs,v);
}
inline int delet(int id,int v){
	pd(id);
	if(q[id].pos==v) return merge(q[id].ls,q[id].rs);
	if(q[q[id].ls].mi==v){
		q[id].ls=delet(q[id].ls,v);
	} 
	else{
		q[id].rs=delet(q[id].rs,v);
	}
	pu(id);
	return id;
}
inline void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
vector<pair<int,int> > c[N];
int main(){
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	q[0].mi=1e9;
	srand(time(NULL));
	n=read(),m=read();
	for(register int i=1;i<=n;i++) a[i]=read();
	for(register int i=1;i<=m;i++){
		b[i].l=read(),b[i].r=read(),b[i].c=read();
		b[i].id=i;	
	}
	sort(b+1,b+m+1,cmp);
	for(register int i=1;i<=m;i++){
		c[b[i].l].push_back(make_pair(b[i].c,i));
	}
	int now=0;
	for(register int i=1;i<=n;i++){
		for(register int j=0;j<c[i].size();j++){
			pair<int,int> op=c[i][j];
			insert(op.first,op.second);
		}
		solve(a[i]);
		while(now<m&&b[now+1].r==i){
			now++;
			int v=q[rt].mi;
			int p=get_pos(rt,v);			
			ans[b[now].id]=q[p].val;
			rt=delet(rt,v);
		}
	}
	for(register int i=1;i<=m;i++){
		write(ans[i]);
		putchar('\n');
	}
	return 0;
}
