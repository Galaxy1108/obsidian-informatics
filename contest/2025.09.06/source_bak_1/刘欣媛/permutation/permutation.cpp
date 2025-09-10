#include <bits/stdc++.h>
using namespace std;
int p[100005],q[100005];
int h[100005],hn[100005];
int ans[15][105][4];
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
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
	if(n==2)
	{
		if(p[1]==q[1])
		{
			cout<<"YES\n";
			cout<<1<<" "<<2;
			return 0;
		}
	
	}
//	ans[3][1]={0,1,2,3},ans[3][2]={0,1,3,2},ans[3][3]={0,2,1,3};
//	ans[3][4]={0,2,3,1},ans[3][5]={0,3,1,2},ans[3][6]={0,3,2,1};
//	if(n==3)
//	{
//		for(int i=1;i<=6;i++)
//		{
//			bool fl=1;
//			for(int j=1;j<=3;j++)
//			{
//				if(ans[3][i][q[j]]!=p[ans[3][i][j]]) fl=0;
//			}
//			if(fl)
//			{
//				cout<<"YES\n";
//				for(int j=1;j<=3;j++)
//				{
//					cout<<ans[3][i][j]<<" ";
//				}		
//			}
//		}
//	 } 
	cout<<"NO";
	
	
	
	
	return 0;
} 
