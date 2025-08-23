#include<bits/stdc++.h>
#define int long long
#define N 3999
using namespace std;
mt19937 rnd(time(0));
int Rand(int l,int r){
	return rnd()%(r-l+1)+l;
}
main(){
	freopen("treeq.in","w",stdout);
	int n=N;
	cout<<n<<"\n";
	for(int i=2;i<=n;i++){
		cout<<1<<" "<<1<<"\n";
	}
	return 0;
}
