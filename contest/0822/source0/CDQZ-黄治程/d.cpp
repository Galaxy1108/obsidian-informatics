#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int x[N];
bool chk(int a,int b,int c,int l,int r){
	for(int i=l,j=0;i<=r;i++,j++){
		if(x[i]!=(a*j+b)/c){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int t,n,q,l,r,vis;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		vis=1;
		for(int i=3;i<=n;i++){
			if(x[i]-x[i-1]!=x[i-1]-x[i-2]){
				vis=0;
			}
		}
		scanf("%d",&q);
		while(q--){
			scanf("%d%d",&l,&r);
			if(vis){
				printf("%d %d %d\n",x[2]-x[1],x[l],1);
				continue;
			}
			for(int c=1;c<=10;c++){
				for(int a=0;a<=10;a++){
					for(int b=0;b<=10;b++){
						if(chk(a,b,c,l,r)){
							printf("%d %d %d\n",a,b,c);
							goto lass;
						}
					}
				}
			}
			printf("0 0 0\n");
			lass:;
		}
	}
}