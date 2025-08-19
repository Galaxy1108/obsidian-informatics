#include<bits/stdc++.h>
#define N 5
#define M 1
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
		cout<<Rand(1,21)<<" "<<Rand(1,20)<<" "<<sum<<"\n";
		sum+=Rand(1,M);
	}
	return 0;
}
