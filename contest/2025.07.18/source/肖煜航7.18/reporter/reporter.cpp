#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long  
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=2e5+5;
vector<int> e[N];
int n,b[N];
int a[N],h[N];
int len,rt;
ll c[N];
ll f[5005][5005];
ll tmp[5005];
void dfs(int u,int fa){
	for(int j=1;j<=len;j++) if(j!=h[u]) f[u][j]=c[u];
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v==fa) continue;
		dfs(v,u);
		for(int j=0;j<=len;j++) tmp[j]=3e16;
		tmp[len+1]=3e16;
		for(int j=len;j;j--) tmp[j]=min(tmp[j+1],f[v][j]);
		for(int j=1;j<=len;j++) f[u][j]+=tmp[j];
	}
}
int main(){
	freopen("reporter.in","r",stdin);
	freopen("reporter.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),b[i]=h[i]=read(),c[i]=read();
	sort(b+1,b+n+1);
	len=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) h[i]=lower_bound(b+1,b+len+1,h[i])-b;
	for(int i=1;i<=n;i++){
		if(a[i]==i){
			continue;
		}
		e[a[i]].push_back(i);
	}
	dfs(1,0);
	ll ans=1e18;
	for(int i=1;i<=len;i++) ans=min(ans,f[1][i]);
	printf("%lld",ans); 
	return 0;
}
