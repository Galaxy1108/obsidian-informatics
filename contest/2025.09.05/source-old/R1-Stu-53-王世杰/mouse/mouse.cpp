#include<bits/stdc++.h>
using namespace std;
int w,b;
double ans;
double f[2001][1001];
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	cin>>w>>b;
	f[w+b][b]=1;
	int k=0;
	for(int i=w+b;i>=1;i--)
	{
		k++;
		for(int j=b;j>=0;j--)
		{
			if(j<i)
			{
				if(k%3==1)
				{
					ans+=f[i][j]*(((double)(i-j))/((double)i));
					f[i-1][j-1]+=f[i][j]*(((double)j)/((double)i));
				}
				if(k%3==2)
				{
					f[i-1][j-1]+=f[i][j]*(((double)j)/((double)i));
				}
				if(k%3==0)
				{
					f[i-1][j]+=f[i][j]*(((double)(i-j))/((double)i));
					f[i-1][j-1]+=f[i][j]*(((double)j)/((double)i));
				}
			}
		}
	}
	printf("%.9lf",ans);
	return 0;
}
