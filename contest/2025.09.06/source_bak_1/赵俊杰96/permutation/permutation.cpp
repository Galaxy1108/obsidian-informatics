#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int p[N],q[N],x[N],y[N],b[N];
int c[N],d[N],top1,top2,cnt;
bool dfs(int u)
{
	cnt++;
	if(cnt>3e7)
	{
		cout<<"NO\n";
		exit(0);
	}
	c[++top1]=u;
	b[x[u]]=1;
	if(!y[p[x[u]]])
	{
		y[p[x[u]]]=q[u];
		d[++top2]=p[x[u]];
		if(!x[q[u]])
		{
			x[q[u]]=p[x[u]];
			//c[++top1]=q[u];
			b[p[x[u]]]=1;
			if(!dfs(q[u]))return 0;
		}
		else if(x[q[u]]!=p[x[u]])return 0;
	}
	else if(y[p[x[u]]]!=q[u])return 0;
	return 1;
}
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)cin>>q[i];
	for(int i=1;i<=n;i++)
	{
		if(x[i])continue;
		for(int j=1;j<=n;j++)
		{
			if(b[j])continue;
			x[i]=j;
			y[j]=i;
			top1=0;top2=0;
			d[++top2]=j;
			if(dfs(i))break;
			for(int k=1;k<=top1;k++)
			{
				b[x[c[k]]]=0;
				x[c[k]]=0;
			}
			for(int k=1;k<=top2;k++)
				y[d[k]]=0;
		}
		if(!x[i])
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)cout<<x[i]<<' ';
	cout<<'\n';
	return 0;
}
