#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod=998244353;
int mul[1000],inv[1000];
signed xx[501][501];
int n,x,ans;
int ksm(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=ret*x%mod;
		x=x*x%mod;y>>=1;
	}return ret;
}
int C(int m,int n){
	return mul[n]*inv[m]%mod*inv[n-m]%mod;
}
int work(int x,int r){
	#define l 1ll
	if(xx[x][r]!=-1)return xx[x][r];
	if(x==2)return r-l+1;
	int ttfa=0;
	for(int j=(x-1)*((l-1)/(x-1)+1);j<=r+x-1;j+=x-1)ttfa+=ksm(min(r,j)-max(l,j-x+2)+1,x),ttfa%=mod;
	for(int i=2;i<x;i++){
		for(int j=(l-1)/(x-1)+1;j*(x-1)<r;j++){
			ttfa=(ttfa+ksm(j*(x-1)-max(l,(j-1)*(x-1)+1)+1,x-i)*C(i,x)%mod*work(i,r-j*(x-1))%mod)%mod;
		}
	}
	return xx[x][r]=ttfa;
	#undef l
}
//I is sb
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	mul[0]=1;
	memset(xx,-1,sizeof(xx));
	for(int i=1;i<1000;i++)mul[i]=mul[i-1]*i%mod,inv[i]=ksm(mul[i],mod-2);
	scanf("%lld%lld",&n,&x);
	cout<<work(n,x)<<endl;
	return 0;
} 
