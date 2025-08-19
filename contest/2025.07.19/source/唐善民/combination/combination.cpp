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
constexpr const int M=1000;
int n,x,P,m,a[M+1];
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
	constexpr const int N=1000; 
	bool is(){
		return n<=1000&&m<=1000;
	}
	int f(int x){
		int ans=0;
		for(int i=0,x0=1;i<=m;i++,x0=(ll)x0*x%P){
			ans=(ans+(ll)a[i]*x0%P)%P;
		}
		return ans;
	}
	int C(int n,int m){
		if(n<0||m<0||n<m){
			return 0;
		}
		if(!m){
			return 1;
		}
		static int mem[N+1][M+1];
		if(mem[n][m]){
			return mem[n][m];
		}
		return mem[n][m]=(C(n-1,m)+C(n-1,m-1))%P;
	}
	int main(){
		int ans=0;
		for(int k=0,x0=1;k<=n;k++,x0=(ll)x0*x%P){
			ans=(ans+(ll)f(k)*x0%P*C(n,k)%P)%P;
		}
		if(ans<0){
			ans+=P;
		}
		cout<<ans<<'\n';
		return 0;
	}
}
namespace judge2{
	constexpr const int N=1e5,M=0;
	bool zs(int n){
		if(n<=1){
			return false;
		}
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				return false;
			}
		}
		return true;
	}
	bool is(){
		return n<=1e5&&m<=0&&zs(P);
	} 
	int f(int x){
		int ans=0;
		for(int i=0,x0=1;i<=m;i++,x0=(ll)x0*x%P){
			ans=(ans+(ll)a[i]*x0%P)%P;
		}
		return ans;
	}
	int C(int n,int m){
		if(n<0||m<0||n<m){
			return 0;
		}
		if(!m){
			return 1;
		}
		static int mem[N+1][M+1];
		if(mem[n][m]){
			return mem[n][m];
		}
		return mem[n][m]=(C(n-1,m)+C(n-1,m-1))%P;
	}
	int main(){
		int ans=0;
			for(int k=0,x0=1;k<=n;k++,x0=(ll)x0*x%P){
				ans=(ans+(ll)f(k)*x0%P*C(n,k)%P)%P;
			}
			if(ans<0){
				ans+=P;
			}
			cout<<ans<<'\n';
		return 0;
	}
}
namespace judge3{
	bool is(){
		return !m;
	} 
	int main(){
		cout<<(ll)a[0]*qpow(1+x,n)%P<<'\n';
	}
}
int main(){
	freopen("combination.in","r",stdin);
	freopen("combination.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>x>>P>>m;
	for(int i=0;i<=m;i++){
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
12 23 998244353 0
89

468514596
*/
