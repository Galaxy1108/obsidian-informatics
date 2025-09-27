#include <iostream>
#include <cstring>
using namespace std;
int n,k,m,a[50005],op,p,v;
int query()
{
	int l=1,r=2,t[50005]={0},cnt=1,ans=2147483647,al=l,ar=r;
	t[a[1]]++;
	while(l<=r&&r<=n)
	{
		if(!t[a[r]])cnt++;
		t[a[r]]++;
		while(l<r&&a[r]==a[l])
		{
			t[a[l]]--;
			l++;
			if(!t[a[l]])cnt--;
		}
		if(cnt>=k)
		{
			if(ans>r-l+1)
			{
				ans=r-l+1;
				al=l;
				ar=r;
			}
		}
		r++;
	}
	memset(t,0,sizeof(t));
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(!t[a[i]])
		{
			cnt++;
			t[a[i]]++;
		}
	}
	if(ans==2147483647&&k!=1)
	{
		if(cnt>=k)
		{
			return n;
		}
		return -1;
	}
	return ans;
}
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	cin >> n >> k >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	while(m--)
	{
		cin >> op;
		if(op==1)
		{
			cin >> p >> v;
			a[p]=v;
		}
		else
		{
			cout << query() << "\n";
		}
	}
	return 0;
}

