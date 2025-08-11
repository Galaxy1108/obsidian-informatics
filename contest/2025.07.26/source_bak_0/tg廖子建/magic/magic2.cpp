#include<bits/stdc++.h>
#define int long long
#define N 200000
#define Q 1000000
#define IT set<ONode>::iterator
using namespace std;
struct Node{int x,y,ans,id;};
struct TNode{int son[2],f,val,size;};
int n,q,a[N+5],tip1,tip2,tmp[N+5],k,tot=0;
Node p[Q+5];
TNode tree[N+5];
struct ODT{
	struct ONode{
		int l,r;
		mutable int root;
		ONode(int x,int y,int z){l=x,r=y,root=z;}
		void pushup(int x){tree[x].size=tree[tree[x].son[0]].size+1+tree[tree[x].son[1]].size;return;}
		bool get(int x){return x==tree[tree[x].f].son[1];}
		void rot(int x){
		    int fx=tree[x].f,ffx=tree[fx].f,gx=get(x);
		    if(ffx)tree[ffx].son[get(fx)]=x;
		    if(tree[x].son[gx^1])tree[tree[x].son[gx^1]].f=fx;
		    tree[fx].son[gx]=tree[x].son[gx^1],tree[x].son[gx^1]=fx;
		    tree[fx].f=x,tree[x].f=ffx,pushup(fx),pushup(x);
		    return;
		}
		void splay(int x){
		    for(int f=tree[x].f;f=tree[x].f,f;rot(x)){
		        if(tree[f].f)rot(get(x)==get(f)?f:x);
		    }
		    root=x;
		    return;
		}
		void build(int v){
			root=++tot;
			tree[root].f=tree[root].son[0]=tree[root].son[1]=0;
			tree[root].val=v,tree[root].size=1;
			return;
		}
		int rnk(int v){
			int x=root,f=0;
			while(x){
				f=x;
				if(v==tree[tree[x].son[0]].size+1)break;
				else if(v<tree[tree[x].son[0]].size+1)x=tree[x].son[0];
				else x=tree[x].son[1];
			}
			if(!x)return x;
			splay(x);
			return x;
		}
		int max(){
			int x=root,f=0;
			while(x)x=tree[x].son[0];
			if(f)splay(f);
			return tree[f].val;
		}
		int min(){
			int x=root,f=0;
			while(x)x=tree[x].son[1];
			if(f)splay(f);
			return tree[f].val;
		}
		bool friend const operator<(ONode const &x,ONode const &y){return x.l<y.l;}
	};
	set<ONode>Tree;
	void manger(int p){
		IT it=Tree.lower_bound(ONode(p,0,0));
		if(it!=Tree.end()&&it->l==p)return;
		ONode x=ONode(it->l,it->r,it->root);
		Tree.erase(it);
		x.rnk(p-it->l);
		if(tree[x.root].son[1])tree[tree[x.root].son[1]].f=0;
		Tree.insert(ONode(x.l,p-1,x.root));
		Tree.insert(ONode(p,x.r,tree[x.root].son[1])).first;
		tree[x.root].son[0]=0;
		return;
	}
	void assign(){
		int v=1;
		IT f,g;
		while(1){
			g=f=Tree.upper_bound(ONode(v,0,0));
			f--;
			if(g==Tree.end())break;
			ONode x=ONode(f->l,f->r,f->root),y=ONode(g->l,g->r,g->root);
			if(x.min()>y.max()){
				Tree.erase(f,++g);
				tree[x.root].son[1]=y.root;
				Tree.insert(ONode(x.l,y.r,x.root));
			}
			else v=y.l;
		}
		return;
	}
}odt;
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
bool cmp1(Node x,Node y){
	if(x.x==y.x)return x.y<y.y;
	return x.x<y.x;
}
bool cmp2(Node x,Node y){
	return x.id<y.id;
}
main(){
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		ODT::ONode x=ODT::ONode(i,i,0);
		x.build(a[i]);
		odt.Tree.insert(x);
	}
	odt.assign();
	for(int i=1;i<=q;i++)p[i].x=read(),p[i].y=read(),p[i].id=i;
	sort(p+1,p+1+q,cmp1),k=1;
	for(int i=0;i<=n&&k<=q;i++){
		while(k<=q&&p[k].x==i){
			set<ODT::ONode>::iterator x=odt.Tree.upper_bound(ODT::ONode(p[k].y,0,0));
			x--;
			ODT::ONode y=ODT::ONode(x->l,x->r,x->root);
			p[k].ans=y.rnk(p[k].x-x->l+1),k++;
		}
		for(int j=1;j<=n;j++)tmp[j]=a[j];
		tip1=1,tip2=1;
		while(tip1<=n/2&&tip2<=n/2){
			if(tmp[tip1]<tmp[n/2+tip2])a[tip1+tip2-1]=tmp[tip1],tip1++;
			else a[tip1+tip2-1]=tmp[n/2+tip2],tip2++;
		}
		while(tip1<=n/2)a[n/2+tip1]=tmp[tip1],tip1++;
		while(tip2<=n/2)a[n/2+tip2]=tmp[n/2+tip2],tip2++;
	}
	while(k<=q)p[k].ans=a[p[k].y],k++;
	sort(p+1,p+1+q,cmp2);
	for(int i=1;i<=q;i++)print(p[i].ans),putchar('\n');
	return 0;
}
