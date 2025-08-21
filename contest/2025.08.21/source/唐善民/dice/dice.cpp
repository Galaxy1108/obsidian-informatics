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
constexpr const int N=5000,P=1e9+7;
int n,all=1,a[N+1],pre[N+1];
int qpow(int base,int n){
	int ans=1;
	while(n){
		if(n&1){
			ans=1ll*ans*base%P;
		}
		base=1ll*base*base%P;
		n>>=1;
	}
	return ans;
}
int f(int x){
	int p=upper_bound(a+1,a+n+1,x)-a-1;
	return 1ll*pre[p]*qpow(x,n-p)%P;
}
namespace judge0{
	int qpow(int base,int n){
		base%=P;
		if(base<0){
			base+=P;
		}
		int ans=1;
		while(n){
			if(n&1){
				ans=1ll*ans*base%P;
			}
			base=1ll*base*base%P;
			n>>=1;
		}
		return ans;
	}
	bool is(){
		for(int i=2;i<=n;i++){
			if(a[i-1]!=a[i]){
				return false;
			}
		}
		return true;
	}
	int y[N+2+1];
	void pre(){
		for(int i=1;i<=n+2;i++){
			y[i]=(y[i-1]+qpow(i,n))%P;
		}
	}
	int f(int x){
		int ans=0;
		/*for(int i=1;i<=x;i++){
			ans=(ans+qpow(i,n))%P;
		}*/
		for(int i=1;i<=n+2;i++){
			int pl=y[i];
			for(int j=1;j<=n+2;j++){
				if(j==i){
					continue;
				}
				pl=1ll*pl*(x-j)%P*qpow(i-j,P-2)%P;
			}
			ans=(ans+pl)%P;
		}
		return ans;
	}
	int main(){
		pre();
		int ans=qpow(a[1],n+1);
		ans=(ans-f(a[1]-1))%P;
		ans=1ll*ans*qpow(all,P-2)%P;
		cout<<ans<<'\n';
		return 0;
	}
}
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		all=1ll*all*a[i]%P;
	}
	if(judge0::is()){
		judge0::main();
		return 0;
	}
	sort(a+1,a+n+1);
	pre[0]=1;
	for(int i=1;i<=n;i++){
		pre[i]=1ll*pre[i-1]*a[i]%P;
	}
	int ans=0;
	for(int i=1;i<=a[n];i++){
		int pl=(f(i)-f(i-1))%P;
		ans=(ans+1ll*pl*i)%P;
	}
	ans=1ll*ans*qpow(all,P-2)%P;
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
