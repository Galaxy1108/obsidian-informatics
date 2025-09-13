#include <bits/stdc++.h>
using namespace std;
int a[2000005];
int b[2000005];
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,l,r;
	cin>>n>>l>>r;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='a')
		{
			a[i+1]=a[i]+1;
			b[i+1]=b[i];
		}
		else
		{
			a[i+1]=a[i];
			b[i+1]=b[i]+1;
		}
	}
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ax=a[x],ay=a[y];
	//	cout<<q<<"\n";
		if(a[x]==a[y])
		{
			if(a[n]-a[y]+1>=l||a[y]-a[1]+1>=l)
			{
				cout<<"Yes\n";
			}
			else
			{
				cout<<"No\n";
			}
			continue;
		}
		int k=abs(ay-ax)+1;
		int c=r-l;
		//k%=l;
		if(l==r)
		{
			if(k%l<=1)
			{
				cout<<"Yes\n";
			}
			else
			{
				cout<<"No\n";
			}
		}
	}
	
	
	return 0;
} 
