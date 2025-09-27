#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int n,m,mx=0,mn,r,l,i,j,c,sum,cu=0,jl;
deque<int> z,y;
int main()
{
	ios::sync_with_stdio(0);
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>l;
		z.push_back(l);
	}
	for(i=1;i<=m;i++)
	{
		cin>>r;
		y.push_back(r);
	}
	if(m<n)
	{
		swap(z,y);
		swap(n,m);
	}
	sort(z.begin(),z.end());
	sort(y.begin(),y.end());
	if(n==m)
	{
		for(i=0;i<n;i++)
		{
			mx=max(mx,abs(z[i]-y[i]));
		}
	}
	else
	{
		c=m-n;
		if(abs(z.front()-y.front())>abs(z.back()-y.back()))
		{
			for(i=0;i<n;i++)
			{
				mn=2e9;
				for(j=cu;j<=c+i;j++)
				{
			//		cout<<"t1 "; 
					if(abs(z[i]-y[j])<mn)
					{
			//			cout<<"t2 ";
						cu=j;
						mn=abs(z[i]-y[j]);
					}
				}
				mx=max(mx,mn);
			}
		}
		else
		{
			cu=n-1;
			for(i=n-1;i>=0;i--)
			{
				mn=2e9;
				for(j=cu;j>=i-cu;j--)
				{
			//		cout<<"t1 "; 
					if(abs(z[i]-y[j])<mn)
					{
			//			cout<<"t2 ";
						cu=j;
						mn=abs(z[i]-y[j]);
					}
				}
				mx=max(mx,mn);
			}
		}
	}
	cout<<mx;
	return 0;
}
/*
5 5 
7 6 1 2 10 
9 11 6 3 12

2 3 
2 3 
1 2 3

4 3 
2 39 41 45 
39 42 46

11 5
1 2 3 4 19 20 21 23 24 25 26
21 22 23 24 25
 
*/

