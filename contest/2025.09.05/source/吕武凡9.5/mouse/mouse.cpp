#include<bits/stdc++.h>
using namespace std;
int w,b;
double f[1010][1010];
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	cin>>w>>b;
	f[0][0]=0.0;
	f[0][1]=0.0;
	f[1][0]=1.0;
	f[1][1]=0.5;
	for(int i=1;i<=w;i++)
	{
		f[i][0]=1.0;
		f[i][1]=i*1.0/(i+1);
	}
	for(int j=1;j<=b;j++)
	{
		f[0][j]=0.0;
	}
	for(int i=1;i<=w;i++)
	{
		for(int j=2;j<=b;j++)
		{
			double sum=0.0;
			//i j-2
			if(j==2)
			{
				sum=0.0;
			}
			else
			{
				sum=f[i-1][j-2]*1.0/2+f[i][j-3]*1.0/2;
			}
			f[i][j]=i*1.0/(i+j)+sum*1.0*(j-1)*j*1.0/((i+j-1)*(i+j)*1.0);
		}
	}
	cout<<fixed<<setprecision(9)<<f[w][b];
}
