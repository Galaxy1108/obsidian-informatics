#include<bits/stdc++.h>
#define int long long
using namespace std;
unordered_map <string,int> ma;
unordered_map <string,int> dis;
bool pd(string a)
{
	for(int i=0;i<a.size()-1;i++)
	{
		if(a[i]==a[i+1])
		{
			return 0;
		}
	}
	return 1;
}
/*void dfs(string a)
{
//	cout<<a<<"-----"<<endl;
/*	
	if(dist[a]>0x3f3f3f)
	{
		cout<<-1;
		return;
	}

	if(ma[a])
	{
		return ;
	}
	if(pd(a))
	{
		ans=min(dis[a],ans);
//		cout<<ans<<endl;
		return;
	}
	for(int i=0;i<a.size()-1;i++)
	{
		string b=a;
		char ch1=b[i];
		char ch2=b[i+1];
		b[i]=ch2;
		b[i+1]=ch1;
//		if(ma[b]==0)
		if(1)
		{
			dis[b]=dis[a]+1;
//			cout<<dis[a]<< " "<<dis[b]<<"-9237497hdsf";
//			cout<<a<<endl;
//			ma[b]=1;
			dfs(b);
//			ma[b]=1;
		}
	}
}*/
int tot[3];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	string a;
	cin>>a;
	if(pd(a))
	{
		cout<<0;
		return 0;
	}
	for(int i=0;i<a.size();i++)
	{
		tot[a[i]-'0']++;
	}
	for(int i=0;i<=2;i++)
	{
//		cout<<tot[i]*2<<" "<<a.size()<<endl;
		if(tot[i]*2-(int)a.size()>1)
		{
			cout<<-1;
			return 0;
		}
	}
	ma[a]=1;
	dis[a]=0;
	deque <string> de;
	de.push_back(a);
	while(!de.empty())
	{
		string cl=de.front();
		de.pop_front();
		for(int i=0;i<cl.size()-1;i++)
		{
			string b=cl;
			char ch1=b[i];
			char ch2=b[i+1];
			b[i]=ch2;
			b[i+1]=ch1;
			if(!ma[b])
			{
				ma[b]=1;
				de.push_back(b);
				dis[b]=dis[cl]+1;
				if(pd(b))
				{
					cout<<dis[b];
					return 0;
				}
			}
		}
	}
	return 0;
}
/*
---INFORMATIONS---
TIME:2025-09-27 08:48:10
*/
