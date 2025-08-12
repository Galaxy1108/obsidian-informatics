#include<bits/stdc++.h>
#define int long long
#define N 120000
using namespace std;
struct Node{int f,size,hs,top,dfn,dep;};
int n,q,m,tot=0,uu,uv,s[N+5],t[N+5],l[N+5];
bool ans=0;
Node tree[N+5];
vector<int>edge[N+5];
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
void build1(int x,int dep){
	tree[x].size=1,tree[x].dep=dep,tree[x].hs=0;
	for(int i:edge[x]){
		if(i==tree[x].f)continue;
		tree[i].f=x,build1(i,dep+1);
		tree[x].size+=tree[i].size;
		if(tree[i].size>tree[tree[x].hs].size)tree[x].hs=i;
	}
	return;
}
void build2(int x,int top){
	tree[x].dfn=++tot,tree[x].top=top;
	if(tree[x].hs)build2(tree[x].hs,top);
	for(int i:edge[x]){
		if(i==tree[x].f||i==tree[x].hs)continue;
		build2(i,i);
	}
	return;
}
int lca(int x,int y){
	while(tree[x].top!=tree[y].top){
		if(tree[tree[x].top].dep<tree[tree[y].top].dep)swap(x,y);
		x=tree[tree[x].top].f;
	}
	return (tree[x].dep>tree[y].dep?y:x);
}
bool check(int x,int y,int z){
	while(tree[x].top!=tree[y].top){
		if(tree[tree[x].top].dfn<=tree[z].dfn&&tree[z].dfn<=tree[x].dfn)return 1;
		x=tree[tree[x].top].f;
	}
	return (tree[y].dfn<=tree[z].dfn&&tree[z].dfn<=tree[x].dfn);
}
main(){
	q=read();
	while(q--){
		n=read(),tot=0,ans=1;
		for(int i=1;i<=n;i++)edge[i].resize(0);
		for(int i=1;i<n;i++){
			uu=read(),uv=read();
			edge[uu].push_back(uv);
			edge[uv].push_back(uu);
		}
		build1(1,1);
		build2(1,1);
		m=read();
		for(int i=1;i<=m;i++)s[i]=read(),t[i]=read(),l[i]=lca(s[i],t[i]),cout<<s[i]<<" "<<t[i]<<" "<<l[i]<<" "<<i<<"\n";
		cout<<m<<"\n";
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==1&&j==3)cout<<check(s[i],l[i],s[j])<<" "<<check(t[i],l[i],s[j])<<" "<<i<<" "<<j<<" b\n";
				if(i==j||!check(s[i],l[i],s[j])&&!check(t[i],l[i],s[j]))continue;
				if(i==1&&j==3)cout<<check(s[i],l[i],t[j])<<" "<<check(t[i],l[i],t[j])<<" "<<check(s[j],l[j],s[i])<<" "<<check(t[j],l[j],s[i])<<" "<<i<<" "<<j<<" a\n";
				if(check(s[i],l[i],t[j])||check(t[i],l[i],t[j])||check(s[j],l[j],s[i])||check(t[j],l[j],s[i])){
					ans=0;
					break;
				}
			}
			if(!ans)break;
		}
		if(ans)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
