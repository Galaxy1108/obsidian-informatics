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
constexpr const int V=10,P=1e9+7;
ll n;
namespace judge1{
	/*
	bool check(ll x){
		while(x>=10){
			int p=x%10;
			x/=10;
			int q=x%10;
			if(abs(p-q)>2){
				return false;
			}
		}
		return true;
	}
	int f(int k){
		ll s=pow(10,k-1),t=s*10;
		int ans=0;
		for(ll i=s;i<t;i++){
			ans=(ans+check(i))%P;
		}
		return ans;
	}
	*/
}
namespace judge2{
	/*
	constexpr const int N=1e6;
	int dp[N+1][V+1];
	int main(){
		for(int i=0;i<=V;i++){
			dp[1][i]=1;
		}
		for(int i=2;i<=n;i++){
			dp[i][0]=(1ll*dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%P;
			dp[i][1]=(1ll*dp[i-1][0]+dp[i-1][1]+dp[i-1][2]+dp[i-1][3])%P;
			for(int j=2;j<=V-2;j++){
				dp[i][j]=(1ll*dp[i-1][j-2]+dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1]+dp[i-1][j+2])%P;
			}
			dp[i][V-1]=(1ll*dp[i-1][V-3]+dp[i-1][V-2]+dp[i-1][V-1]+dp[i-1][V])%P;
			dp[i][V]=(1ll*dp[i-1][V-2]+dp[i-1][V-1]+dp[i-1][V])%P;
		}
		int ans=0;
		for(int i=1;i<=V;i++){
			ans=(ans+dp[n][i])%P;
		}
		cout<<ans<<'\n';
		return 0; 
	}
	*/
}
namespace judge3{
	//n 行 m 列 
	struct Matrix{
		int n,m;
		//下标从 1 开始. 
		int a[V+1][V+1];
		Matrix(){
			memset(a,0,sizeof(a));
		}
		Matrix(int nn,int mm=-1){
			memset(a,0,sizeof(a));
			n=nn;m=mm;
			if(m==-1){
				m=n;
			}
		}
		void print(){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cerr<<a[i][j]<<' ';
				}
				cerr<<endl;
			}
		}
	};
	Matrix operator *(Matrix A,Matrix B){
		Matrix C(A.n,B.m);
		for(int i=1;i<=A.n;i++){
			for(int j=1;j<=B.m;j++){
				for(int k=1;k<=A.m;k++){
					C.a[i][j]=(C.a[i][j]+1ll*A.a[i][k]*B.a[k][j])%P;
				}
			}
		}
		return C;
	}
	Matrix qpow(Matrix base,ll n){
		Matrix ans(base.n);
		for(int i=1;i<=base.n;i++){
			ans.a[i][i]=1;
		}
		while(n){
			if(n&1){
				ans=ans*base;
			}
			base=base*base;
			n>>=1;
		}
		return ans;
	}
	int main(){
		Matrix A(V,V);
		for(int i=1;i<=V;i++){
			for(int j=max(i-2,1);j<=min(i+2,V);j++){
				A.a[i][j]=1;
			}
		}
		A=qpow(A,n-1);
		Matrix B(V,1);
		for(int i=1;i<=V;i++){
			B.a[i][1]=1;
		}
		B=A*B;
		int ans=0;
		for(int i=2;i<=V;i++){
			ans=(ans+B.a[i][1])%P;
		}
		cout<<ans<<'\n';
		return 0;
	}
} 
int main(){
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	judge3::main();
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
