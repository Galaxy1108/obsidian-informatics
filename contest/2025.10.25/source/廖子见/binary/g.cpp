#include<bits/stdc++.h>
#define int long long
using namespace std;
mt19937 rnd(time(0));
main(){
	freopen("binary.in","w",stdout);
	int n=5,m=100;
	cout<<n<<"\n";
	for(int i=1;i<=n;i++)cout<<rnd()%2<<" ";
	cout<<"\n"<<m<<"\n";
	for(int i=1;i<=m;i++){
		int l=rnd()%n+1,r=rnd()%(n-l+1)+l;
		cout<<2<<" "<<l<<" "<<r<<"\n";
	}
	return 0;
}
