#include <bits/stdc++.h>
using namespace std;
constexpr int N=5005;
constexpr long long MOD=1000000007;
int n;
int a[N];
long long pr[N];
long long mpow(long long base,long long p){
	long long res=1;
	while(p){
		if(p&1)res=res*base%MOD;
		p>>=1;
		base=base*base%MOD;
	}
	return res;
}
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	pr[0]=1;
	for(int i=1;i<=n;i++){
		pr[i]=pr[i-1]*a[i]%MOD;
	}
	int cnt=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cnt++;
		if(i==n||a[i]!=a[i+1]){
			//有n-i+cnt个骰子可以达到a[i-cnt]+1~a[i]的值 
			//其他1~i-cnt个骰子<=a[i-cnt]
			static long long sum;
			sum=0;
			for(long long k=a[i-cnt]+1;k<=a[i];k++){
				sum=(sum+k*(mpow(k,n-i+cnt)-mpow(k-1,n-i+cnt)+MOD)%MOD)%MOD;
			}
			ans=(ans+pr[i-cnt]*sum%MOD)%MOD;
			cnt=0;
		}
	}
	ans=ans*mpow(pr[n],MOD-2ll)%MOD;
	cout<<ans;
	return 0;
}

