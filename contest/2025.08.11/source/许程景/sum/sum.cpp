#include<cstdio>
using namespace std;
int main(){
	freopen("sum.in", "r", stdin);
	freopen("sum.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int A,K;
		scanf("%d%d",&A,&K);
		if(K>(A>>1)) printf("%d\n",-1);
		else printf("%d\n",K<<1);
	}
}