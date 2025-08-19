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
typedef long long ll;
constexpr const int N=1e6,K=100,P=998244353;
int n,k; 
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
namespace judge1{
	constexpr const int N=10,K=5;
	bool is(){
		return n<=10&&k<=5;
	}
	int gcd(int a,int b){
		while(b){
			int tmp=a;
			a=b;
			b=tmp%b;
		}
		return a;
	}
	int lcm(int n,int m){
		return (ll)n/gcd(n,m)*m%P;
	}
	int ans=1;
	int x[K+1]; 
	void dfs(int p){
		if(p>k){
			int pl=1;
			for(int i=1;i<=k;i++){
				pl=lcm(pl,x[i]);
			}
			ans=(ll)ans*pl%P;
			return;
		}
		for(x[p]=1;x[p]<=n;x[p]++){
			dfs(p+1); 
		} 
	} 
	int main(){
		ans=1;
		dfs(1);
		cout<<ans<<'\n';
	}
}
namespace judge2{
	bool is(){
		return k<=2;
	}
	int mu[N+1],fact[N+1];
	void pre(){
		mu[1]=1;
		static bool vis[N+1];
		static int size,prime[N+1];
		for(int i=2;i<=N;i++){
			if(!vis[i]){
				mu[i]=-1;
				prime[++size]=i;
				vis[i]=i;
			}
			for(int j=1;j<=size&&i*prime[j]<=N;j++){
				vis[i*prime[j]]=prime[j];
				if(i%prime[j]==0){
					break;
				}
				mu[i*prime[j]]=-mu[i];
			}
		}
		fact[0]=1;
		for(int i=1;i<=N;i++){
			fact[i]=(ll)fact[i-1]*i%P;
		}
	}
	int main(){
		int ans=0;
		for(int d=1;d<=n;d++){
			int pl=0;
			for(int t=1;d*t<=n;t++){
				int tn=n/d/t;
				pl=(pl+(ll)mu[t]*qpow(fact[tn],tn<<1)%P)%P;
			}
			ans=(ans+(ll)d*pl%P)%P;
		}
		cout<<ans<<'\n';
		return 0;
	}
}
int main(){
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	judge2::pre();
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		if(judge1::is()){
			judge1::main();
		}else{
			judge2::main();
		}
	}
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
1
2 2

8 
*/ 
