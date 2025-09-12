#include<bits/stdc++.h> 
using namespace std;
int getlg(int x)
{
	x++;
	int ans=0,flag=1;
	while(flag<x)
	{
		ans++;
		flag*=2;
	}
	return ans;
}
int main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
		}
		cout<<getlg(n)<<"\n";
	}
	return 0;
}
