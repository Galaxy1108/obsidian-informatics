#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int main(){
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	int n;
	cin >> n;
	if(n<=20){
		long long k=1;
		for(int i=1;i<=n;i++){
			ll res=0;
			res=i/gcd(k,i);
			k*=res;
		}
		cout << k << " ";
		for(int i=2;i<=n;i++){
			cout << i << " ";
		}
		cout << endl;
		for(int i=2;i<=n;i++){
			cout << 1 << " " << i << endl;
		}
		
	}
	return 0;
}
