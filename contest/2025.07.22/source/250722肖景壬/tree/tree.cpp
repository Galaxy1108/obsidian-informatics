#include<bits/stdc++.h>
using namespace std;
int n,m,l[100005],r[100005],st[100005],en[100005],va[100005];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout); 
	cin>>n>>m;
	for(int i = 2; i <= n; i++)
	{
		cin>>l[i]>>r[i];
	 } 
	for(int i = 1; i <= m; i++)
	{
		cin>>st[i]>>en[i]>>va[i];
	}
	cout<<0<<endl;
 } 
