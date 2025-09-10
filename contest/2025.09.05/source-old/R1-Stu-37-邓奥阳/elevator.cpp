#include<bits/stdc++.h>
using namespace std;
int n,a[2001],b[2001];
int now,r,hv,ans,to;
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	scanf("%d",&n);
	b[0]=1;
	for(int i=1;i<=n;++i)scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;++i)
	{
		ans+=abs(a[i]-b[i-1]+1)+abs(a[i]-b[i]+1)+1;
	}
	printf("%d",ans);
}
