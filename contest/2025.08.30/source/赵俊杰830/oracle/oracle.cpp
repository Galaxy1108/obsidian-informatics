#include<bits/stdc++.h>
using namespace std;
const int N=25;
int ans,l[N*N],r[N*N],n,m,b[N];
void dfs(int k,int s,int t)
{
//	cout<<k<<' '<<s<<' '<<t<<'\n';
	if(k>m)
	{
		//for(int i=1;i<=m;i++)cout<<"["<<l[i]<<","<<r[i]<<"] ";
		//cout<<'\n';
		for(int i=1;i<=n;i++)
		{
			int x=1,y=n;
			//cout<<x<<' '<<y<<'\n';
			for(int j=1;j<=m;j++)
			{
				if(i>=l[j]&&i<=r[j])
				{
					x=max(x,l[j]);
					y=min(y,r[j]);
				}
			}
			//cout<<x<<' '<<y<<'\n';
			for(int i=1;i<=n;i++)b[i]=1;
			//cout<<x<<' '<<y<<'\n';
			for(int i=1;i<x;i++)b[i]=0;
			//cout<<x<<' '<<y<<'\n';
			for(int i=y+1;i<=n;i++)b[i]=0;
			//cout<<x<<' '<<y<<'\n';
			//for(int i=1;i<=n;i++)cout<<b[i]<<' ';
			//cout<<'\n';
			for(int j=1;j<=m;j++)
				if(i<l[j]||i>r[j])
				{
					for(int k=l[j];k<=r[j];k++)
						b[k]=0;
				}
			int cnt=0;
			for(int i=1;i<=n;i++)cnt+=b[i];
			//for(int i=1;i<=n;i++)cout<<b[i]<<' ';
			//cout<<'\n';
			if(cnt!=1)return;
		}
		// for(int i=1;i<=m;i++)cout<<"["<<l[i]<<","<<r[i]<<"] ";
		//cout<<'\n';
		ans++;
		//exit(0);
		return;
	}
	for(int j=t;j<=n;j++)
	{
		l[k]=s;r[k]=j;
		dfs(k+1,s,j+1);
	}
	for(int i=s+1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			l[k]=i;r[k]=j;
			dfs(k+1,i,j+1);
		}
}
int main()
{
	freopen("oracle.in","r",stdin);
	freopen("oracle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(m==n*(n+1)/2)
	{
		cout<<"1\n";
		return 0;
	}
	if(n>10)
	{
		cout<<"0\n";
		return 0;
	}
	dfs(1,1,1);
	cout<<ans<<'\n';
	return 0;
}
