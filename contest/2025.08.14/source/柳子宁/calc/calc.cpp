#include<bits/stdc++.h>
using namespace std;
int n;
long long p,B;
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	scanf("%d%lld",&n,&p);
	for(int i=1;i<=n;++i){
		scanf("%lld",&B);
		if(B%p==0) {printf("-1\n");continue;}
		if(p==2&&B%2==1) {printf("1\n");continue;}
		if(p==3&&B%3==2) {printf("2\n");continue;}
		printf("-1\n");
	}
	return 0;
}
