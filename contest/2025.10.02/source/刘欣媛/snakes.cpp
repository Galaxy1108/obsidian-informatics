#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
inline bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	int n;
	cin>>n;
	for(register int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int tot=1;
	while(t--)
	{
		
		if(tot!=1)
		{
			int k;
			cin>>k;
			//cout<<"h";
			for(register int i=1;i<=k;i++)
			{
				int x,y;
				cin>>x>>y;
				a[x]=y;
			//	cout<<x<<" "<<y<< " "<<a[x]<<"\n";
			}
		}
		for(register int i=1;i<=n;i++)
		{
			b[i]=a[i];
		}
		tot++;
		int cnt=0;
		while(1)
		{
			if(cnt==n-1)
			{
				break;
			}
			if(b[n]-b[cnt+1]>=b[min(cnt+2,n-1)])
			{
				b[n]-=b[cnt+1];
				b[cnt+1]=0;
				cnt++;
				int idx=n;
				while(b[idx]<b[idx-1])
				{
					swap(b[idx],b[idx-1]);
					idx--;
				}
			}
			
			else
			{
				break;
			}
			//sort(b+1,b+n+1);
		}
//		if(n-cnt>=5&&b[n-2]-(b[n-1]-(b[n]-b[cnt+1]))>=b[cnt+2])
//		{
//			cnt++;
//		}
		int o=b[n]-b[cnt+1];
		int idx=1;
		while(1)
		{
			if(b[n-idx]==0||n==3) break;
			if(b[n-idx-1]-o>=b[cnt+2])
			{
				break;
			}
			else
			{
				idx++; 
				o=b[n-idx]-o;
			}
		}
		if(idx%2==0)
		{
			cnt++;
		}
		cout<<n-cnt<<"\n";
	}
	
	
	
	
	return 0;
 } 
