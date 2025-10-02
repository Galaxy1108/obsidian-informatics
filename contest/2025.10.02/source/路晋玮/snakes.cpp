#include<iostream>
using namespace std;
int a[1000005];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,n,i,k,x,y,j;
	cin>>t>>n;
	for(i=1;i<=n;i++)
	    cin>>a[i];
	if(a[3]-a[1]>=a[2])
	    cout<<1<<endl;
	else
	    cout<<3<<endl;
	for(i=2;i<=t;i++)
	{
		cin>>k;
		for(j=1;j<=k;j++)
		{
			cin>>x>>y;
			a[x]=y;
		}
		if(a[3]-a[1]>=a[2])
	    cout<<1<<endl;
	    else
	    cout<<3<<endl;
	}
	return 0;
}
