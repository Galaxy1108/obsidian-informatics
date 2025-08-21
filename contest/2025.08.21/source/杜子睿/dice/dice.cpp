#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
int n;
long long q,p,k,cnt,a[5005];
long long pow(long long x,long long y){
	long long res=1;
	while(y){
		if(y&1)	
			res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	} 
	return res;
}
int main(){
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)	
		cin>>a[i];
	sort(a,a+n); 
	cnt=n;
	k=1;
	for(long long i=1;i<=a[n-1];i++){
		long long add;
		add=pow(i,cnt)+mod-pow(i-1,cnt);
		add=add%mod;
		add=add*k;
		add=add%mod;
		p+=add;
		p=p%mod;
		add=add*i;
		add=add%mod;
		q+=add;
		q=q%mod;
		while(i!=a[n-1]&&a[n-cnt]==i){
			k=k*a[n-cnt]; 
			k=k%mod;
			cnt--;
		}
	}
	cout<<q*pow(p,mod-2)%mod;
	return 0;
}

