#include<bits/stdc++.h>
using namespace std;
int T;
long long S,K;
int main()
{
	freopen("sum1.in","r",stdin);
	freopen("sum.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld",&S,&K);
		if(K>(S-1)/2) printf("-1\n"); 
		else printf("%lld\n",K<<1);
	}
	
	return 0;
}
