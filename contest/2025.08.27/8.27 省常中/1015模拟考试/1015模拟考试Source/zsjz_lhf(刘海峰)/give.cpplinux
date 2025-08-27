#include<cstdio>
#include<bitset>
using namespace std;
const int N=2e5+1;
bitset<N> dp[70],w,t;
long long m,s;
int n,k,a[N],T;
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%d",&m,&s,&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),t[a[i]]=1;
		k=2*a[n]-1;
		dp[0]=(m&1)?t:1;
		int i;
		for(i=0;(1ll<<i)<=s;i++)
		{
			bool p=s&(1ll<<i);
			for(int j=0;(j<<1)<=k;j++)
				w[j]=dp[i][j<<1|p];
			if(!(m&(1<<(i+1)))) dp[i+1]=w;
			else for(int j=1;j<=n;j++)
				dp[i+1]^=w<<a[j];
			w=0;
		}
		printf("%d\n",int(dp[i][0]));
		while(i) dp[i--]=0;
		t=0;
	}
}