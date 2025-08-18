#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10501],f[10501],minn;
int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n+1;i<=n+m;i++)a[i]=114514191;
	memset(f,0x3f,sizeof(f));
	int max1=0,max2=0;
	f[0]=0;
	minn=114514191;
	for(int i=1;i<m;i++)
	{
		if(a[i]>max1)max2=max1,max1=a[i];
		else if(a[i]>max2)max2=a[i];
		f[i]=max1+max2;
	}
	for(int i=m;i<=n+m;i++)
	{
		for(int j=i-m+2;j<=i;j++)
		{
			for(int k=i-m+1;k<j;k++)
			{
				f[i]=min(f[i],a[j]+a[k]+f[k-1]);
			}
		}
//		cout<<f[i]<<endl;
		if(i>=n)minn=min(minn,f[i]);
	}
	cout<<minn<<endl;
	return 0;
}
