#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#define ull unsigned long long
using namespace std;
const ull P=131;
int read(){
	int p=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p*w;
}
const int N=75;
const int mod=1e9+7;
int n,a[N<<1];
int f[N][N][N][N];
int cnt1;
int tot,b[N];
bool vis[N<<1];
int tmp[N][N][N][N];
int jia(int x,int y){
	x+=y;
	if(x>=mod) x-=mod;
	return x;
}
namespace solve{
	int b[N<<1];
	int c[N],ans;
	unordered_map<ull,bool> yes;
	void dfs(int x){
		if(x==2*n+1){
			for(int i=1;i<=2*n;i+=2){
				c[i/2+1]=min(b[i],b[i+1]);
			}
			ull h=0;
			for(int i=1;i<=n;i++) h=h*P+c[i];
			if(yes[h]) return;
			yes[h]=1;ans++;
			return;
		}	
		if(a[x]!=-1){
		b[x]=a[x];
			dfs(x+1);
			return;
		}
		for(int i=1;i<=2*n;i++){
			if(!vis[i]){
				vis[i]=1;
				b[x]=i;
				dfs(x+1);
				vis[i]=0;
			}
		}
	}
	void solve(){
		dfs(1);
		printf("%d",ans);
	}
}
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=read();
	for(int i=1;i<=2*n;i++) a[i]=read();
	for(int i=1;i<=2*n;i++){
		if(a[i]==-1) continue;
		vis[a[i]]=1;
	}
	if(n<=5){
		solve::solve();
		return 0;
	}
	for(int i=1;i<=2*n;i+=2){
		if(a[i]==-1&&a[i+1]==-1){
			cnt1++;	
			continue;
		}
		if(a[i]!=-1&&a[i+1]!=-1) continue;
		if(a[i]!=-1) b[++tot]=a[i];
		else b[++tot]=a[i+1];
	}
	sort(b+1,b+tot+1);
	int now=tot+1;
	f[cnt1][0][0][0]=1;
	for(int i=2*n;i;i--){  
		if(vis[i]) continue;
		memcpy(tmp,f,sizeof tmp);
		memset(f,0,sizeof f);
		bool flag=0;
		while(now>1&&b[now-1]>i){
			flag=1;
			for(int x1=0;x1<=n;x1++) for(int x2=0;x2<=n;x2++){
				for(int l=1;l<=n;l++) for(int x4=0;x4<=tot;x4++){
					f[x1][x2][l][x4]=jia(f[x1][x2][l][x4],tmp[x1][x2][l-1][x4]);
				}
			}
			now--;
		}
		if(!flag) memcpy(f,tmp,sizeof f);
		memcpy(tmp,f,sizeof tmp);
		memset(f,0,sizeof f);
		for(int x1=0;x1<=n;x1++) for(int x2=0;x2<=n;x2++) for(int x3=0;x3<=n;x3++) for(int x4=0;x4<=tot;x4++){
			//1
			if(x1>0) f[x1-1][x2+1][x3][x4]=jia(f[x1-1][x2+1][x3][x4],tmp[x1][x2][x3][x4]);
			//2
			if(x2>0) f[x1][x2-1][x3][x4]=jia(f[x1][x2-1][x3][x4],1ll*tmp[x1][x2][x3][x4]*x2%mod);
			//3
			if(x3>0) f[x1][x2][x3-1][x4]=jia(f[x1][x2][x3-1][x4],1ll*tmp[x1][x2][x3][x4]*x3%mod);
			//4
			if(x4<tot) f[x1][x2][x3][x4+1]=jia(f[x1][x2][x3][x4+1],tmp[x1][x2][x3][x4]);
		}
	}
	int ans=0;
	for(int i=0;i<=tot;i++) ans=jia(ans,f[0][0][i][i]);
	printf("%d",ans);
	return 0;
}
