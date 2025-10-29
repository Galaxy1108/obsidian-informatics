#include<bits/stdc++.h>
using namespace std;
using ll =long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,a[maxn];
ll f[5];
const ll inf=9e18;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++){
		f[0]+=a[i];
		f[1]+=a[i]%2;
		f[2]+=!(a[i]%2);
		f[3]+=a[i]%2;
		f[4]+=a[i];
		for(int j=1;j<5;j++) f[j]=min(f[j],f[j-1]);
	}
	printf("%lld\n",f[4]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}