#include <bits/stdc++.h>
using namespace std;
int n;
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
long long lcm(long long a,long long b){
	return (__int128)a*b/gcd(a,b);
}
int main(){
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	long long l=1;
	for(int i=1;i<=n;i++){
		l=lcm(l,i);
	}
	cout<<l<<' ';
	for(int i=2;i<=n;i++){
		cout<<i<<' ';
	}
	cout<<'\n';
	for(int i=2;i<=n;i++){
		cout<<1<<" "<<i<<'\n';
	}
	return 0;
}

