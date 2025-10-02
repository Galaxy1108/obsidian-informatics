#include <bits/stdc++.h>

using namespace std;

int n,m,q;
bool a[105];
bool b[105];
bool c[105];

/*struct P{
	int type,num,x;
}c[1000005];

bool cmp(P a,P b)
{
	return
}*/
int check()
{
	int i;
	int sum=0;
	if(b[1]==0)
	{
		for(i=1;i<=n;i++)
		{
			if(b[i]==1)
			{
				break;
			}
		}
		if(i!=n)
		{
			a[1]=a[i];
		}
		else if(i==n)
		{
			a[1]=1;
		}
	}
	for(i=2;i<=n;i++)
	{
		if(b[i]==1)
		{
			if(a[i]!=a[i-1])
			{
				sum++;
			}
			continue;
		}
		a[i]=a[i-1];
	}
	return sum;
}

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	int i,j;
	int x,y;
	for(i=1;i<=n;i++)
	{
		cin>>x;
		if(x%2==0)
		{
			a[i]=1;
		}
		else
		{
			a[i]=0;
		}
	}
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		if(y%2==0&&a[x]==0)
		{
			a[x]=1;
		}
		if(y%2!=0&&a[x]==1)
		{
			a[x]=0;
		}
		b[x]=1;
	}
	int z;
	int ans=check();
	int sum=0;
	for(i=1;i<=q;i++)
	{
		for(j=1;j<=n;j++)
		{
			c[j]=a[j];
		}
		sum=0;
		cin>>x>>y;
		//c[y].type=x;
		if(x==1)
		{
			if(y==1)
			{
				if(c[y]!=c[y+1])
				{
					sum--;
				}
				c[y]=c[y+1];
			}
			else if(y==n)
			{
				if(c[y]!=c[y-1])
				{
					sum--;
				}
				c[y]=c[y-1];
			}
			else
			{
				if(c[y-1]==c[y+1])
				{
					if(c[y]!=c[y-1])
					{
						sum-=2;
					}
				}
				c[y]=c[y-1];
			}
			b[y]=0;
		}
		else
		{
			cin>>z;
			if(z%2==0)
			{
				z=1;
			}
			else
			{
				z=0;
			}
			if(y==1)
			{
				if(z!=c[1])
				{
					sum++;
				}
			}
			else if(y==n)
			{
				if(z!=c[n])
				{
					sum++;
				}
			}
			else
			{
				if(c[y-1]==c[y+1])
				{
					if(z!=c[y])
					{
						sum+=2;
					}
				}
			}
			c[y]=z;
			b[y]=1;

		}
		cout<<ans+sum<<endl;
	}

	return 0;
 }

