#include <bits/stdc++.h>
using namespace std;
bitset<10000005> a;
bitset<10000005> b;
int n;
int book[21];
void print()
{
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int ans;
int main()
{
    freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	int q;
    cin>>n>>q;
    a.set();
    bool flag=false;
    while(q--)
    {
    	int tp,m;
    	scanf("%d%d",&tp,&m);
    	if(tp==1)
    	{
    		if(book[m])
    		{
    			continue;
			}
			else
			{
				book[m]=1;
				for(int i=1;i<=n;i+=m)
				{
					if(i<=n and a[i])
					{
						a[i]=0;
					}
				}
			}
//			print();
		}
		else if(tp==2)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				if(a[i])
				{
					cnt++;
				}
				if(cnt%m==1 and a[i])
				{
					a[i]=0;
				}
			}
//			print();
		}
		else
		{
			if(flag)
            {
                cout<<-1;
                continue;
            }
			b=a;
			while(1)
			{
				int cnt=0;
				for(int i=1;i<=n;i++)
				{
					if(b[i])
					{
						cnt++;
					}
					if(cnt%m==1 and b[i])
					{
						b[i]=0;
						ans=i;
					}
				}
				if(cnt==1)
				{
					break;
				}
				cnt=0;
				for(int i=n;i>=1;i--)
				{
					if(b[i])
					{
						cnt++;
					}
					if(cnt%m==1 and b[i])
					{
						b[i]=0;
						ans=i;
					}
				}
				if(cnt==1)
				{
					break;
				}

			}
			printf("%d\n",ans);
			if(!a.any())
			{
				flag=true;
				continue;
			}
//			print();
		}
	}
 }

