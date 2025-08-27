#include<bits/stdc++.h>
using namespace std;
long long num,n,x,inv[100005],p[100005];
const int mod=998244353;
long long power(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1)
			res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
void init(){
	inv[1]=1;
	inv[0]=1;
	p[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=inv[i-1]*power(i,mod-2)%mod;
		p[i]=p[i-1]*i%mod;
	}
}
long long c(int x,int y){
	return p[x]*inv[x-y]%mod*inv[y]%mod;
}
int main(){
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	cin>>num>>n>>x;
	init();
	if(num==1){
		cout<<n<<" ";
		for(int i=2;i<=n;i++)
			cout<<"0 ";
	}
	if(num==5){
		long long res=1;
		cout<<n<<" ";
		for(long long i=2;i<=n;i++){
			long long ans=0;
			if(x+1<i)
				cout<<"0 ";
			else{
				for(int j=1;j<=n-i+1;j++)
					ans=(ans+c(min(x,n-j),i-1))%mod;
				cout<<ans<<" ";
			}
		} 
	} 
	return 0;
}
