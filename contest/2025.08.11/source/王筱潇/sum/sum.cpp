#include<bits/stdc++.h>
using namespace std;
long long s,k;
int main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&s,&k);
		if(s/2<k){
			printf("-1\n");
			continue;
		}
		else if(s%2==1){
			printf("%lld\n",k*2);
			continue;
		}
		else{
			printf("%lld\n",s-k);
			continue;
		}
	}
	return 0; 
} 
