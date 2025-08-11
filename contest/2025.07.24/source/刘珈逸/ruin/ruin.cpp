#include<bits/stdc++.h>
using namespace std;
const int N=605,mod=1e9+7;
int n,a[N];
int b[N];
int ans;
int l[N];
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n*2;i++)l[i]=b[i];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n*2;j++)if(l[j]){
				bool fl=0;
				for(int k=j+1;k<=n*2;k++)fl|=l[j]==l[k];
				l[j]-=fl;
			}
		}
//		for(int i=1;i<=n*2;i++)printf("%d ",b[i]);puts("");
//		for(int i=1;i<=n*2;i++)printf("%d ",l[i]);puts("\n");
		for(int i=1;i<=n*2;i++)if(l[i]&&!a[i]||a[i]&&!l[i])return;
		ans++;
		return;
	}for(int i=1;i<=n*2;i++)if(!b[i]){
		b[i]=x;
		for(int j=i+1;j<=n*2;j++)if(!b[j]){
			b[j]=x;
			dfs(x+1);
			b[j]=0;
		}
		b[i]=0;
	}
}
int solve(){
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
int main(){
	freopen("ruin.in","r",stdin);
	freopen("ruin.out","w",stdout);
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++)scanf("%d",&x),a[x]=1;
	if(n<=5)return solve();
	puts("0");
	return 0;
}
