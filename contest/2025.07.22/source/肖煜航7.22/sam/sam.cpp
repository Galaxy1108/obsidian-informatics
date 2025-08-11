#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll mod=1e9+7;
struct mat{
	ll a[11][11];
	int n,m;
	mat(){
		n=m=0;
		memset(a,0,sizeof a);
	}
};
mat operator *(mat x,mat y){
	mat z;
	z.n=x.n,z.m=y.m;
	for(int i=1;i<=z.n;i++){
		for(int j=1;j<=z.m;j++){
			for(int k=1;k<=x.m;k++){
				z.a[i][j]=(z.a[i][j]+1ll*x.a[i][k]*y.a[k][j]%mod)%mod;
			}
		}
	}
	return z;
}
mat qpow(mat x,ll y){
	x.n=x.m=10;
	mat ans;
	ans.n=ans.m=10;
	for(int i=1;i<=10;i++) ans.a[i][i]=1;
	while(y){
		if(y&1) ans=ans*x;
		y>>=1;
		x=x*x;
	}
	return ans;
}
int main(){
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	mat op;
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(abs(i-j)<=2){
				op.a[i+1][j+1]=1;
			}
		}
	}
	ll k;scanf("%lld",&k);
	op.n=op.m=10;
	k--;
	mat ans;
	ans.n=1,ans.m=10;
	for(int i=2;i<=10;i++) ans.a[1][i]=1;
	if(k){
		ans=ans*qpow(op,k);
	}
	ll sum=0;
	for(int i=1;i<=10;i++) sum=(sum+ans.a[1][i])%mod;
	printf("%lld",sum);
	return 0;
}
