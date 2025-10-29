#include <cstdio>
#include <vector>
#define N 301
int status[N],parent[N];
std::vector<int> edges[N];
std::vector<int> depths[N];
int tot=1,ans=0x3fffffff;
void get_depths(int par,int grandpar,int depth){
    depths[depth].push_back(par);
    for(int child:edges[par]){
	if(child==grandpar) continue;
	parent[child]=par;
	get_depths(child,par,depth+1);
    }
}
	
void dfs(int depth){
    for(int par:depths[depth]){
	if(status[par]==-1){
	    for(int child:edges[par]){
		if(child==parent[par]) continue;
		status[child]=-1;
	    }
	}
    }
    int affected=0;
    for(int i:depths[depth+1]){
	if(status[i]==0){
	    affected++;
	    status[i]=1;
	}
    }
    if(affected<=1){
	if(tot<ans) ans=tot;
	return;
    }
    tot+=affected-1;
    if(tot>ans) return;
    for(int par:depths[depth]){
	if(status[par]==1){
	    for(int child:edges[par]){
		if(child==parent[par]) continue;
		status[child]=-1;
		dfs(depth+1);
		status[child]=1;
	    }
	}
    }
    tot-=affected-1;
}
#define file(filen)\
    freopen(#filen ".in","r",stdin);\
    freopen(#filen ".out","w",stdout);
int main(){
    file(disease)
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    while(m--){
	scanf("%d%d",&u,&v);
	edges[u].push_back(v);
	edges[v].push_back(u);
    }
    get_depths(1,0,0);
    status[1]=1;
    dfs(0);
    printf("%d\n",ans);
}
