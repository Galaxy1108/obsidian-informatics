#include<bits/stdc++.h>
using namespace std;
long long t,s,k;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>s>>k;
		if((k*2>s)||k>5e17){
			cout<<-1<<endl;
			continue;
		}
		else 
			cout<<2*k<<endl;
	}
	return 0;
}

