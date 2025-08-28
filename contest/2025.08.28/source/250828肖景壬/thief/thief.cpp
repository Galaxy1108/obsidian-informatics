#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000005],l[1000005],r[1000005],c[1000005];
int main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= m; i++)
	{
		cin>>l[i]>>r[i]>>c[i];
		for(int j = l[i]; j <= r[i]; j++)
		{
			if(c[i]>a[j]) c[i]--;
			else if(c[i]<a[j]) c[i]++;
		}
		cout<<c[i]<<'\n';
	}
}
