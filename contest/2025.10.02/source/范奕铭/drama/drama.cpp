#include<bits/stdc++.h>
using namespace std;
long long n;
unsigned long long h[2000600];
struct dph
{
	long long maxn=0;
	long long minn=0;
}a[2000];
int zhi;
long long shu;
unsigned long long dphmaxn=0;
int ans=0; 
int ans1=0;
int ans2=0;
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
	}
	zhi=sqrt(n);
	shu=n/zhi;
	if(n%zhi!=0)
	{
		shu++;
	}
	for(long long i=1;i<=shu;i++)
	{
		unsigned long long maxn=0;
		unsigned long long minn=1e10;
		for(int j=(i-1)*zhi+1;j<=min(i*zhi,n);j++)
		{
			if(h[j]>maxn)
			{
				maxn=h[j];
			}	
			if(h[j]<minn)
			{
				minn=h[j];
			}	
		}
		a[i].maxn=maxn;
		a[i].minn=minn;
	}
	for(int i=1;i<=n;i++)
	{
		unsigned long long b=0;
		long long chang=1;
		long long p=(i+zhi-1)/zhi;
		bool zuo=0;
		bool you=0;
		long long maxn=h[i];
		for(long long j=i-1;j>=(p-1)*zhi+1;j--)
		{
			if(h[j]>maxn)
			{
				maxn=h[j];
			}
			if(h[j]<h[i])
			{
				zuo=1;
				break;
			}
			chang++;
		}
		for(long long j=i+1;j<=min(p*zhi,n);j++)
		{
			if(h[j]>maxn)
			{
				maxn=h[j];
			}
			if(h[j]<h[i])
			{
				you=1;
				break;
			}
			chang++;
		}
		if(zuo==0)
		{
			for(long long j=p-1;j>=1;j--)
			{
				if(a[j].minn<h[i])
				{
					for(int w=j*zhi;w>=(j-1)*zhi+1;w--)
					{
						if(h[w]<h[i])
						{
							break;
						}
						chang++;
						if(h[w]>maxn)
						{
							maxn=h[w];
						}
					}
					break;
				}
				chang+=zhi;
				if(a[j].maxn>maxn)
				{
					maxn=a[j].maxn;
				}
			}
		}
		if(you==0)
		{
			for(long long j=p+1;j<=shu;j++)
			{
				if(a[j].minn<h[i])
				{
					for(int w=(j-1)*zhi+1;w<=min(n,j*zhi);w++)
					{
						if(h[w]<h[i])
						{
							break;
						}
						chang++;
						if(h[w]>maxn)
						{
							maxn=h[w];
						}
					}
					break;
				}
				chang+=zhi;
				if(a[j].maxn>maxn)
				{
					maxn=a[j].maxn;
				}
			}
		}
		b=chang*h[i]*maxn;
		if(b>dphmaxn)
		{
			dphmaxn=b;
			ans=i;
		//	ans1=chang;
		//	ans2=maxn;
		}
	//	cout<<b<<endl;
	}
	cout<<dphmaxn;//<<" "<<h[ans]<<" "<<ans1<<" "<<ans2;
	return 0;
}
