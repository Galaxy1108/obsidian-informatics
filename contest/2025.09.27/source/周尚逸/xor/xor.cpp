#include<bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x=0; char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x;
}
int n,a[100005];
int pre[100005]={0};
long long ans=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;i++)
	{
		a[i]=rd();
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			int maxx=0;
			for(int k=j;k<=i;k++)
			{
				maxx=max(maxx,a[k]);
			}
			if((pre[i]^pre[j-1])<=maxx)ans++;
		}
	}
	cout<<ans+n;
	return 0;
}
