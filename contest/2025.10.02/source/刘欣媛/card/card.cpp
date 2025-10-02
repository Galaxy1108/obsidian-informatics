#include <bits/stdc++.h>
using namespace std;
int p[1000005],b[1000005];
int l,r;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	int o;
	for(int i=1;i<=n;i++)
	{
		cin>>o;
		if(o%2==0)
		{
			l++;
		}
		else
		{
			r++;
		}
	}
	int m;
	cin>>m;
	int p,b;
	for(int i=1;i<=m;i++)
	{
		cin>>p[i]>>b[i];
	 } 
	while(q--)
	{
		int t,idx;
		cin>>t>>idx;
		if(t==1)
		{
			
		}
	}
	
	
	return 0;
 } 
