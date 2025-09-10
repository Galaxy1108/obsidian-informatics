#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ans;
int fa[300010],siz[300010];
vector<int> line[300010];
int fnd(int x){
	if(fa[x]!=x) fa[x]=fnd(fa[x]);
	return fa[x];
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		line[x].push_back(i);
		line[y].push_back(i);
		fa[i]=i;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<(int)line[i].size();++j){
			int x=line[i][j-1];
			int y=line[i][j];
			if(fnd(x)==fnd(y)) continue;
			fa[fnd(x)]=fnd(y);
		}
	}
	for(int i=1;i<=m;++i){
		++siz[fnd(i)];
	}
	for(int i=1;i<=m;++i){
		ans+=siz[i]/2;
	}
	printf("%d\n",ans);
	return 0;
}