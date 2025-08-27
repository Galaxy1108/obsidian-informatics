#include<bits/stdc++.h>
using namespace std;
int n,t,x;
int main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	cin>>n>>x;
	if(x==0)
	{
		cout<<n<<" ";
		for(int i = 2; i <= n; i++)
		{
			cout<<"0 ";
		}
	}
}
