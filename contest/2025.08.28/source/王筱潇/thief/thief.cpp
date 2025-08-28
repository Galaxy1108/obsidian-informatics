#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[500010];
int main(){
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int l,r,c;
	while(m--){
		scanf("%d%d%d",&l,&r,&c);
		for(int i=l;i<=r;i++){
			if(c>a[i]) c--;
			else if(c<a[i]) c++;
		}
		printf("%d\n",c);
	}
}
