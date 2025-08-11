#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300;
int n,c[N];
int f[N][N],idx;
int ls[N],rs[N],na[N],nb[N];
int fa[N];
int op[N],ans;
void build(int l,int r,int &id){
	if(l==r){
		id=l;
		if(op[l]==0) na[id]++;
		else nb[id]++;
		return;
	}
	if(!id) id=++idx;
	int mid=l+r>>1;
	build(l,mid,ls[id]);
	fa[ls[id]]=id;
	build(mid+1,r,rs[id]);
	fa[rs[id]]=id;
	na[id]=na[ls[id]]+na[rs[id]];
	nb[id]=nb[ls[id]]+nb[rs[id]];
}
void dfs(int x,int sum){
	if(sum>=ans) return;
	if(x==n+1){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int p1=i,p2=j;
				int lc;
				while(p1!=p2){
					p1=fa[p1];
					p2=fa[p2];
				}
				lc=p1;
				if(na[lc]<nb[lc]){
					if(!op[i]&&!op[j]){
						sum+=2*f[i][j];
					}
					else if(!op[i]){
						sum+=f[i][j];
					}
					else if(!op[j]){
						sum+=f[i][j];
					}
				}
				else{
					if(op[i]&&op[j]){
						sum+=2*f[i][j];
					}				
					else if(op[i]){
						sum+=f[i][j];
					}
					else if(op[j]){
						sum+=f[i][j];
					}
				}
			}
		}
		ans=min(ans,sum);
		return;
	}
	dfs(x+1,sum);
	op[x]^=1;
	int p=x;
	while(p){
		if(op[x]==1) na[p]--,nb[p]++;
		else nb[p]--,na[p]++;
		p=fa[p];
	}
	dfs(x+1,sum+c[x]);
	p=x;
	while(p){
		if(op[x]==1) na[p]++,nb[p]--;
		else nb[p]++,na[p]--;
		p=fa[p];
	}
	op[x]^=1;
}
int main(){
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
	scanf("%d",&n);
	int o=1;
	for(int i=1;i<=n;i++) o<<=1;
	n=o;
	for(int i=1;i<=n;i++) scanf("%d",&op[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) scanf("%d",&f[i][j]);
	idx=n;o=0;
	build(1,n,o);
	ans=2147483647;
	dfs(1,0);
	printf("%d",ans);
	return 0;
} 
