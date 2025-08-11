#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,q,p[200010],a[200010],x,y,z,c,d;
ll kpow(ll b){
	if(b==1) return 2;
	int tmp=kpow(b/2);
	tmp*=tmp;
	if(b%2==1) tmp*=2;
	return tmp;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&p[i]);
	}
	while(q){
		q--;
		scanf("%lld%lld%lld",&x,&y,&z);
		if(x==1){
			p[y]=z;
		}
		if(x==2){
			for(int i=y;i<=y+kpow(z)-1;i++){
				a[i]=p[i];
			}
			for(int i=1;i<=z;i++){
				for(int j=y;j<=y+kpow(z)-1;j++){
					while(a[j]==-1) j++;
					c=j;
					j++;
					while(a[j]==-1) j++;
					d=j; 
					a[c]=abs(a[c]-a[d]);
					a[d]=-1;
				}
			}
			for(int i=y;i<=y+kpow(z)-1;i++){
				if(a[i]!=-1){
					printf("%lld\n",a[i]);
					break;
				}
			}
		}
	}
	return 0;
}
