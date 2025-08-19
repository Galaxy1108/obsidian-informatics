#include<bits/stdc++.h>
using namespace std;
int n,x[1000010],p[1000010],c[1000010],f[1000010],sum[1000010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x[i],&p[i],&c[i]);
		sum[i]=sum[i-1]+p[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			f[i]=max(f[i],f[j]+x[i]*(p[i]-p[j])-(sum[i]-sum[j])+c[i]);
		}
	}
	printf("%d",f[n]);
	return 0;
} 
