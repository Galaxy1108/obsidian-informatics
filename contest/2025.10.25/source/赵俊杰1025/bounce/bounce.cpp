#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],f[20],vis[N],n;
int get(int k)
{
	vector<int>v,t;
	for(int i=1;i<=n;i++)
		if(!vis[i])v.push_back(i),t.push_back(0);
	int ans=-1;
	while(!v.empty())
	{
		for(int i=0;i*k<v.size();i++)
			t[i*k]=1,ans=v[i*k];
		int cnt=0;
		for(int i=v.size()-1;i>=0;i--)
		{
			if(!t[i])
			{
				cnt++;
				if(cnt%k==1)t[i]=1,ans=v[i];
			}
		}
		vector<int>p;
		for(int i=0;i<v.size();i++)
			if(!t[i])p.push_back(v[i]);
		v=p;
		for(int i=0;i<p.size();i++)t[i]=0;
	}
	return ans;
}
int main()
{
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>n>>T;
	for(int i=2;i<=20;i++)f[i]=get(i);
	while(T--)
	{
		int op,k;
		cin>>op>>k;
		if(n>100000)
		{
			cout<<f[k]<<'\n';
			continue;
		}
		if(op==1)
		{
			for(int i=0;i*k+1<=n;i++)
				vis[i*k+1]=1;
		}
		else if(op==2)
		{
			int cnt=0;
			for(int i=1;i<=n;i++)
			{
				cnt+=!vis[i];
				if(!vis[i]&&cnt%k==1)vis[i]=1;
			}
		}
		else
		{
			cout<<get(k)<<'\n';
		}
	}
	return 0;
}
