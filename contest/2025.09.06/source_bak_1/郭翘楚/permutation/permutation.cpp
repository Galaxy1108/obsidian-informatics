#include <bits/stdc++.h>
using namespace std;
int p[100005];
int q[100005];
int h[100005];
int vis[100005];
int vis1[100005];
vector<vector<int> > cyp;
vector<vector<int> > cyq;
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>q[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			cnt++;
			int cur=i;
			vector<int> c;
			while(!vis[cur])
			{
				vis[cur]=true;
				c.push_back(cur); 
				cur=p[cur];
			}
			cyp.push_back(c);
		}
	}
	int cnt1=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis1[i])
		{
			cnt1++; 
			int cur=i;
			vector<int> c;
			while(!vis1[cur])
			{
				vis1[cur]=true;
				c.push_back(cur);
				cur=q[cur];
			}
			cyq.push_back(c);
		}
	}
	if(cnt!=cnt1)
	{
		cout<<"NO";
		return 0;
	}
	sort(cyp.begin(),cyp.end(),
		[](vector<int>& a,vector<int>& b){
			return a.size()<b.size();
		}
	);
	sort(cyq.begin(),cyq.end(),
		[](vector<int>& a,vector<int>& b){
			return a.size()<b.size();
		}
	);
//	for(auto& s:cyp)
//	{
//		for(int num:s)
//		{
//			cout<<num<<" "; 
//		}
//		cout<<endl;
//	}
	for(int i=0;i<cnt;i++)
	{
		if(cyp[i].size()!=cyq[i].size())
		{
			cout<<"NO";
			return 0;
		}
		for(int j=0;j<cyp[i].size();j++)
		{
			h[q[cyq[i][j]]]=p[cyp[i][j]];
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<h[i]<<" ";
	}
	return 0;
} 
