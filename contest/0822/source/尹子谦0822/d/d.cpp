#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main()
{
	freopen("d1.in","r",stdin);
	freopen("d.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,x[N],d[N],q;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>x[i],d[i]=x[i]-x[i-1];
		cin>>q;
		if(n<=20&&q<=20)
		{
			while(q--)
			{
				int l,r,fd;
				cin>>l>>r;
				for(int c=1;c<=20;c++)
				{
					for(int a=0;a<=20;a++)
					{
						for(int b=0;b<=20;b++)
						{
							fd=1;
							for(int i=l;i<=r;i++)
							{	
								if((a*(i-l)+b)/c!=x[i])
								{
									fd=0;
									break;
								}
							}
							if(fd)
							{
								cout<<a<<' '<<b<<' '<<c<<endl;
								break;
							}
						}
						if(fd)break;
					}
					if(fd) break;
				}
			}
			continue;
		}
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			cout<<x[l+1]-x[l]<<' '<<x[l]<<' '<<1<<endl;
		}
	}
	return 0;
}

