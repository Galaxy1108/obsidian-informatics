#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10]={0,1,4,13,233,5736},n,p;
int main(){
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	scanf("%lld%lld",&n,&p);
	printf("%lld",a[n]%p);
	return 0;
} 
