#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,y;
		cin>>n>>x>>y;
		cout<<"YES\n";
		int l=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				cout<<l<<" ";
				l++;
			}
			cout<<"\n";
		}
	}
	
	
	
	return 0;
} 
