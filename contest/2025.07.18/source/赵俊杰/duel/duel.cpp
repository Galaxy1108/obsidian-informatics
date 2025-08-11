#include<bits/stdc++.h>
using namespace std;
const int N=800005;
int a[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,T;
	cin>>n>>T;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(T--)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1)
		{
			a[x]=y;
		}
		else
		{
			cout<<"0\n";
		}
	}
	return 0;
}
