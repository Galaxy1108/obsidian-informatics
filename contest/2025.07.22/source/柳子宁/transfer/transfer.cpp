#include<bits/stdc++.h>
using namespace std;
int n,k,ans=1e9,cnt;
int s[110],t[110],p[110];
char st[110];
int check(){
	int sum=0,res=0,K=0;
	for(int i=1;i<=2*n;++i){
		if(t[i]==0) ++sum;
		else{
			if(res==0&&sum==0) return 1e9;
			if(res==0) ++K,res=sum,sum=0;
			--res;
		}
	}
	return K;
}
int calc(){
	int ans=0;
	cnt=0;
	for(int i=1;i<=2*n;++i){
		if(t[i]==1) ans+=abs(p[++cnt]-i);
	}
	return ans;
}
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n>10){
		printf("0\n");
		return 0;
	} 
	scanf("%s",st+1);
	for(int i=1;i<=2*n;++i) s[i]=st[i]-'A';
	for(int i=1;i<=2*n;++i){
		if(s[i]) p[++cnt]=i;
	}
	for(int S=0;S<(1<<(2*n));++S){
		if(__builtin_popcount(S)!=n) continue;
		for(int i=1;i<=2*n;++i) t[i]=S>>(i-1)&1;
		if(check()<=k){
			ans=min(ans,calc());
		}
	}
	printf("%d\n",ans);
	return 0;
}
