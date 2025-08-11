#include<cstdio>
#define N 500001
struct edge{
	int v,nxt;
}edges[N];
int heads[N],weight[N];
long long ans_size[N],ans_tot[N];
#define child edges[id].v
void get_ans(int par){
	// printf("%d",par);
	ans_tot[par]=weight[par];
	ans_size[par]=1;
	for(int id=heads[par];id;id=edges[id].nxt){
		get_ans(child);
		if(ans_tot[child]/weight[par]>=ans_size[child]){
			ans_size[par]+=ans_size[child];
			ans_tot[par]+=ans_tot[child];
		}
	}
	// printf("<%d,%d>",ans_tot[par],ans_size[par]);
}
#undef child
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int inp;
		scanf("%d",&inp);
		edges[i]=edge{i,heads[inp]};
		heads[inp]=i;
	}
	for(int i=1;i<=n;i++) scanf("%d",&weight[i]);
	get_ans(1);
	for(int i=1;i<=n;i++){
		printf("%.10lf\n",(double)ans_tot[i]/ans_size[i]);
	}
}