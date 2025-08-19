#include <bits/stdc++.h>
using namespace std;
#define V 25
#define MOD 1000000007
int n,base[V];
int pr[V]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
long long p2(long long p){
	long long res=1,base=2;
	while(p){
		if(p&1)res=res*base%MOD;
		p>>=1;
		base=base*base%MOD;
	}
	return res;
}
int main(){
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	scanf("%d",&n);
	int a,v,c;
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		v=0;
		for(int j=0;j<19;j++){
			c=0;
			while(a%pr[j]==0){
				c^=1;
				a/=pr[j];
			}
			v=v<<1|c;
		}
		for(int j=18;j>=0;j--){
			if((v>>j)&1){
				if(base[j]==0){
					base[j]=v;
					break;
				}
				else{
					v^=base[j];
				}
			}
		}
	}
	for(int i=0;i<19;i++){
		if(base[i]!=0)n--;
	}
	printf("%lld",(p2(n)-1ll+MOD)%MOD);
	return 0;
}
