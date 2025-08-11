#include <bits/stdc++.h>
using namespace std;
int fa[500010],a[500010],n,wg[500010],cnt[500010],maxn=0;
struct wig{
	int flag;
	int w;
}wi[500010];
struct anser{
	int ans;
	int cnt;
}f[500010];
bool cmp(wig x,wig y){
	return x.w>y.w;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&fa[i]);
		 wi[i].flag++;
		 	wi[i].w=wi[fa[i]].w+1;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&wg[i]);
		wi[i].w=wi[fa[i]].w+1;
		maxn=max(wi[i].w,maxn);
	}
	int wz=1;
	sort(wi+1,wi+1+n,cmp);
} 
