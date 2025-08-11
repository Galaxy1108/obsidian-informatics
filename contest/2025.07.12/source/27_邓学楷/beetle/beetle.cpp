#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2500010,M=1e9+7;
int n,k,s[N];
ll ans;

int main()
{
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for (int i=1;i<=n;i++)
		ans+=(i%M)*((ll)pow(23,n-i)%M)%M,ans%=M;
	printf("%lld\n",ans);
	return 0;
}
