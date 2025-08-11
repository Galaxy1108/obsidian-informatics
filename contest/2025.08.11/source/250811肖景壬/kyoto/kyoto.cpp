#include<bits/stdc++.h>
using namespace std;
long long h,w,f[5005][5005],a[5005],b[5005];
int main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	cin>>h>>w;
	for(int i = 1; i <= h; i++)
	{
		cin>>a[i];
	}
	for(int i = 1; i <= w; i++)
	{
		cin>>b[i];
	}
	memset(f,0x3f,sizeof(f));
	f[0][1]=f[1][0]=0;
	for(int i = 1; i <= h; i++)
	{
		for(int j = 1; j <= w; j++)
		{
			f[i][j]=min(f[i][j-1]+a[i],f[i-1][j]+b[j]);
			if(i==1&&j==1) f[i][j]=0;
		}
	}
	cout<<f[h][w]<<endl;
}
