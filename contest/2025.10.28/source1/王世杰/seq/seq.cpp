#include<bits/stdc++.h>
using namespace std;
int n,q,a[500005];
int hzh[500005];
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>n>>q;
	int c,b;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&b,&c);
		a[b]=c;
		for(int j=n;j>=1;j--)
		{
			hzh[j]=max(hzh[j+1],a[j]);
		}
		int minn=100000000;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			minn=min(minn,a[i]);
			if(minn>=hzh[i+1]) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
