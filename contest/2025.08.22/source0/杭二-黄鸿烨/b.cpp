#include<bits/stdc++.h>
using namespace std;
struct edge{
	int u,v,w;
};
vector<edge> e;
int n;
namespace baoli{
	int pcnt[20000];
	vector<pair<int,int>> vec[20];
	long long sum,ans[200];
	void DFS(int u,int fa,int dis){
		if(fa!=-1) sum+=dis;
		for(auto P:vec[u]){
			const int v=P.first,w=P.second;
			if(v==fa) continue;
			DFS(v,u,min(dis,w));
		}
	}
	int lowbit(int x){return (x&(-x));}
	int fa[200];
	int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
	void merge(int u,int v){fa[find(u)]=find(v);}
	int main(){
		pcnt[0]=0;
		for(int i=1;i<20000;++i) pcnt[i]=pcnt[i-lowbit(i)]+1;
		for(int i=0;i<n;++i) ans[i]=INT64_MAX;
		for(int S=0;S<(1<<(int)e.size());++S){
			if(pcnt[S>>14]+pcnt[S&((1<<14)-1)]==n-1){
				for(int i=0;i<n;++i) vec[i].clear();
				for(int i=0;i<n;++i) fa[i]=i;
				bool tag=false;
				for(int i=0;i<(int)e.size();++i){
					if((S>>i)&1){
						if(find(e[i].u)==find(e[i].v)){
							tag=true;
							break;
						}
						merge(e[i].u,e[i].v);
						vec[e[i].u].push_back(make_pair(e[i].v,e[i].w));
						vec[e[i].v].push_back(make_pair(e[i].u,e[i].w));
					}
				}
				if(tag) continue;
				for(int r=0;r<n;++r){
					sum=0;
					DFS(r,-1,INT_MAX);
					ans[r]=min(ans[r],sum);
				}
			}
		}
		for(int i=0;i<n;++i) cout << ans[i] << '\n';
		return 0;
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin >> n;
	for(int u=0;u<n-1;++u){
		for(int v=u+1,w;v<n;++v){
			cin >> w;
			e.push_back(edge{u,v,w});
		}
	}
	if(n<=8) return baoli::main();
	return 0;
}
