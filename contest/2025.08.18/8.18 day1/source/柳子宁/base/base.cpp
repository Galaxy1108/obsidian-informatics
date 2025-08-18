#include<bits/stdc++.h>
using namespace std;
int n;
long long a[2010],b[2010],suma[2010],sumb[2010];
long long mn[2010][2010],ans;
int main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<=n;++i) scanf("%lld",&b[i]);
	for(int i=1;i<=n;++i) suma[i]=suma[i-1]+a[i];
	for(int i=1;i<=n;++i) sumb[i]=sumb[i-1]+b[i];
	for(int i=n;i>=1;--i){
		for(int j=i;j<=n;++j){
			mn[i][j]=suma[j]-suma[i-1];
			if(i<j){
				mn[i][j]=min(mn[i][j],mn[i+1][j]);
				mn[i][j]=min(mn[i][j],mn[i][j-1]);
			}
		}
	}
	ans=-1e18;
	for(int i=1;i<=n;++i){
		for(int j=i+2;j<=n;++j){
			ans=max(ans,sumb[j]-sumb[i-1]-mn[i+1][j-1]+suma[j]-suma[i-1]);
		}
	}
	printf("%lld\n",ans);
	return 0;
}
