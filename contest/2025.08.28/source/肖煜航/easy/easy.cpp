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
const int N=2e5+5;  
int n,m;
ll a[N]; 
int main(){
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	while(m--){
		int opt=read();
		ll l,r;
		if(opt==1){
			l=read();
			for(int i=1;i<=n;i++) a[i]=min(a[i],l);
		}
		else if(opt==2){
			for(int i=1;i<=n;i++) a[i]+=i;
		} 
		else{
			l=read(),r=read();
			ll sum=0;
			for(int i=l;i<=r;i++) sum+=a[i];
			printf("%lld\n",sum);
		}
	}	
	return 0;
} 
