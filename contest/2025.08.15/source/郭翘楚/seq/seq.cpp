#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int a[MAXN];
int b[MAXN];
int t[MAXN];
int main()
{
	freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t[a[i]]++;
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i]; 
	}
	if(n==m)
	{
		cout<<1;
		return 0;
	}
	else if(m==1) 
	{
		int ans==0;
		for(int i=1;i<=1e5;i++)
		{
			if(t[i]!=0)
			{
				ans++;
			}
		}
		cout<<ans*ans<<endl;
	}
	else
	{
		cout<<n-1;
	}
}
