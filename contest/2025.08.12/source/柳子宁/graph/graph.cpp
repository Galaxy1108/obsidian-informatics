#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,l,r,u,v,x,y,tag,tot,cnt;
int a[200010],h[200010];
struct Line{
	int v,nxt;
}line[400010];
vector<pair<int,int> > L[200010];
vector<int> fa[200010];
int fnd(int a,int x){
	if(fa[a][x]!=x) fa[a][x]=fnd(a,fa[a][x]);
	return fa[a][x];
}
void Init(){
	k=(m+n-2)/(n-1);
	tag=x=y=0;
	for(int i=1;i<=k;++i){
		fa[i].resize(n+1);
		for(int j=1;j<=n;++j) fa[i][j]=j;
		L[i].clear();
	}
}
void Addline(int u,int v){
	line[++cnt].v=v,line[cnt].nxt=h[u],h[u]=cnt;
}
int Getpath(int x,int fa,int y){
	if(x==y) {a[++tot]=y;return 1;}
	for(int i=h[x];i;i=line[i].nxt){
		int v=line[i].v;if(v==fa) continue;
		if(Getpath(v,x,y)) {a[++tot]=x;return 1;}
	}
	return 0;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		Init();
		for(int i=1;i<=m;++i){
			scanf("%d%d",&u,&v);
			if(tag) continue;
			l=1,r=k;
			while(l<r){
				const int mid=(l+r)>>1;
				if(fnd(mid,u)==fnd(mid,v)) l=mid+1;
				else r=mid;
			}
			fa[l][fnd(l,u)]=fnd(l,v);
			L[l].push_back(make_pair(u,v));
			if(l==k){
				tag=1;
				x=u,y=v;
			}
		}
		printf("%d %d\n",x,y);
		for(int i=1;i<=k;++i){
			for(int j=1;j<=n;++j) h[j]=0;
			for(int j=1;j<=cnt;++j) line[j]=(Line){0,0};
			cnt=0;
			
			for(auto v:L[i]){
				Addline(v.first,v.second);
				Addline(v.second,v.first);
			}
			
			tot=0;
			Getpath(x,0,y);
			printf("%d ",tot);
			for(int i=tot;i>=1;--i) printf("%d ",a[i]);
			printf("\n");
		}
	}
	return 0;
}
