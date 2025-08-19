//#include<bits/stdc++.h>
#include<algorithm> 
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
typedef __int128 lll;
typedef long long ll; 
constexpr const int N=1e5,V=70,VPrime=19,P=1e9+7;
int n,a[N+1];
int qpow(int base,int n){
	int ans=1;
	while(n){
		if(n&1){
			ans=(ll)ans*base%P;
		}
		base=(ll)base*base%P;
		n>>=1;
	}
	return ans;
}
template<typename T>
bool isPrime(T n){
	if(n<=1){
		return false;
	}
	for(T i=2;i*i<=n;i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}
namespace judge1{
	bool is(){
		return false;
		return n<=20;
	}
	int ans=0,x[N+1];
	void dfs(int p){
		if(p>n){
			lll pl=1;
			for(int i=1;i<=n;i++){
				pl*=x[i];
			}
			lll sqrtPl=sqrt((double)pl);
			if(sqrtPl*sqrtPl==pl){
				ans++;
			}
			return;
		}
		x[p]=1;
		dfs(p+1);
		x[p]=a[p];
		dfs(p+1);
	}
	int main(){
		dfs(1);
		cout<<ans-1<<'\n';
		return 0;
	}
}
namespace judge2{
	bool is(){
		for(int i=1;i<=n;i++){
			if((a[i]&-a[i])!=a[i]){
				return false;
			}
		}
		return true;
	}
	//a[1]~a[i]中和为 偶数/奇数 
	int dp[N+1][2];
	int main(){
		for(int i=1;i<=n;i++){
			a[i]=__lg(a[i]);
		}
		dp[0][0]=1; 
		for(int i=1;i<=n;i++){
			if(a[i]&1){
				dp[i][0]=(dp[i-1][1]+dp[i-1][0])%P;
				dp[i][1]=(dp[i-1][0]+dp[i-1][1])%P;
			}else{
				dp[i][0]=dp[i-1][0]*2%P;
				dp[i][1]=dp[i-1][1]*2%P;
			}
		}
		int ans=dp[n][0]-1;
		if(ans<=0){
			ans+=P;
		}
		cout<<dp[n][0]-1<<'\n';
		return 0;
	}
}
namespace judge3{
	int cnt[VPrime+1],rank[V+1],prime[V+1],size;
	int fact[N+1];
	void pre(){
		for(int i=1;i<=V;i++){
			if(isPrime(i)){
				rank[i]=rank[prime[size]]+1;
				prime[++size]=i;
			}
		}
		for(int i=1;i<=n;i++){
			cnt[rank[a[i]]]++;
		}
		fact[0]=1;
		for(int i=1;i<=N;i++){
			fact[i]=(ll)fact[i-1]*i%P;
		}
	}
	bool is(){
		for(int i=1;i<=n;i++){
			if(!isPrime(a[i])){
				return false;
			}
		}
		return true;
	}
	int C(int n,int m){
		if(n<0||m<0||n<m){
			return false;
		}
		return (ll)fact[n]*qpow((ll)fact[m]*fact[n-m]%P,P-2)%P;
	}
	int main(){
		pre();
		bool noAns=true;
		for(int i=1;i<=size;i++){
			if(cnt[i]>=2){
				noAns=false;
			}
		} 
		if(noAns){
			cout<<"0\n";
			return 0;
		}
		int ans=1;
		for(int i=1;i<=size;i++){
			int pl=0;
			for(int j=0;(j<<1)<=cnt[i];j++){
				pl=((ll)pl+C(cnt[i],j<<1))%P; 
			}
			ans=(ll)ans*pl%P;
		}
		ans=(ans-1)%P;
		if(ans<0){
			ans+=P;
		}
		cout<<ans<<'\n';
		return 0;
	}
}
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(judge1::is()){
		judge1::main();
	}else if(judge2::is()){
		judge2::main();
	}else{
		judge3::main();
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 
3 3 5 5

3 
*/
