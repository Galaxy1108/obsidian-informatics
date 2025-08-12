#include<bits/stdc++.h>
using namespace std;
int T,n,cnt,x,y,tot,m,px,py,lca;
int h[5000010],in[5000010],sid[200010],tid[200010],s[200010],t[200010],dep[200010];
int ids[20][200010],idt[20][200010],fa[20][200010];
queue<int> q;
struct Line{
	int v,nxt;
}line[40000010];
vector<int> son[200010];
void Addline(int u,int v){
	if(!u||!v) return;
//	cerr<<u<<"->"<<v<<'\n'; 
	line[++cnt].v=v,line[cnt].nxt=h[u],h[u]=cnt,++in[v];
	return;
}
void dfs(int x){
	ids[0][x]=++tot;
	idt[0][x]=++tot;
	if(sid[x]) Addline(sid[x],ids[0][x]);
	if(tid[x]) Addline(idt[0][x],tid[x]);
	for(auto v:son[x]){
		if(fa[0][x]==v) continue;
		dep[v]=dep[x]+1;
		fa[0][v]=x;
		dfs(v);
	}
}
int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int k=18;k>=0;--k) if(dep[fa[k][x]]>=dep[y]) x=fa[k][x];
	if(x==y) return x;
	for(int k=18;k>=0;--k) if(fa[k][x]!=fa[k][y]) x=fa[k][x],y=fa[k][y];
	return fa[0][x];
}
void Add1(int x,int y,int id){
	if(dep[x]<dep[y]) swap(x,y);
	for(int k=18;k>=0;--k){
		if(dep[fa[k][x]]>=dep[y]){
			Addline(ids[k][x],id);
			x=fa[k][x];
		}
	}
	if(x==y){
		if(sid[x]) Addline(sid[x],id);
		return;
	}
	for(int k=18;k>=0;--k){
		if(fa[k][x]!=fa[k][y]){
			Addline(ids[k][x],id);
			Addline(ids[k][y],id);
			x=fa[k][x],y=fa[k][y];
		}
	}
	if(sid[x]) Addline(sid[x],id);
	if(sid[y]) Addline(sid[y],id);
	x=fa[0][x];
	if(sid[x]) Addline(sid[x],id);
	return;
} 
void Add2(int x,int y,int id){
	if(dep[x]<dep[y]) swap(x,y);
	for(int k=18;k>=0;--k){
		if(dep[fa[k][x]]>=dep[y]){
			Addline(id,idt[k][x]);
			x=fa[k][x];
		}
	}
	if(x==y){
		if(tid[x]) Addline(id,tid[x]);
		return;
	}
	for(int k=18;k>=0;--k){
		if(fa[k][x]!=fa[k][y]){
			Addline(id,idt[k][x]);
			Addline(id,idt[k][y]);
			x=fa[k][x],y=fa[k][y];
		}
	}
	if(tid[x]) Addline(id,tid[x]);
	if(tid[y]) Addline(id,tid[y]);
	x=fa[0][x];
	if(tid[x]) Addline(id,tid[x]);
	return;
} 
int Topsort(){
	for(int i=1;i<=tot;++i){
		if(in[i]==0) q.push(i);
	}
	while(!q.empty()){
		int p=q.front();q.pop();
		for(int i=h[p];i;i=line[i].nxt){
			--in[line[i].v];
			if(in[line[i].v]==0) q.push(line[i].v);
		}
	}
	for(int i=1;i<=tot;++i){
		if(in[i]) return 0;
	}
	return 1;
}
void Clear(){
	for(int i=0;i<=n;++i) son[i].clear();
	while(!q.empty()) q.pop();
	for(int k=0;k<=19;++k){
		memset(ids[k],0,sizeof(int)*(n+5));
		memset(idt[k],0,sizeof(int)*(n+5));
		memset(fa[k],0,sizeof(int)*(n+5));
	}
	memset(h,0,sizeof(int)*(tot+5));
	memset(in,0,sizeof(int)*(tot+5));
	memset(sid,0,sizeof(int)*(n+5));
	memset(tid,0,sizeof(int)*(n+5));
	memset(s,0,sizeof(int)*(n+5));
	memset(t,0,sizeof(int)*(n+5));
	memset(dep,0,sizeof(int)*(n+5));
	n=cnt=x=y=tot=m=px=py=lca=0;
	return;
}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<n;++i){
			scanf("%d%d",&x,&y);
			son[x].push_back(y);
			son[y].push_back(x);
		}
		scanf("%d",&m);
		for(int i=1;i<=m;++i){
			scanf("%d%d",&s[i],&t[i]);
			sid[s[i]]=i,tid[t[i]]=i;
		}
		tot=n;
		dep[1]=1,dfs(1);
		for(int k=1;k<=18;++k){
			for(int i=1;i<=n;++i){
				ids[k][i]=++tot,idt[k][i]=++tot;
				Addline(ids[k-1][i],ids[k][i]);
				Addline(ids[k-1][fa[k-1][i]],ids[k][i]);
				Addline(idt[k][i],idt[k-1][i]);
				Addline(idt[k][i],idt[k-1][fa[k-1][i]]);
				fa[k][i]=fa[k-1][fa[k-1][i]];
			}
		}
		for(int i=1;i<=m;++i){
			x=s[i],y=t[i];
			lca=LCA(x,y);
			if(x==lca){
				px=y;
				for(int k=18;k>=0;--k){
					if(dep[fa[k][px]]>dep[x]) px=fa[k][px];
				}
				py=fa[0][y];
			}
			else if(y==lca){
				px=fa[0][x];
				py=x;
				for(int k=18;k>=0;--k){
					if(dep[fa[k][py]]>dep[y]) py=fa[k][py];
				}
			}
			else px=fa[0][x],py=fa[0][y];
			
			Add1(px,y,i);
			Add2(x,py,i);
		}
		if(Topsort()) printf("Yes\n");
		else printf("No\n");
		
		Clear();
	}
	
	return 0;
} 
