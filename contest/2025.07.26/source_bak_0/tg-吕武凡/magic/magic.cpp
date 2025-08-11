#include<bits/stdc++.h>
using namespace std;
long long n,q;
long long a[200010];
long long l[100010];
long long r[100010];
long long ans[1000100];
struct question
{
	long long t,p;
	long long id;
}e[1000100];
bool cmp(question a,question b)
{
	if(a.t!=b.t)
	{
		return a.t<b.t;
	}
	else
	{
		return a.p<b.p;
	}
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=q;i++)
	{
		cin>>e[i].t>>e[i].p;
		e[i].id=i;
	}
	sort(e+1,e+q+1,cmp);
	e[0].t=0;
	for(int i=1;i<=q;i++)
	{
		if(e[i].t>e[i-1].t)
		{
			
			long long num=e[i].t-e[i-1].t;
			for(int j=1;j<=num;j++)
			{
				for(int k=1;k<=n;k++)
				{
					l[k]=1e9;
				}
				for(int k=1;k<=n;k++)
				{
					r[k]=1e9;
				}
				for(int k=1;k<=n/2;k++)
				{
					l[k]=a[k];
				}
				for(int k=n/2+1;k<=n;k++)
				{
					r[k-n/2]=a[k];
				}
				long long h1=1,h2=1;
				for(int k=1;k<=n;k++)
				{
					if(l[h1]<r[h2])
					{
						a[k]=l[h1];
						h1++;
					}
					else
					{
						a[k]=r[h2];
						h2++;
					}
				}
				/*for(int i=1;i<=n;i++)
				{
					cout<<a[i]<<" ";
				}cout<<endl;
				cout<<j<<endl;*/
			}
			ans[e[i].id]=a[e[i].p];
		}
		else
		{
			ans[e[i].id]=a[e[i].p];
		} 
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<endl;
	}
}
