#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("find.in","w",stdout);
	std::mt19937 rng(time(0));
	long long n=rng();
	n*=121;
	if(n>1e12) n/=10;
	long long k=rng()%100000;
	printf("%lld %lld",n,k);
	while(clock()<500);
	return 0;
}
