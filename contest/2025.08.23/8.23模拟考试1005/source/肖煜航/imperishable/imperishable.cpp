#include<cstdio>
#include<algorithm>
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=2e5+5;
const int mod=998244353;
int cid,n,a[N],Q;
int p[N];
int solve(){
	
}
int main(){
//	freopen("imperishable.in","r",stdin);
//	freopen("imperishable.out","w",stdout);
	cid=read();
	n=read();
	p[0]=1;
	for(int i=1;i<=n;i++) p[i]=2ll*p[i-1]%mod;
	for(int i=1;i<=n;i++) a[i]=read();
	printf("%d\n",solve());
	while(Q--){
		int x=read(),y=read();
		a[x]=y;
		printf("%d\n",solve());
	}
	return 0;
}
