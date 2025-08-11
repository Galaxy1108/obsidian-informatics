#include<bits/stdc++.h>
using namespace std;
int t;
long long s,k;
bool tick[1000100];
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>s>>k;
		if(s%2==1)
		{
			if(k>s/2)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<2*k<<endl;
			}
		}
		else
		{
			memset(tick,0,sizeof(tick));
			tick[1]=tick[2]=1;
			for(int i=1;i<=sqrt(s);i++)
			{
				if(s%i==0)
				{
					tick[i]=tick[s/i]=1;
				}
			}
			for(int i=1;i<s;i++)
			{
				if(tick[i]==0)
				{
					for(int j=s;j>=i;j-=i)
					{
						tick[j]=1;
					}
				}
			}
			int p=0;
			for(int i=1;i<s;i++)
			{
				if(tick[i]==0)
				{
					p++;
					if(p==k)
					{
						cout<<i<<endl;
					}
				}
			}
			if(k>p)
			{
				cout<<-1<<endl;
			}
		}
	}
}
