#include<iostream>
#include<cmath>
using namespace std;
long long n,m,p,tmp;
long long qpow(long long x){
	long long a=2,res=1;
	while(x){
		if(x%2==1)res*=a;
		a*=a;
		a%=p;
		res%=p;
		x/=2;
	} 
	return res;
}
int main(){
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);	
	cin >> n >> m >> p;
	if(n==1){
		tmp=qpow(1+m);
		cout << tmp%p;
	}
	else if(n<m){
		tmp=qpow(n+m);
		cout << tmp%p;
	}
	else{
		tmp=qpow(2*m);
		cout << tmp%p;
	}
	return 0;
} 
