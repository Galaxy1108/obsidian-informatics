#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("elevator.in","w",stdout);
	std::mt19937 rng(time(0));
	int n=rng()%50+2;
	printf("%d\n",n);
	for(int i=1,a,b;i<=n;++i){
		a=rng()%9+1;
		b=rng()%9+1;
		while(a==b) b=rng()%9+1;
		printf("%d %d\n",a,b);
	}
	while(clock()<500);
	return 0;
}
