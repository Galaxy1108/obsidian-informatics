#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,l[N],r[N];
bool checks(int mid)
{
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		pos++;
		if(pos>m)return false;
		while(abs(l[i]-r[pos])>mid)
		{
			pos++;
			if(pos>m)return false;
		}
	}
	return true;
}
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>l[i];
	for(int i=1;i<=m;i++)cin>>r[i];
	if(m<n)
	{
		swap(n,m);
		for(int i=1;i<=m;i++)swap(l[i],r[i]);
	}
	sort(l+1,l+1+n);
	sort(r+1,r+1+m);
	int pl=0,pr=2e9,anslt;
	while(pl<=pr)
	{
		int mid=(pl+pr)/2;
		if(checks(mid))
		{
			pr=mid-1;
			anslt=mid;
		}
		else pl=mid+1;
	}
	cout<<anslt;
	
	return 0;
} 
