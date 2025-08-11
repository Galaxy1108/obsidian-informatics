#include <cstdio>
#include <cstring>
using namespace std;
int min(int a,int b){
	return a<b?a:b;
}
int b[10000][1001];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n,i=1,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&b[0][i]);
	for(;;i++){
		int tmp1=0,tmp2=n>>1,tp=0,flg=1;
		while(tmp1<(n>>1)&&tmp2<n){
			if(b[i-1][tmp1]<b[i-1][tmp2]) b[i][tp++]=b[i-1][tmp1++];
			else b[i][tp++]=b[i-1][tmp2++];
		}
		if(tmp1<(n>>1)) while(tp<n) b[i][tp++]=b[i-1][tmp1++];
		if(tmp2<n) while(tp<n) b[i][tp++]=b[i-1][tmp2++];
		for(int j=0;j<n;j++){
			if(b[i][j]!=b[i-1][j]){
				flg=0;
				break;
			}
		}
		if(flg) break;
//		for(int j=0;j<n;j++){
//			printf("%d ",b[i][j]);
//		}
//		printf("\n");
	}
	while(m--){
		int t,i_;
		scanf("%d%d",&t,&i_);
		if(t>i) printf("%d\n",b[i][i_-1]);
		else printf("%d\n",b[t][i_-1]);
	}
}
