#include<bits/stdc++.h>
#define N 10000
#define V 1000
#define M 100
using namespace std;
mt19937 rnd;
int Rand(int l,int r){
	return rnd()%(r-l+1)+l;
}
main(){
	freopen("data.in","w",stdout);
	rnd.seed(time(0));
	int n=N,sum=0;
	cout<<n<<"\n";
	for(int i=1;i<=n;i++){
		cout<<sum<<" "<<Rand(1,V)<<" "<<Rand(1,V)<<"\n";
		sum+=Rand(1,M);
	}
	return 0;
}
