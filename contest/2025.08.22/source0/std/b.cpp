#include <cstdio>
using namespace std;
int read(){
	char c=getchar();int x=0;
	while(c<48||c>57) c=getchar();
	do x=(x<<1)+(x<<3)+(c^48),c=getchar();
	while(c>=48&&c<=57);
	return x;
}
const int N=2003,INF=0x3f3f3f3f;
typedef long long ll;
const ll lINF=0x3f3f3f3f3f3f3f3f;
template<typename T>
inline void chmn(T &x,T v){if(x>v) x=v;}
int n,mn;
int d[N][N];
int tmp[N];
int eu,ev;
ll f[N];
bool vis[N];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read();mn=INF;
	for(int i=1;i<=n;++i) tmp[i]=INF;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			d[j][i]=d[i][j]=read();
			chmn(tmp[i],d[i][j]);
			chmn(tmp[j],d[j][i]);
			if(d[i][j]<mn) mn=d[i][j],eu=i,ev=j;
		}
	for(int i=1;i<=n;++i) tmp[i]-=mn;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j) if(i!=j) chmn(d[i][j]-=mn,tmp[j]<<1);
	for(int i=0;i<=n;++i) f[i]=lINF;
	f[eu]=f[ev]=0;
	for(int x=1;x<=n;++x){
		int pos=0;
		for(int i=1;i<=n;++i)
			if(!vis[i]&&f[i]<f[pos]) pos=i;
		vis[pos]=1;
		for(int i=1;i<=n;++i) chmn(f[i],f[pos]+d[pos][i]);
	}
	for(int i=1;i<=n;++i) printf("%lld\n",(ll)mn*(n-1)+f[i]);
	return 0;
}
