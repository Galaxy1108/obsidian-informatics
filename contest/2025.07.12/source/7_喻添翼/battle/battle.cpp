#include<bits/stdc++.h>
using namespace std;
const int mx=150010;
struct hl
{
	int x,y,z,p;
}a[mx];
bool cmp(hl A,hl B)
{
	return A.x>B.x;
}
bool flag;
int n,ans=-1,sum;
int main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+1+n,cmp);
	//flag=0;
	for(int i=1;i<=n;i++)
	{	
		sum=a[i].x;
		for(int j=1;j<=n;j++)
		{
			if(a[i].y<a[j].y&&a[j].x<a[i].x)
			{
				sum+=a[j].y;
				for(int k=1;k<=n;k++)
				{
					if(a[i].z<a[k].z&&a[j].z<a[k].z&&a[k].y<a[j].y&&a[k].x<a[i].x)
						ans=max(ans,sum+a[k].z);
				}
				sum-=a[j].y;
			}
			
		}
	}
	cout<<ans;
	return 0;
}
