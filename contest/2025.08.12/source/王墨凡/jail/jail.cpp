#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio> 
#include<map> 
using namespace std;
struct edge{
	int to,from,ru,ch;
};
struct crim{
	int e,s,lca;
}mem[120086];
int fa[120086][21],depth[120086],q,lc[120086];
vector<edge> tree[120086];
bool cmp(crim a,crim b){
	return a.lca < b.lca;
}

void dfs(int f,int x,int deep){
	fa[x][0]=f;
	depth[x]=deep;
	for(int i=1;i<=20;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(edge i:tree[x]){
		if(i.to==f)continue;
		dfs(x,i.to,deep+1);
	}
}
int lca(int x,int y){
	bool flag=0;
	if(depth[x]<depth[y])swap(x,y),flag=1;
	int k=20;
	while(depth[x]!=depth[y] and k>=0){
		if(depth[fa[x][k]]>=depth[y]){
			x=fa[x][k];
		}
		k--;
	}
	for(int i=20;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	return fa[x][0];
}
int main(){
//	freopen("jail.in","r",stdin);
//	freopen("jail.out","w",stdout);
	cin >> q;
	while(q--){
		int n,m,x,y;
		cin >> n;
		for(int i=1;i<=n;i++)tree[i].clear();
		for(int i=1;i<n;i++){
			cin >> x >> y;
			tree[x].push_back({y,x,0,0});
			tree[y].push_back({x,y,0,0});
		}
		dfs(0,1,1);
		cin >> m;
		for(int i=1;i<=m;i++){
			cin >> mem[i].s >> mem[i].e;
			lc[i]=mem[i].lca=lca(mem[i].s,mem[i].e);
		}
		sort(mem+1,mem+1+m,cmp);
		int maxx=unique(lc+1,lc+1+m)-(lc+1);
		if(maxx<m){
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}
	return 0;
} 
