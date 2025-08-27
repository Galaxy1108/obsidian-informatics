#include<bits/stdc++.h>
using namespace std;
const int N=2e4+5,M=2300;
typedef long long ll;
typedef __int128 LL;
bool st;
int isp[N],prime[M],tot;
int n,mod;
ll p1[M][N],p2[M][N];
bool ed;
ll qpow(int id,int v){
	return (LL)p1[id][v%10000]*p2[id][v/10000]%(1ll*mod*(prime[id]-1));
}
inline int calc1(int x,int k){
	if(x<k)return 0;x-=k-1;
	return (x%k)*((x+k-1)/k)+k*(x/k)*(x/k+1)/2;
}
int calc(int x){
	int res=1;
	for(int i=1;i<=tot;i++)if(prime[i]<=x){
		int cnt=0;int now=prime[i];
		while(now<=n){
			cnt+=(x+1)*(x/now);
			cnt-=2*calc1(x,now);
			now*=prime[i];
		}
		ll w=(qpow(i,cnt+1)-1)/(prime[i]-1);
		res=res*w%mod;
	}else break;
	return res;
}
int main(){
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	scanf("%d%d",&n,&mod);
	for(int i=2;i<N;i++){
		if(!isp[i])prime[++tot]=i;
		for(int j=1;j<=tot&&i*prime[j]<N;j++){
			isp[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		}
	}
	for(int i=1;i<=tot;i++){
		ll m1=1ll*mod*(prime[i]-1);
		p1[i][0]=1;
		for(int j=1;j<=10000;j++)p1[i][j]=1ll*p1[i][j-1]*prime[i]%m1;
		p2[i][0]=1;
		for(int j=1;j<=10000;j++)p2[i][j]=(LL)p1[i][10000]*p2[i][j-1]%m1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=(ans+calc(i))%mod;
	printf("%d\n",ans);
	return 0;
}
