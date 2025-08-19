#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch<='9'&&ch>='0') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=1e6+5;
int pri[N],tot;
int mu[N];
ll s[N];
bool vis[N];
ll get(int n,int m,int k){
	if(n==0||m==0) return 0;
	ll ans=0;
	int l=1,r=0;
	while(l<=min(n,m)){
		r=min(n/(n/l),m/(m/l));
		ans+=1ll*(s[r]-s[l-1])*(n/l/k)*(m/l/k);
		l=r+1;
	}
	return ans;
}
ll get1(int x,int l,int r,int k){
	return get(x,r,k)-get(x,l-1,k);
}
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	mu[1]=1;
	for(int i=2;i<=1000000;i++){
		if(!vis[i]) pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*pri[j]<=1000000;j++){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
			mu[i*pri[j]]=-mu[i];
		}
	}
	for(int i=1;i<=1000000;i++) s[i]=s[i-1]+mu[i];
	int n=read();
	while(n--){
		int a=read(),b=read(),c=read(),d=read(),k=read();
		printf("%lld\n",get1(b,c,d,k)-get1(a-1,c,d,k));
	}
	return 0;
}
