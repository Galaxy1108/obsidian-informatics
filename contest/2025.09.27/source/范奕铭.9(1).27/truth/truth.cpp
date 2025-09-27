#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int a[50050];
int solve()
{
	int dph3[100]={0};
	int zhong=0;
	int chang=0;
	long long minn=1e9;
	queue<int>p;
	for(int i=1;i<=n;i++)
	{
		p.push(a[i]);
		dph3[a[i]]++;
		chang++;
		if(dph3[a[i]]==1)
		{
			zhong++;
		}
		while(dph3[p.front()]>1)
		{
			dph3[p.front()]--;
			p.pop();
			chang--;
		}
		if(zhong==k)
		{
			if(chang<minn)
			{
				minn=chang;
			}
		}
	}
	return minn;
}
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		int dph;
		cin>>dph;
		if(dph==1)
		{
			int dph1;
			int dph2;
			cin>>dph1>>dph2;
			a[dph1]=dph2;
		}
		if(dph==2)
		{
			if(solve()==1e9)
			{
				cout<<-1<<endl;
			}
			else
			{
				cout<<solve()<<endl;
			}
		}
	}
	return 0;
}
