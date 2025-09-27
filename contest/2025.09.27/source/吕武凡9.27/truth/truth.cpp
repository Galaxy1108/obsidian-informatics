#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int a[50010];
int op,x,y;
bool tong[32];
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			a[x]=y;
		}
		else
		{
			bool f=0;
			for(int len=k;len<=n;len++)
			{
				for(int l=1,r=l+len-1;l<=n,r<=n;l++,r++)
				{
					for(int j=l;j<=r;j++)
					{
						tong[a[j]]=1;
					}
					bool ti=0;
					for(int j=1;j<=k;j++)
					{
						if(tong[j]==0)
						{
							ti=1;
							break;
						}
					}
					for(int j=1;j<=k;j++)
					{
						tong[j]=0;
					}
					if(ti==0)
					{
						f=1;
						cout<<len<<endl;
						break;
					}
				}
				if(f)
				{
					break;
				}
			}
			if(!f)
			{
				cout<<-1<<endl;
				continue;
			}
		}
	}
}
