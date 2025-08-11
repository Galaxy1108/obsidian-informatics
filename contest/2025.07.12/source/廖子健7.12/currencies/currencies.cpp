#include<bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;
struct Cnode{int dep,f,s,h_s,top,v;Cnode(){dep=f=s=h_s=top=v=0;}};
struct Bnode{int f,s[2],v,size,sum;Bnode(){sum=f=s[0]=s[1]=v=size=0;}};
int n,m,root,tot=0,tags[N+5]={},uu,uv,opt,ux,uy,uz,vvv[N+5]={},tip[N+5][2],q;
Cnode chan[N+5];
Bnode tree[N+5];
vector<int>edge[N+5];
vector<int>val[N+5];
int newnode(int v){tree[++tot]={},tree[tot].v=tree[tot].sum=v,tree[tot].size=1;return tot;}
void clean(int x){tree[x].f=tree[x].s[0]=tree[x].s[1]=tree[x].sum=tree[x].size=0;return;}
void pushup(int x){tree[x].size=tree[tree[x].s[0]].size+1+tree[tree[x].s[1]].size,tree[x].sum=tree[tree[x].s[0]].sum+tree[x].v+tree[tree[x].s[1]].sum;return;}
bool get(int x){return x==tree[tree[x].f].s[1];}
void rot(int x){
    int fx=tree[x].f,ffx=tree[fx].f,gx=get(x);
    if(!ffx)tree[fx].s[get(fx)]=x;
    if(tree[x].s[gx^1])tree[tree[x].s[gx^1]].f=fx;
    tree[fx].s[gx]=tree[x].s[gx^1],tree[x].s[gx^1]=fx;
    tree[fx].f=x,tree[x].f=ffx,pushup(fx),pushup(x);
    return;
}
void splay(int x){
    for(int f=tree[x].f;f=tree[x].f,x;rot(x)){
    	cout<<x<<"\n";
        if(tree[f].f)rot(get(f)==get(x)?f:x);
    }
    root=x;
    return;
}
void ins(int v){
    int f=0,x=root;
    if(!x){root=newnode(v);return;}
    while(x)f=x,x=tree[x].s[v>tree[x].v];
    x=newnode(v),tree[x].f=f,tree[f].s[v>tree[f].v]=x,splay(x);
    return;
}
int kth(int v){
    int x=root,sum=0;
    while(x){
        if(tree[x].v+tree[tree[x].s[0]].sum>v)x=tree[x].s[0];
        else if(tree[x].v+tree[tree[x].s[0]].sum<v)v-=tree[x].v+tree[tree[x].s[0]].sum,sum+=tree[tree[x].s[0]].size+1,x=tree[x].s[1];
        else{
        	sum+=tree[tree[x].s[0]].size+1;
        	break;
		}
    }
    splay(x);
    return sum;
}
void build1(int x,int dep){
    chan[x].s=1,chan[x].dep=dep;
    for(int i=0;i<edge[x].size();i++){
        if(edge[x][i]==chan[x].f)continue;
        chan[edge[x][i]].f=x,chan[edge[x][i]].v=val[x][i],build1(edge[x][i],dep+1),chan[x].s+=chan[edge[x][i]].s;
        if(chan[edge[x][i]].s>chan[chan[x].h_s].s)chan[x].h_s=edge[x][i];
    }
    return;
}
void build2(int x,int top){
    chan[x].dep=top;
    if(chan[x].h_s)build2(chan[x].h_s,top);
    for(int i:edge[x]){
        if(i==chan[x].f||i==chan[x].h_s)continue;
        build2(i,i);
    }
    return;
}
int lca(int x,int y,int z){
	int sum=0;
	tot=0,root=0;
	while(x!=y){
		if(chan[x].dep<chan[y].dep)swap(x,y);
		ins(chan[x].v),x=chan[x].f,sum++;
		cout<<x<<" "<<y<<" wqqwewe13211231\n";
	}
	return sum-kth(z);
}
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
    return;
}
main(){
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
    n=read(),m=read(),q=read();
    for(int i=1;i<n;i++){
        tip[i][0]=uu=read(),tip[i][1]=uv=read();
        edge[uu].push_back(uv);
        edge[uv].push_back(uu);
    }
    for(int i=1;i<=m;i++){
    	ux=read(),uy=read();
    	vvv[ux]=uy;
	}
	for(int i=1;i<n;i++){
		val[tip[i][1]].push_back(vvv[i]);
		val[tip[i][0]].push_back(vvv[i]);
	}
    build1(1,1),build2(1,1);
    for(int i=1;i<=q;i++){
    	print(-1),putchar('\n');
	}
    return 0;
}
