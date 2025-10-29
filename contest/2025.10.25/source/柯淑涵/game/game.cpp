#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000001];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n%2==1){
		cout<<n<<endl;
	}
	else{
		cout<<0<<endl; 
	}
	return 0;
} 
