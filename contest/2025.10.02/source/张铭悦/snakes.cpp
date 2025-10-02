#include <bits/stdc++.h>

using namespace std;

int t;
int a[1000005];

struct P{
	int val;
	int num;
}b[1000005];

bool cmp(P x,P y)
{
	if(x.val==y.val)
	{
		return x.num<y.num;
	}
	return x.val<y.val;
}

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	int i,j;
	int n,m;
	int x,y;
	for(i=1;i<=t;i++)
	{
		if(i==1)
		{
			cin>>n;
			for(j=1;j<=n;j++)
			{
				cin>>a[j];
			}
		}
		else
		{
			cin>>m;
			for(j=1;j<=m;j++)
			{
				cin>>x>>y;
				a[x]=y;
			}
		}
		for(j=1;j<=n;j++)
		{
			b[j].val=a[j];
			b[j].num=j;
		}
		int head=1;
		while(head<n)
		{
			sort(b+head,b+n+1,cmp);
			int haha=b[n].val-b[head].val;
			if(head!=n-1&&haha>=b[n-1].val)
			{
				b[n].val=haha;
				head++;
			}
			else if(head==n-1&&b[n].val>=b[n-1].val)
			{
				b[n].val=haha;
				head++;
			}
			else if(b[n].num>b[head+1].num&&haha>=b[head+1].val)
			{
			    b[n].val=haha;
				head++;
			}
			else
			{
				break;
			}
		}
		cout<<n-head+1<<endl;
	}
	return 0;
}

