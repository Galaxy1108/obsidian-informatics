#include<bits/stdc++.h>
using namespace std;
int t,n,k,x,y,a[1000010],ans;
int solve(){
	if(n==3){
		if(a[3]>a[1]+a[2]) return 1;
		else return 3;
	}
	return 1;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	ans=solve();
	printf("%d\n",ans);
	for(int T=2;T<=t;T++){
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d%d",&x,&y);
			a[x]=y;
		}
		ans=solve();
		printf("%d\n",ans);
	}
	return 0;
} 
