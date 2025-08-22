#include <cstdio>
using namespace std;
typedef __int128 lll;
typedef long long ll;
const int N=20000003;
int n,m,p;ll md;
struct barrett{
	friend ll operator%(const ll x,const barrett s){
		return x-((lll)x*md>>64)*p;
	}
}P;
int f[N],g[N],res;
inline void inc(int &x,int v){(x+=v)>=p&&(x-=p);}
inline void dec(int &x,int v){(x-=v)<0&&(x+=p);}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d%d",&n,&m,&p);md=((lll)1<<64)/p;
	for(int i=1;i<=m;++i) f[i]=i;
	res=((ll)m*(m+1)>>1)%P;
	for(int o=2;o<=n;++o){
		for(int i=1;i<=m;++i) inc(g[i]=f[i],g[i-1]);
		for(int i=1;i<=m;++i) f[i]=(ll)(res-g[m-i]+p)*i%P;
		int cur=0;
		res=0;
		for(int i=1;i<=m;++i) dec(f[i],cur),inc(cur,g[i]),inc(res,f[i]);
	}
	printf("%d\n",res%p);
	return 0;
}
