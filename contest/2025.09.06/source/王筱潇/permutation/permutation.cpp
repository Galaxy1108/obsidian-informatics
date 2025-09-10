#include <bits/stdc++.h>
using namespace std;
int ans[100010],h[100010],pn[100010],p[100010],q[100010],n,qn[100010],f[100010];
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d",&n);
	if(n==2) printf("NO");
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&q[i]);
	for(int i=1;i<=n;i++) pn[p[i]]=i;
	for(int i=1;i<=n;i++) qn[q[i]]=i;
	for(int i=1;i<=n;i++){
		h[qn[i]]=i;
		f[i]=1;
		int flag=i,cnt=1;
		flag=qn[flag];
		while(f[flag]==0){
			h[flag]=pn[h[q[i]]];
			f[flag]=1;
			flag=qn[flag];
			cnt++;
		}
		if(cnt==n-1){
			printf("YES");
			for(int i=1;i<=n;i++) printf("%d ",h[i]);
			return 0;
		}
	}
	printf("NO");
	return 0;
}  
