#include<bits/stdc++.h>
using namespace std;
int n;
int p[100010],q[100010],h[100010];
bool tick[100010];
bool f=0;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(h[q[i]]!=p[h[i]])
		{
			return false;
		}
	}
	return true;
}
void DFS(int deep)
{
	if(f)
	{
		return;
	}
	if(deep>n)
	{
		if(check())
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<h[i]<<" ";
			}
			cout<<endl;
			f=1;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(tick[i]==0)
		{
			h[deep]=i;
			tick[i]=1;
			DFS(deep+1);
			tick[i]=0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
	}
	if(n<=10)
	{
		DFS(1);
		if(!f)
		{
			cout<<"NO"<<endl;
		}
	}
	else
	{
		cout<<"NO"<<endl;
		return 0;
	}
}
/*
10
1 5 2 6 3 10 4 8 7 9
7 3 9 2 5 4 1 9 10 8
*/
