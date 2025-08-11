#include <bits/stdc++.h>
using namespace std;
#define NN 1035
#define INF 0x3f3f3f3f3f3f3f3f
#define lowbit(x) ((x)&(-(x)))
#define highzero(x) (32u-__builtin_clz(x))//从第0位开始，前导0的第1位 
int n,a[NN],now[NN],sum[NN],c[NN],f[NN][NN];
long long ans;
inline void check(){
	static long long tot;tot=0;
	sum[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=now[i])tot+=c[i];
		sum[i]=sum[i-1]+now[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			static int t;t=1<<highzero((i-1)^(j-1));
			static int s;s=sum[(i|(t-1))+1]-sum[((i|(t-1))^(t-1))+1-1]; 
			static int p;p=(i|(t-1))-((i|(t-1))^(t-1))+1;
			if(s<=(p>>1)){//A更多 
				tot+=((now[i]==1)+(now[j]==1))*f[i][j];
			}
			else{
				tot+=((now[i]==0)+(now[j]==0))*f[i][j];
			} 
		}
	}
	ans=min(ans,tot);
}
void dfs(int x){
	if(x>n){
		check();
		return ;
	}
	now[x]=0;
	dfs(x+1);
	now[x]=1;
	dfs(x+1);
}
int main(){
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
	scanf("%d",&n);
	n=(1<<n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	bool subtask_c0=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		if(c[i]!=0)subtask_c0=false;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			scanf("%d",&f[i][j]);
		}
	}
	if(subtask_c0){
		printf("0");
		return 0;
	}
	ans=INF;
	dfs(1);
	printf("%lld",ans);
	return 0;
}

