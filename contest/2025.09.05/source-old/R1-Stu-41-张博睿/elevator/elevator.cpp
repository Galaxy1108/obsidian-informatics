#include<bits/stdc++.h>
using namespace std;

const int N=2002;
int n;
int a[N],b[N];

int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		ans+=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
