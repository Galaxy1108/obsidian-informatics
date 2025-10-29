#include<bits/stdc++.h>
using namespace std;
int n,mod,book[15],a[15],b[3628805],cnt,num;
long long f[3628805],ans;
void dfs(int x){
	if(x==n+1){
		num=0;
		for(int i(1);i<n;++i)for(int j(i+1);j<=n;++j)if(a[i]>a[j])num++;
		b[++cnt]=num;
		return;
	}
	for(int i(1);i<=n;++i){
		if(!book[i]){
			book[i]=1;
			a[x]=i;
			dfs(x+1);
			book[i]=0;
		}
	}
	return;
}
int main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	scanf("%d%d",&n,&mod);
	dfs(1);
	for(int i(2);i<=cnt;++i)for(int j(i-1);j>=1;--j)if(b[j]>b[i])f[i]++;
	for(int i(2);i<=cnt;++i)ans+=f[i];
	printf("%d",ans%mod);
	return 0;
}
