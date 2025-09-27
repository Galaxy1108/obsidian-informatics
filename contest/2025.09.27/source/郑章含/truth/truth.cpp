#include<bits/stdc++.h>
using namespace std;
int n,k,m,opt,a[50010];
int cnt,num[50];
int sovle(){
	int l=1,r=0,ans;
	cnt=0;
	memset(num,0,sizeof(num));
	while(cnt!=k&&r<n){
		if(num[a[++r]]==0) cnt++;
		num[a[r]]++;
	}
	if(cnt<k) return -1;
	ans=r-l+1;
	for(l=2;l<=n;l++){
		if(num[a[l-1]]==1) cnt--;
		num[a[l-1]]--;
		while(cnt!=k&&r<n){
			if(num[a[++r]]==0) cnt++;
			num[a[r]]++;
		}
		if(cnt!=k) break;
		ans=min(ans,r-l+1);
	}
	return ans;
}
int main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&opt);
		if(opt==2) printf("%d\n",sovle());
		if(opt==1){
			int p,v;
			scanf("%d%d",&p,&v);
			a[p]=v;
		}
	}
	return 0;
}
