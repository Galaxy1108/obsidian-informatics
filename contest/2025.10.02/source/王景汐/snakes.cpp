#include<bits/stdc++.h>
using namespace std;	
int t,n;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int m;
	int a[1000001],b[1000001];
	cin>>t>>n;
	int www=t;
	while(t--)
	{
		int wjx=n;
		if(t==www-1)
		{
			for(int i=1;i<=n;i++) {cin>>a[i];b[i]=a[i];}
			while(n!=1)
			{
				if(a[n]-a[1]>a[2]) 
				{
					a[n]=a[n]-a[1];
					n--;
					for(int i=1;i<=n;i++) a[i]=a[i+1];
					for(int i=n;i>=1;i--) if(a[i]<a[i-1]) swap(a[i],a[i-1]); else break;
				}
				else
				break;
			}
			cout<<n<<endl;
			n=wjx;
			for(int i=1;i<=n;i++) a[i]=b[i];
		}
		else
		{
			cin>>m;
			int x,y;
			for(int i=1;i<=m;i++)
			{
				cin>>x>>y;
				a[x]=y;
			}
			while(n!=1)
			{
				if(a[n]-a[1]>a[2]||n==2) 
				{
					a[n]=a[n]-a[1];
					n--;
					for(int i=1;i<=n;i++) a[i]=a[i+1];
					for(int i=n;i>=1;i--) if(a[i]<a[i-1]) swap(a[i],a[i-1]); else break;
				}
				else
				break;
			}
			cout<<n<<endl;
			n=wjx;
			for(int i=1;i<=n;i++) a[i]=b[i];
		}
	}
 	return 0;
}
 	

