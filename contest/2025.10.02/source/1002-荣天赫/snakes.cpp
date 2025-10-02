#include<iostream>
#include<algorithm>
using namespace std;
int snake[50005],curr[50005];
int head,tail;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t;
	int n;
	cin>>t;
	for(int fl=1;fl<=t;fl++)
	{
		if(fl==1)
		{	
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				cin>>snake[i];
			}
		}
		else
		{
			int k;
			cin>>k;
			for(int i=1;i<=k;i++)
			{
				int x,y;
				cin>>x>>y;
				snake[x]=y;
				
			}
		}
		for(int i=1;i<=n;i++)
		{
			curr[i]=snake[i];
		}
		head=1,tail=n;
		while(head<tail)
		{
			if(curr[tail]-curr[head]>curr[head+1]&&head+1<tail)
			{
				curr[tail]-=curr[head];
				head++;
				for(int j=head;j<tail;j++)
				{
					if(curr[j]>curr[j+1])
					{
						swap(curr[j],curr[j+1]);
					}
				}
				for(int j=tail;j>head;j--)
				{
					if(curr[j]<curr[j-1])
					{
						swap(curr[j],curr[j-1]);
					}
				}
			}
			else if(head+1==tail&&curr[head]<curr[tail])
			{
				head++;
			}
			else
			{
				break;
			}
		}
		cout<<tail-head+1<<endl;
	}
	return 0;
}
