#include<bits/stdc++.h>
#define int long long
#define N 120000
using namespace std;
struct Node{int f,size,hs,top,dfn,dep;};
int n,q,m,uu,uv,tot=0,s[N+5],t[N+5],l[N+5],ver[N+5],a[N+5],b[N+5];
Node tree[N+5];
bool flag[N+5],ans;
vector<int>edge[N+5],graph[N+5];
queue<int>p;
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
	return (tree[y].dep<tree[x].dep?y:x);
}
void solve(int x){
	int u=s[x];
//	cout<<x<<" solve\n";
	while(u!=l[x]){
//		cout<<u<<" "<<a[u]<<"\n";
		if(a[u]&&a[u]!=x)graph[a[u]].push_back(x),ver[x]++;
		if(b[u]&&b[u]!=x)graph[x].push_back(b[u]),ver[b[u]]++;
		u=tree[u].f;
	}
	u=t[x];
	while(u!=l[x]){
//		cout<<u<<" "<<a[u]<<"\n";
		if(a[u]&&a[u]!=x)graph[a[u]].push_back(x),ver[x]++;
		if(b[u]&&b[u]!=x)graph[x].push_back(b[u]),ver[b[u]]++;
		u=tree[u].f;
	}
	u=l[x];
//	cout<<u<<" "<<a[u]<<"\n";
	if(a[u]&&a[u]!=x)graph[a[u]].push_back(x),ver[x]++;
	if(b[u]&&b[u]!=x)graph[x].push_back(b[u]),ver[b[u]]++;
	return;
}
main(){
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	q=read();
	while(q--){
		n=read(),tot=0;
		for(int i=1;i<=n;i++)edge[i].resize(0),b[i]=a[i]=0;
		for(int i=1;i<n;i++){
			uu=read(),uv=read();
			edge[uu].push_back(uv);
			edge[uv].push_back(uu);
		}
		build1(1,1);
		build2(1,1);
		m=read();
		for(int i=1;i<=m;i++){
			s[i]=read(),t[i]=read(),l[i]=lca(s[i],t[i]);
			b[t[i]]=a[s[i]]=i,flag[i]=ver[i]=0,graph[i].resize(0);
//			cout<<s[i]<<" "<<t[i]<<" "<<l[i]<<" "<<i<<"\n";
		}
		for(int i=1;i<=m;i++)solve(i);
		while(p.size())p.pop();
		for(int i=1;i<=m;i++){
			if(!ver[i])p.push(i);
		}
//		cout<<"queue\n";
		while(p.size()){
//			cout<<p.front()<<" "<<ver[p.front()]<<"\n";
			flag[p.front()]=1;
			for(int i:graph[p.front()]){
				ver[i]--;
				if(!ver[i])p.push(i);
			}
			p.pop();
		}
		ans=1;
		for(int i=1;i<=m;i++)ans&=flag[i];
		if(ans)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
