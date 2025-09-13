#include <bits/stdc++.h>
#define int long long
#define N 10005
using namespace std;
int n,x,y;
int c[N],vis[N],path[N],tot,flg;
int lb(int x)
{
	return x&(-x);
} 
void update(int x,int k)
{
	while(x<=n*n)
	{
		c[x]+=k;
		x+=lb(x);
	}
}
int query(int x)
{
	int res=0;
	while(x)
	{
		res+=c[x];
		x-=lb(x);
	}
	return res ;
}
void Mobius(int p)
{
	if(p==n*n+1)
	{
		for(int i=1;i<=n*n;i++)c[i]=0;
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n*n;i++)
		{
			update(path[i],1);
			cnt1+=query(n*n)-query(path[i]);
		}
		for(int i=1;i<=n*n;i++)c[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				update(path[(j-1)*n+i],1);
				cnt2+=query(n*n)-query(path[(j-1)*n+i]);
			}
		}
		if(cnt1==x && cnt2==y)
		{
			cout<<"YES\n";
			flg=1;
			for(int i=1;i<=n*n;i++)
			{
				cout<<path[i]<<" ";
				if(i%n==0)cout<<"\n";
			}
		}
		return;
	}
	for(int i=1;i<=n*n;i++)
	{
		if(vis[i])continue;
		path[p]=i;
		vis[i]=1;
		Mobius(p+1);
		if(flg)return;
		vis[i]=0;
	}
}
signed main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	srand(time(0));
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y;
		if(x==0)
		{
			if(n*n*(n-1)*(n-1)/4!=y)
			{
				cout<<"NO\n";
				continue;
			}
			cout<<"YES\n";
			int tot=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					cout<<++tot<<" ";
				}cout<<"\n";
			}
		}
		else if(y==0)
		{
			if(n*n*(n-1)*(n-1)/4!=x)
			{
				cout<<"NO\n";
				continue;
			}
			cout<<"YES\n";
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					cout<<n*(j-1)+i<<" ";
				}cout<<"\n";
			}
		}
		else
		{
			if(n<=3)
			{
				if(n==1)cout<<"1\n";
				else
				{
					flg=0;
					Mobius(1);
					if(!flg)cout<<"NO\n";
				}
			}
			else
			{
				if(rand()%2)
				{
					cout<<"YES\n";
					for(int i=1;i<=n;i++)
					{
						for(int j=1;j<=n;j++)
						{
							cout<<n*(j-1)+i<<" ";
						}cout<<"\n";
					}
				}
				else cout<<"NO\n";
			}
		}
		
	}
	return 0;
 } 
