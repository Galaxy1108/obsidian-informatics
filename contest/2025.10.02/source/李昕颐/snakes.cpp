#include<iostream>
#include<map>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct node
{
	int s,id;
}a[1000001];
map<int,int> q;
bool cmp(node x,node y)
{
	if(x.s!=y.s)return x.s<y.s;
	else return x.id<y.id;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,s=0;
	cin>>t;
	for(int k=1;k<=t;k++)
    {
    	int n;
    	cin>>n;
    	if(k==1)
    	{
    		for(int i=1;i<=n;i++)
			{
			    cin>>a[i].s;
			    a[i].id=i;
			    q[i]=i;
			    if(a[i].s==0)s++;
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
			    int x,y;
			    cin>>x>>y;
			    if(a[q[x]].s==0&&y!=0)s--;
			    a[q[x]].s=y;
			}
		}
		sort(a+1,a+n+1,cmp);
		int num=0;
		for(int i=1;i<n;i++)
		{
			num+=a[i].s;
		}
		if(num<=a[n].s)
		{
			s=n-1;
			cout<<"1\n";
			for(int i=1;i<n;i++)a[i].s=0;
			continue;
		}
		for(int i=1;i<n;i++)
		{
			if(n-s==2)
			{
				a[n].s-=a[n-1].s;
				a[n-1].s=0;
				s++;
			}
			else if(a[n].s-a[1+s].s>a[1+s+1].s)
			{
				a[n].s-=a[1+s].s;
				a[1+s].s=0;
				s++;
			}
			else if(a[n].s-a[1+s].s==a[1+s+1].s&&a[n].id>a[1+s+1].id)
			{
				a[n].s-=a[1+s].s;
				a[1+s].s=0;
				s++;
			}
			else break;
			sort(a+1,a+n+1,cmp);
		}
		for(int i=1;i<=n;i++)
		{
			q[a[i].id]=i;
		}
		cout<<n-s<<endl;
	}
	return 0;
}
