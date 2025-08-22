#include <bits/stdc++.h>
using namespace std;
int x[100005];
int y[100005];
int k;
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		int q;
		cin>>q;
		while(q--)
		{
			bool flag=false;
			int l,r;
			cin>>l>>r;
			k=r-l+1;
			for(int i=0;i<k;i++)
			{
				y[i]=x[i+l];
			}
			for(int c=1;c<=20;c++)
			{
				for(int b=0;b<=100;b++)
				{
					for(int a=0;a<=1000;a++) 
					{
						for(int i=0;i<k;i++)
						{
							if(y[i]!=(a*i+b)/c)
							{
								break;
							}
							if(i==k-1)
							{
								flag=true;
								cout<<a<<" "<<b<<" "<<c<<endl; 
								break;
							}
						}
						if(flag) break;
					}
					if(flag) break;
				}
				if(flag) break;
			}
			if(!flag)
			{
				cout<<x[l+1]-x[l]<<" "<<x[l]<<" "<<1<<endl;
			}
		}
	}
	return 0;
}
