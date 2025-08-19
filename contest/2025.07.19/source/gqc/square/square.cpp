#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int t[71];
int a[100005]; 
int p[19],cnt,b[19];
void init()
{
	bool isp[71]={false};
	for(int i=2;i<=70;i++)
	{
		if(!isp[i])
		{
			p[cnt++]=i;
			for(int j=i*i;j<=70;j+=i)
			{
				isp[j]=true;
			}
		}
	}
}
int main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout); 
	init();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]; 
	}
	int r=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==1) continue;
		int msk=0;
		int tmp=a[i];
		for(int j=0;j<cnt;j++)
		{
			int c=0;
			while(tmp%p[j]==0)
			{
				c++;
				tmp/=p[j];
			}
			if(c%2) msk|=(1<<j);
		}
		//高斯消元 
		int x=msk;
		for(int j=0;j<cnt;j++)
		{
			if((x>>j)&1)
			{
				if(!b[j])
				{
					b[j]=x;
					r++;
					break;
				}
				else
				{
					x^=b[j];
				} 
			}
		}
	}
	long long ans=1;
	int e=n-r;
//	cout<<e<<endl;
	for(int i=0;i<e;i++)
	{
		ans=ans*2%mod;
	}
	ans--;
	cout<<ans%mod;
	return 0;
 } 
