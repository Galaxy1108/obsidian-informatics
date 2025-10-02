#include<iostream>
#include<cstring>
using namespace std;
int card[1000005],chose[1000005],jl[1000005];
int cnt[2],lst,ans;
int minn=1e9;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(chose,-1,sizeof(chose));
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
		cnt[card[i]%2]++;
	}
	while(m--)
	{
		int p,b;
		cin>>p>>b;
		chose[p]=b%2;
		cnt[b%2]--;
	}
	while(q--)
	{
		ans=0;
		int op;
		cin>>op;
		if(op==1)
		{
			int p;
			cin>>p;
			cnt[chose[p]]++;
			chose[p]=-1;
		}
		if(op==2)
		{
			int p,x;
			cin>>p>>x;
			if(chose[p]!=-1)
			{
				cnt[chose[p]]++;
				chose[p]=x%2;
			}
			else
			{
				chose[p]=x%2;
				cnt[x%2]--;
			}
		}
		if(cnt[0]==0)
		{
			for(int i=1;i<n;i++)
			{
				chose[i]==chose[i+1]||chose[i]+chose[i+1]==0 ? ans+=0:ans+=1;
			}
			cout<<ans<<endl;
		}
		else if(cnt[1]==0)
		{
			for(int i=1;i<n;i++)
			{
				chose[i]==chose[i+1]||chose[i]+chose[i+1]==-1 ? ans+=0:ans+=1;
			}
			cout<<ans<<endl;
		}
		else if(cnt[0]==1)
		{
			int minn=1e9;
			for(int i=1;i<=n;i++)
			{
				if(chose[i]==-1)
				{
					chose[i]=0;
					ans=0;
					for(int j=1;j<n;j++)
					{
						chose[j]==chose[j+1]||chose[j]+chose[j+1]==0 ? ans+=0:ans+=1;
					}
					minn=min(minn,ans);
					chose[i]=-1;
				}
			}
			cout<<minn<<endl;
		}
		else if(cnt[1]==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(chose[i]==-1)
				{
					chose[i]=1;
					ans=0;
					for(int j=1;j<n;j++)
					{
						chose[j]==chose[j+1]||chose[j]+chose[j+1]==-1 ? ans+=0:ans+=1;
					}
					minn=min(minn,ans);
					chose[i]=-1;
				}
			}
			cout<<minn<<endl;
		}
		else
		{
			cout<<lst<<endl;
		}
		lst=min(ans,minn);
	}
	return 0;
}
