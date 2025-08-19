#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=1e6+5;
int n;
ll X[N],p[N],c[N];
ll s[N],a[N],b[N];
int q[N],head,tail;
ll f[N];
long double get(int x,int y){
	return 1.0*(f[x]-b[x]-f[y]+b[y])/(a[y]-a[x]);
}
int main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++) X[i]=read(),p[i]=read(),c[i]=read();
	for(int i=1;i<=n;i++) s[i]=X[n]-X[i];
	for(int i=1;i<=n;i++){
		a[i]=a[i-1]+p[i];
		b[i]=b[i-1]+p[i]*s[i];
	}
	head=tail=1;
	q[1]=0;
	for(int i=1;i<=n;i++){
		while(tail-head+1>1&&get(q[head],q[head+1])>s[i]) head++;
		int j=q[head];
		f[i]=f[j]+b[i]-b[j]-s[i]*a[i]+s[i]*a[j]+c[i];
		while(tail-head+1>1&&get(q[tail-1],q[tail])<get(q[tail],i)) tail--;
		q[++tail]=i;
	}
	printf("%lld",f[n]);
	return 0;
} 
