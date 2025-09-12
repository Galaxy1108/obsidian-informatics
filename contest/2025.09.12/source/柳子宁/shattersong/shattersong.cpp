#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int fa[100010],siz[100010];
long long Z[100010],val[100010];
vector<int> V[100010];
struct Line{
	int x,y;
	long long w;
}line[500010];
bool cmp(Line x,Line y) {return x.w<y.w;}
int fnd(int x){
	if(fa[x]!=x) fa[x]=fnd(fa[x]);
	return fa[x];
}
int main()
{
	freopen("shattersong.in","r",stdin);
	freopen("shattersong.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>Z[i],siz[i]=1;
	for(int i=1;i<=m;++i) cin>>line[i].x>>line[i].y>>line[i].w;
	for(int i=1;i<=n;++i) fa[i]=i;
	sort(line+1,line+m+1,cmp); 
	while(1){
		int tag=0;
		for(int i=1;i<=m;++i){
			x=fnd(line[i].x);y=fnd(line[i].y);
			if(x==y) continue;
			long long v=min(val[x]+Z[siz[x]],val[y]+Z[siz[y]]);
			if(line[i].w>v) continue;
			siz[y]+=siz[x];
			val[y]=max(val[y],val[x]);
			val[y]=max(val[y],line[i].w);
			fa[x]=y;
			tag=1;
			break;
		}
		if(!tag) break;
	}

	int ans=0;
	for(int i=1;i<=n;++i){
		if(fa[i]==i) ++ans;
		V[fnd(i)].push_back(i);
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;++i){
		if(fa[i]==i){
			printf("%d ",(int)V[i].size());
			for(auto v:V[i]) printf("%d ",v);
			printf("\n");
		}
	}

	return 0;
}
