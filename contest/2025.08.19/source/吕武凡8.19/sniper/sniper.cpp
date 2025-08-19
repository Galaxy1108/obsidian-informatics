#include<bits/stdc++.h>
using namespace std;
int v[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int n;
int w[8010],u[8010],t[8010];
bool tick[8010];
int k;
int sum=0;
int ans=0;
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(w[i]==15&&tick[i]==0)
		{
			return false;
		}
	}
	return true;
}
void DFS(int pos,int tm,int id)
{
	if(id==n||tm==t[n])
	{
		if(check()) ans=max(ans,sum);
		return;
	}
	for(int i=id+1;i<=n;i++)
	{
		int ti;
		if(tm!=0)
		{
			ti=tm+1+ceil(1.0*(u[i]-u[id])/2);
			if(ceil(1.0*(u[i]-u[id])/2)==0)
			{
				if(t[i]>=ti)
				{
					continue;
				}
			}
		} 
		if(tm==0) ti=t[i];
		if(ti<=t[i])
		{
			sum+=v[w[i]];
			tick[i]=1;
			DFS(u[i],t[i],i);
			sum-=v[w[i]];
			tick[i]=0;
		}
	}
}
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>u[i]>>t[i];
	}
	DFS(0,0,0);
	cout<<ans;
}
/*
5 
9 1 1 
8 1 2 
15 3 4 
2 2 4 
21 6 8 
*/
