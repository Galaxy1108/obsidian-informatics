#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int siz[310],tag[310];
vector<int> line[310];
void dfs(int x,int fa){
	siz[x]=1;
	for(auto v:line[x]){
		if(v==fa) continue;
		dfs(v,x);
		siz[x]+=siz[v];
	}
}
int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		line[x].push_back(y);
		line[y].push_back(x);
	}
	
	dfs(1,0);
	
	vector<int> V;
	V.push_back(1);
	tag[1]=1;
	
	while(1){
		vector<int> V1;
		for(auto u:V){
			for(auto v:line[u])
			if(!tag[v]) V1.push_back(v);
		}
		if(V1.empty()) break;
		int mx=0,id=0;
		for(auto v:V1){
			tag[v]=1;
			if(siz[v]>mx) mx=v,id=v;
		}
		for(auto v:V1){
			if(v!=id) V.push_back(v);
		}
	}
	
	printf("%d\n",(int)V.size());
	
	return 0;
}
