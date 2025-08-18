#include <algorithm>
#include <cstdio>
using namespace std;
long long pref[4002],suff[4002];
long long mp[4001][2];
long long n;
int main(){
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++) scanf("%lld",&mp[i][0]),mp[i][0]+=mp[i-1][0];
	for(long long i=1;i<=n;i++) scanf("%lld",&mp[i][1]),mp[i][1]+=mp[i-1][1];
	for(long long i=1;i<=n;i++) pref[i]=max(pref[i-1],0ll)+mp[i][0]-mp[i-1][0]+mp[i][1]-mp[i-1][1];
	for(long long i=n;i!=0;i--) suff[i]=max(suff[i+1],0ll)+mp[i][0]-mp[i-1][0]+mp[i][1]-mp[i-1][1];
	long long ans=0x8000000000000000;
	for(long long i=1;i<=n;i++){
		for(long long j=i+2;j<=n;j++){
			ans=max(ans,pref[i]+suff[j]+max(mp[j-1][1]-mp[i][1],mp[j-1][0]-mp[i][0]));
			// printf("<[%lld,%lld],%lld,%lld,%lld>\n",i,j,pref[i],suff[j],pref[i]+suff[j]+max(mp[j-1][1]-mp[i][1],mp[j-1][0]-mp[i][0]));
		}
	}
	printf("%lld",ans);
}