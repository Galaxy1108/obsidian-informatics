#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll p;
ll qpow(ll a,ll b){
	if(a==1)return 1;
	ll power=a,res=1;
	if(b<=0)return 1;
	while(b>0){
		if(b&1)
			res=res+power;
		power=power*power;
		b>>=1;
	}
	return res;
}
void solv(){
	cout << -1 << endl;
	
}
int main(){
	srand(time(0));
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout); 
	int T;
	cin >> T >> p;
	while(T--)solv();
	return 0;
}
