#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
int n;
int p[mx],q[mx],h[mx],hh[mx];
bool used[mx];
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=n;i++) cin>>q[i];
	bool flag=1;
	for(int i=1;i<=n-1;i++)
	{
		if(p[i]!=i+1)
		{
			flag=0;
			break;
		}
	}
	cout<<"NO";
	return 0;
}
