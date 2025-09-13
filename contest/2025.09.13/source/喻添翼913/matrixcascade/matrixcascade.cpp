#include<bits/stdc++.h> 
using namespace std;
const int mx=1e5+10;
int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,x,y;
		cin>>n>>x>>y;
		if(x>n*n*(n*n-1)/2||y>n*n*(n*n-1)/2) cout<<"NO"<<endl;
		else if(x==n*n*(n*n-1)/2&&y!=n*n*(n+1)*(n+1)/4) cout<<"NO"<<endl;
		else if(y==n*n*(n*n-1)/2&&x!=n*n*(n+1)*(n+1)/4) cout<<"NO"<<endl;
		else 
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				cout<<(i-1)*n+j<<' ';
				cout<<endl;
			}
		}
	}
	return 0;
}
