#include<bits/stdc++.h>
using namespace std;
int n,a[200010];
long long V1[200010],V2[200010];
long long ans,sum1[200010],sum2[200010],sum3[200010];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		sum1[i]=sum1[i-1]+a[i];
		sum2[i]=sum2[i-1]+(a[i]&1);
		if(a[i]==0) sum2[i]+=2;
		sum3[i]=sum3[i-1]+(a[i]%2==0);
	}
	ans=sum1[n];
	
	long long mn=0;
	for(int l=1;l<=n;++l){
		V1[l]=sum2[l-1]+mn;
		mn=min(mn,-sum2[l]+sum1[l]);
		ans=min(ans,sum1[n]-sum1[l]+V1[l]);
	}
	
	mn=1e18;
	for(int r=n;r>=1;--r){
		mn=min(mn,sum2[r]-sum1[r]);
		V2[r]=sum1[n]-sum2[r]+mn;
	}
	
	mn=1e18;
	for(int l=n;l>=1;--l){
		mn=min(mn,V2[l]+sum3[l]);
		ans=min(ans,V1[l]-sum3[l-1]+mn);
	}
	printf("%lld\n",ans);
	return 0;
} 
