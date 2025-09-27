#include<bits/stdc++.h>
using namespace std;
int n;
long long dph[100500];
long long da[10005];
long long yihou(long long x,long long y)
{
	int a[40]={0};
	int dph1=0;
	while(x>0)
	{
		int af1=x%2;
		x=x/2;
		dph1++;
		a[dph1]=af1;
	}
	int b[40]={0};
	int dph2=0;
	while(y>0)
	{
		int af2=y%2;
		y=y/2;
		dph2++;
		b[dph2]=af2;
	}
	int c[40];
	for(int i=1;i<=max(dph1,dph2);i++)
	{
		if(a[i]!=b[i])
		{
			c[i]=1;
		} 
		else
		{
			c[i]=0;
		}
	}
	long long fuzhu=1;
	long long zhi=0;
	for(int i=1;i<=max(dph1,dph2);i++)
	{
		zhi=zhi+c[i]*fuzhu;
		fuzhu=fuzhu*2;
	}
	return zhi;
}
int cnt1;
int zhi1;
long long cnt=0;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>dph[i];
	}
	zhi1=sqrt(n);
	cnt1=n/zhi1;
	for(int i=1;i<=cnt1;i++)
	{
		int maxn=-10;
		for(int j=(i-1)*zhi1+1;j<=i*zhi1;j++)
		{
			if(dph[j]>maxn)
			{
				maxn=dph[j];
			}
		}
		da[i]=maxn;
	}
	for(int i=1;i<=n;i++)
	{
		long long dph6=dph[i];
		for(int j=i;j<=n;j++)
		{
			int dph3=(i+zhi1-1)/zhi1;
			int dph4=(j+zhi1-1)/zhi1;
			long long maxn1=-1;
			for(int w=dph3+1;w<=dph4-1;w++)
			{
				if(da[w]>maxn1)
				{
					maxn1=da[w];
				}
			}
			for(int w=i;w<=min(j,dph3*zhi1);w++)
			{
				if(dph[w]>maxn1)
				{
					maxn1=dph[w];
				}
			}
			for(int w=max((dph4-1)*zhi1+1,i);w<=j;w++)
			{
				if(dph[w]>maxn1)
				{
					maxn1=dph[w];
				}
			}
			if(j>i)
			{
				dph6=yihou(dph6,dph[j]);
			}
			if(dph6<=maxn1)
			{
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
