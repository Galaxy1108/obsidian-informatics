#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mx=N-5;
int mu[N],s[N];
int prime[N],tot;
bool isp[N];
typedef long long ll;
ll calc(int n,int m,int k){
	ll ans=0;
	n/=k;m/=k;if(n>m)swap(n,m);
	for(int l=1,r;l<=n;l=r+1){
		r=min(n/(n/l),m/(m/l));
		ans+=1ll*(n/l)*(m/l)*(s[r]-s[l-1]);
	}return ans;
}
int main(){
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	mu[1]=1;
	for(int i=2;i<=mx;i++){
		if(!isp[i])prime[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&i*prime[j]<=mx;j++){
			isp[i*prime[j]]=1;
			if(i%prime[j]==0)break;
			mu[i*prime[j]]=-mu[i];
		}
	}for(int i=1;i<=mx;i++)s[i]=s[i-1]+mu[i];
	int n;scanf("%d",&n);
	while(n--){
		int a,b,c,d,k;scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("%lld\n",calc(b,d,k)+calc(a-1,c-1,k)-calc(b,c-1,k)-calc(a-1,d,k));
	}
	return 0;
}
