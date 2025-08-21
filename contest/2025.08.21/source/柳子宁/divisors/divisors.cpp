#include<bits/stdc++.h>
using namespace std;
int n;
int f1,f2;
int val[10010];
int main()
{
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	scanf("%d",&n);
	f1=2,f2=n;
	for(int i=1;i<=n;++i) val[i]=1;
	for(int i=1;i<n;++i){
		if(i&1){
			val[i]*=f2;
			val[i+1]*=f2;
			--f2;
		}
		else{
			val[i]*=f1;
			val[i+1]*=f1;
			++f1;
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",val[i]);
	printf("\n");
	for(int i=1;i<n;++i) printf("%d %d\n",i,i+1);
	return 0;
} 
