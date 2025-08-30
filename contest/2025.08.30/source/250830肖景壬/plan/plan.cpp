#include<bits/stdc++.h>
using namespace std;
int n,k,x,y,ans=0;
int gcd(int xx,int yy)
{
	if(yy==0) return xx;
	return gcd(yy,xx%yy);
}
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	cin>>n>>k;
	for(int i = 1; i < n; i++)
	{
		cin>>x>>y;
	}
	for(int i = 1; i <= n; i++)
	{
		cin>>x;
		ans=gcd(x,ans);
	}
	cout<<ans<<endl; 
}
