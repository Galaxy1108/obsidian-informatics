#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define pb emplace_back
using namespace std;
typedef long long ll;
int n=10;
vector<vector<int> >ans;
vector<int>a(15);
bool vis[15];
void dfs(int u)
{
	if(1.0*clock()/CLOCKS_PER_SEC>=9.3)
		return;
	if(u==11)
	{
		int ffl=1;
		for(auto b:ans)
		{
			bool fl=1;
			for(int i=1;i<=10;i++)
				fl&=(abs(a[i]-b[i])<=1);
			if(fl)
			{
				ffl=0;
				break;
			}
		}
		if(ffl)ans.pb(a);
		return;
	}
	for(int i=1;i<=10;i++)
		if(!vis[i])
		{
			vis[i]=1,a[u]=i;
			dfs(u+1);
			vis[i]=0;
		}
}
int main()
{
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	dfs(1);
	cout<<ans.size()<<'\n';
	for(auto b:ans)
	{
		for(int i=1;i<=10;i++)
			cout<<b[i]<<' ';
		cout<<'\n';
	}
//	for(int i=10;i>=1;i--)
//	{
//		for(int j=i-)
//	}
//	cout<<"1\n1 2 3 4 5 6 7 8 9 10\n";
	return 0;
}
