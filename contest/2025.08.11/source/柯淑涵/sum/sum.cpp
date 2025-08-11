#include <bits/stdc++.h>
using namespace std;
long long T,n,m; 
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m;
		if(n%2==1){
			if(2*m>n) cout<<"-1"<<endl;
			else cout<<2*m<<endl;
			
		} 
		else cout<<"-1"<<endl;
	}
	return 0;
}

