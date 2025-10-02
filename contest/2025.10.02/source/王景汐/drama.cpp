#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	int n;
	cin>>n;
	long long int a[10000000]={0};
	for(int i=1;i<=n;i++) cin>>a[i];
	long long int y=-1,z=INT_MAX;
	unsigned __int128 x=1;
	for(int i=1;i<=n;i++){
		y=-1;
		z=INT_MAX;
		for(int j=i;j<=n;j++)
		{
			if(y<a[j]) y=a[j];
			if(z>a[j]) z=a[j];
			if(y*z*(j-i+1)>x) x=y*z*(j-i+1);	
		}
	}
	short b[30],c=0;
	for(int i=1;x!=0;i++)
	{
		c++;
		b[i]=x%10;
		x=x/10;
	}
	for(int i=c;i>=1;i--)
	cout<<b[i];
 	return 0;
}
 	

