#include<bits/stdc++.h>
//#define int long long
#define N 1000000
using namespace std;
struct Node{int v,l,r;};
int n,l,r,s[N+5],a[N+5],tot=0,root[N+5],tip[N+5]={},second[N+5]={},ans=INT_MAX,maxn=0;
bool flag=0;
Node tree[N+N*30+5];
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
int newNode(Node x){
	int p=++tot;
	tree[p]=x;
	return p;
}
int upd(int s,int t,int x,int p){
	int now=newNode(tree[p]),mid=(s+t)>>1;
	if(s==t){
		tree[now].v++;
		return now;
	}
	if(x<=mid)tree[now].l=upd(s,mid,x,tree[p].l);
	else tree[now].r=upd(mid+1,t,x,tree[p].r);
	return now;
}
int find(int s,int t,int x,int p){
	if(s==t)return tree[p].v;
	int mid=(s+t)>>1;
	if(x<=mid)return find(s,mid,x,tree[p].l);
	else return find(mid+1,t,x,tree[p].r);
	return 0;
}
int build(int s,int t){
	int p=++tot,mid=(s+t)>>1;
	if(t==s){
		tree[p].v=tree[p].l=tree[p].r=0;
		return p;
	}
	tree[p].l=build(s,mid);
	tree[p].r=build(mid+1,t);
	return p;
}
void getans(int i){
	if(!tip[i]||tip[i]>=l||(second[i]&&second[i]<=r))return;
	for(int j=r+1;j<=(second[i]?second[i]:n);j++){
		if(j-tip[i]+1>=ans)break;
		if(find(1,maxn,s[j],root[tip[i]])==1){
			ans=min(ans,j-tip[i]+1);
			break;
		}
	}
	return;
}
main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	n=read(),l=read(),r=read();
	for(int i=1;i<=n;i++){
		s[i]=read();
		maxn=max(maxn,s[i]);
		if(!tip[s[i]])tip[s[i]]=i;
		else if(!second[s[i]])second[s[i]]=i;
	}
//	cout<<maxn<<"\n";
	root[n+1]=build(1,maxn);
	for(int i=n;i>0;i--){
		root[i]=upd(1,maxn,s[i],root[i+1]);
	}
	srand(time(0));
//	for(int i=1;i<=10;i++)getans(rand()%maxn+1);
	for(int i=1;i<=maxn;i++){
		if(!tip[i]||tip[i]>=l||(second[i]&&second[i]<=r))continue;
		for(int j=r+1;j<=(second[i]?second[i]:n);j++){
			if(j-tip[i]+1>=ans)break;
			if(find(1,maxn,s[j],root[tip[i]])==1){
				ans=min(ans,j-tip[i]+1);
				break;
			}
		}
//		getans(i);
	}
	if(ans==INT_MAX)print(-1);
	else print(ans);
	return 0;
}
