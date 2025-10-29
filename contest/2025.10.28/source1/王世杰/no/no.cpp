#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
bool to[200005];
int n,q,p,x;
int a[200005],b[200005];
int ans;
bool pd()
{
	for(int i=1;i<=n;i++)
	{
		to[a[i]]=false;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=b[i-1])
		{
			if(!to[b[i]]) to[b[i]]=true;
			else return false;
		}
	}
	return true;
}
void dfs(int cnt)
{
	if(pd())
	{
		ans=min(ans,cnt);
	}
	if(cnt>=ans) return ;
	bool tp[12];
	memset(tp,false,sizeof(tp));
	for(int i=1;i<=n;i++)
	{
		if(!tp[i])
		{
			for(int j=1;j<=n;j++)
			{
				if(b[j]==b[i]) tp[j]=true;
			}
			vector<int>lsi,lsj;
			int ci=b[i],cj;
			for(int j=1;j<=n;j++)
			{
				if(b[j]==b[i]) lsi.push_back(j);
			}
			for(int j=1;j<=n;j++)
			{
				lsj.clear();
				if(!tp[j])
				{
					cj=b[j];
					for(int k=1;k<=n;k++)
					{
						if(b[k]==cj) lsj.push_back(k);
					}
					for(int k=0;k<lsi.size();k++)
					{
						b[lsi[k]]=cj;
					}
					dfs(cnt+lsi.size());
					for(int k=0;k<lsi.size();k++)
					{
						b[lsi[k]]=ci;
					}
					for(int k=0;k<lsj.size();k++)
					{
						b[lsj[k]]=ci;
					}
					dfs(cnt+lsj.size());
					for(int k=0;k<lsj.size();k++)
					{
						b[lsj[k]]=cj;
					}
				}
			}
			for(int j=1;j<=n;j++)
			{
				if(b[j]==b[i]) tp[j]=false;
			}
		}
	}
}
int main()
{
	freopen("no.in","r",stdin);
	freopen("no.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		to[a[i]]=false;
		b[i]=a[i];
	}
	ans=INF;
	dfs(0);
	cout<<ans<<endl;
	for(int i=1;i<=q;i++)
	{
		cin>>p>>x;
		a[p]=x;
		for(int i=1;i<=n;i++)
		{
			to[a[i]]=false;
			b[i]=a[i];
		}
		ans=INF;
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
}
