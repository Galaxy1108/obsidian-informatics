#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,d,k,cntp;
int prime[1000010],mu[1000010],flag[1000010],smu[1000010];
void Init(){
	int N=1000000;
	mu[1]=1;
	for(int i=2;i<=N;++i){
		if(!flag[i]) flag[i]=i,mu[i]=-1,prime[++cntp]=i;
		for(int j=1;j<=cntp&&i*prime[j]<=N;++j){
			flag[i*prime[j]]=prime[j];
			if(i%prime[j]==0) {mu[i*prime[j]]=0;break;}
			else mu[i*prime[j]]=-mu[i];
		}
	}
	for(int i=1;i<=N;++i) smu[i]=smu[i-1]+mu[i];
}
long long w(int a,int b){
	int m=min(a,b);
	long long ans=0;
	for(int d=1;d<=m;){
		int r=min(a/(a/d),b/(b/d));
		ans+=1ll*(smu[r]-smu[d-1])*(a/d)*(b/d);
		d=r+1;
	}
	return ans;
} 
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	Init(); 
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		printf("%lld\n",w(b/k,d/k)-w(b/k,(c-1)/k)-w((a-1)/k,d/k)+w((a-1)/k,(c-1)/k));
	}
	return 0;
}
