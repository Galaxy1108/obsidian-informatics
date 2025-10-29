#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int N=205;
int n;
ll mod;
int a[N];
bool vis[N];
ll b[N];
ll ans;
void dfs(int x){
	if(x==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) if(a[j]<a[i]) cnt++;
		}
		for(int i=cnt+1;i<=100;i++){
			ans+=b[i];
			ans%=mod;
		}
		b[cnt]++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main(){
	freopen("pair.in","r",stdin);
	freopen("pair.out","w",stdout);
	scanf("%d%lld",&n,&mod);
	dfs(1);
	printf("%lld",ans);
	return 0;
} 
