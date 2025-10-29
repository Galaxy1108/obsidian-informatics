#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=2e5+5; 
int n;
ll f[N],a[N],s[N];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++) f[i]=1e18;
	f[0]=0;
	for(int i=1;i<=n;i++){
		if(a[i]&1) f[i]=1+s[i-1];
		else f[i]=s[i-1];
		if(a[i]==0){
			f[i]=min(f[i],f[i-1]+1);			
		}
		else{
			ll op=a[i]-1;
			if(op&1){
				f[i]=min(f[i],f[i-1]+1);
			}
			else{
				f[i]=min(f[i],f[i-1]);
			}
		}
	}
	ll ans=1e18;
	for(int i=0;i<=n;i++){
		ll res=f[i];
		if(i<n){
			if(a[i+1]&1) res++;
			res+=s[n]-s[i+1];
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
