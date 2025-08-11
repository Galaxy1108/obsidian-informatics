#include<bits/stdc++.h>
using  namespace std;
const int maxn=150000+10;
int n;
//int x[maxn],y[maxn],z[maxn];
int a[5][maxn];
int vis[5][maxn];
//int hx[maxn],hy[maxn],hz[maxn];
int ans;
//bool cmp1(int a,int b){
//	return x[a]>x[b];
//}
//bool cmp1(int a,int b){
//	return y[a]>y[b];
//}
//bool cmp1(int a,int b){
//	return z[a]>z[b];
//}

void dfs(int now,int dep,int sum){
//	printf("%d %d %d\n",now,dep,sum);
//	
	
	if(vis[1][now]==1||vis[2][now]==1)return;
	if(dep>=3){
		
//		
//	for(int i=1;i<=100;i++){
//		printf("%d ",vis[1][i]);
//	}
//	printf("\n");
//	for(int i=1;i<=100;i++){
//		printf("%d ",vis[2][i]);
//	}
//	printf("\n\n\n");
//		printf("####%d %d\n",ans,sum);
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if((a[dep][i]>=a[dep][now])){
			vis[dep][i]=1;
		}
	}
	for(int i=1;i<=n;i++){
//		if((a[dep][i]<a[dep][now])){
//			if((a[dep+1][i]>a[dep+1][now]))
//				dfs(i,dep+1,sum+a[dep+1][i]);
//		}else{
//			vis[dep][i]=1;
//		}
		if(vis[dep][i]==0&&(a[dep+1][i]>a[dep+1][now])){
			dfs(i,dep+1,sum+a[dep+1][i]);
		}
	}
	memset(vis[dep],0,sizeof(vis[dep]));
	return;
}

int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
//	sort(hx+1,hx+1+n,cmp1);
//	sort(hy+1,hy+1+n,cmp2);
//	sort(hz+1,hz+1+n,cmp3);
	for(int i=1;i<=n;i++){
		dfs(i,1,a[1][i]);
	}
	if(ans==0)ans=-1;
	printf("%d",ans);
	return 0;
}
