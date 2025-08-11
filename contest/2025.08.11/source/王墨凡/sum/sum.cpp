#include<iostream>
using namespace std;
long long s,t,k,q;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin >> q;
	while(q--){
		cin >> s >> k;
		if(k*2>s)cout << -1 << endl;
		else cout << k*2 << endl;
	}
	return 0;
}
