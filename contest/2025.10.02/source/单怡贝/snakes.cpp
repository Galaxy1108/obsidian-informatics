#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXn (int)1e6+1
using namespace std;
int T;
int n,l=1,t,a[MAXn],b[MAXn];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);T--;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	if(n==3){
		if(b[3]-b[1]<b[2]) cout<<3<<endl;
		else cout<<1<<endl;
		while(T--){
			int k,x,y;
			scanf("%d",&k);
			for(int i=1; i<=k; i++){
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
			for(int i=1; i<=n; i++) b[i]=a[i];
			sort(b+1,b+4);
			if(b[3]-b[1]<b[2]) cout<<3<<endl;
			else cout<<1<<endl;
		}
	}
	return 0;
}
