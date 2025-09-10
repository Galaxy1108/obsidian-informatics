#include <bits/stdc++.h>
#define N 100005
using namespace std;
int n;
int p[N],q[N],h[N];
int tmp1[N],tmp2[N];
int vis[15],found;
bool eq(int a[],int b[])
{
	for(int i=1;i<=n;i++)if(a[i]!=b[i])return 0;
	return 1;
}
void Mobius(int pos) 
{
	if(found)return;
	if(pos==n+1)
	{
		for(int i=1;i<=n;i++)tmp1[i]=p[h[i]];
		for(int i=1;i<=n;i++)tmp2[i]=h[q[i]];
		if(eq(tmp1,tmp2))
		{
			cout<<"YES\n";
			for(int i=1;i<=n;i++)cout<<h[i]<<" ";
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(found)return;
		if(vis[i])continue;
		vis[i]=1;
		h[pos]=i;
		Mobius(pos+1);
		vis[i]=0;
	}
}

int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>n;
	
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)cin>>q[i];
	if(n<=10)
	{
		Mobius(1);
		cout<<"NO";
	}
	else
	{
		if(p==q)
		{
			cout<<"YES\n";
			for(int i=1;i<=n;i++)cout<<i<<" ";
		}
		else cout<<"NO";
	}
	return 0;
}
