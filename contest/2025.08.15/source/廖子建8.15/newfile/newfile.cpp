#include<bits/stdc++.h>
#define int long long
#define N 100000
#define Mod 1000000009
using namespace std;
struct Node{int l,r,tag,v,sum;};
int n,m,q,tot=0,root[N+5],ux,uy,uz,ua,ub,uc,ud;
Node tree[N*100+5];
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
int newNode(int x){
	int p=++tot;
	tree[p]=tree[x];
	return p;
}
void pushup(int x){
	tree[x].v=(tree[tree[x].l].v+tree[tree[x].r].v)%Mod;
	tree[x].sum=(tree[tree[x].l].sum+tree[tree[x].r].sum)%Mod;
	return;
}
void printTree(int p){
	cout<<p<<" "<<tree[p].sum<<" "<<tree[p].v<<" "<<tree[p].tag<<" "<<tree[p].l<<" "<<tree[p].r<<"\n";
	if(!tree[p].l)return void();
	printTree(tree[p].l);
	printTree(tree[p].r);
	return;
}
void pushdown(int l,int r,int mid,int p){
	if(l<r&&tree[p].tag){
		tree[p].l=newNode(tree[p].l),tree[p].r=newNode(tree[p].r);
		tree[tree[p].l].tag=(tree[tree[p].l].tag+tree[p].tag)%Mod,tree[tree[p].r].tag=(tree[tree[p].r].tag+tree[p].tag)%Mod;
		tree[tree[p].l].v=(tree[tree[p].l].v+(mid-l+1)*tree[p].tag%Mod)%Mod;
		tree[tree[p].r].v=(tree[tree[p].r].v+(r-mid)*tree[p].tag%Mod)%Mod;
		tree[tree[p].l].sum=(tree[tree[p].l].sum+tree[tree[p].l].v)%Mod;
		tree[tree[p].r].sum=(tree[tree[p].r].sum+tree[tree[p].r].v)%Mod;
//		cout<<l<<" "<<mid<<" "<<tree[p].l<<" "<<tree[tree[p].l].sum<<" l\n";
//		cout<<mid+1<<" "<<r<<" "<<tree[p].r<<" "<<tree[tree[p].r].sum<<" r\n";
	}
	tree[p].tag=0;
	return;
}
int upd(int s,int t,int l,int r,int v,int p){
	int mid=(l+r)>>1;
	pushdown(l,r,mid,p);
	p=newNode(p);
	if(s<=l&&r<=t){
//		cout<<tree[p].sum<<" "<<tree[p].tag<<" "<<l<<" "<<r<<" "<<p<<" upd1\n";
		tree[p].tag=(tree[p].tag+v)%Mod;
		tree[p].v=(tree[p].v+(r-l+1)*v%Mod)%Mod;
		tree[p].sum=(tree[p].sum+tree[p].v)%Mod;
//		cout<<tree[p].sum<<" "<<tree[p].tag<<" "<<l<<" "<<r<<" "<<p<<" upd2\n";
		return p;
	}
	if(s<=mid)tree[p].l=upd(s,t,l,mid,v,tree[p].l);
	if(mid<t)tree[p].r=upd(s,t,mid+1,r,v,tree[p].r);
	pushup(p);
//	cout<<tree[p].sum<<" "<<tree[p].v<<" "<<l<<" "<<r<<" run\n";
	return p;
}
int find(int s,int t,int l,int r,int p){
	int mid=(l+r)>>1,sum=0;
	pushdown(l,r,mid,p);
//	cout<<l<<" "<<r<<" "<<p<<" "<<tree[p].sum<<" "<<tree[p].v<<" find\n";
	if(s<=l&&r<=t)return tree[p].v;
	if(s<=mid)sum=(sum+find(s,t,l,mid,tree[p].l))%Mod;
	if(mid<t)sum=(sum+find(s,t,mid+1,r,tree[p].r))%Mod;
//	cout<<tree[p].sum<<" "<<tree[p].v<<" "<<l<<" "<<r<<" run\n";
	return sum;
}
int build(int l,int r){
	int p=newNode(0);
	if(l==r)return p;
	int mid=(l+r)>>1;
	tree[p].l=build(l,mid);
	tree[p].r=build(mid+1,r);
	return p;
}
main(){
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
//	cout<<"sdfasdfsdf\n";
	n=read(),m=read(),q=read();
	root[0]=build(1,n);
	for(int i=1;i<=m;i++){
		ux=read(),uy=read(),uz=read();
		root[i]=upd(ux,uy,1,n,uz,root[i-1]);
//		printTree(root[i]);
//		for(int j=1;j<=n;j++){
//			cout<<find(j,j,1,n,root[i])<<" ";
//		}
//		cout<<"\n";
//cout<<i<<" asdfafs\n";
	}
	int ans;
	for(int i=1;i<=q;i++){
		ua=read(),ub=read(),uc=read(),ud=read();
		ans=0;
//		cout<<ua<<" "<<ub<<" "<<uc<<" "<<ud<<" ans\n";
		for(int i=ua;i<=ub;i++)ans=(ans+find(uc,ud,1,n,root[i]))%Mod;
		print(ans),putchar('\n');
	}
	return 0;
}
