#include<bits/stdc++.h>
using namespace std;
long long t,n,x,y,cnt;
int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y;
		cout<<"YES"<<endl;
		cnt=0;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				cnt++;
				cout<<cnt<<" ";
			}
			cout<<endl;
		}
	}
}
