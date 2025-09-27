#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int l[100005],r[100005],n,m;
bool check(int k)
{
	int h1=1,h2=1,cnt=0;
	for(h1;h1<=n;h1++)
	{
		if(r[h2]-l[h1]>k)
		    continue;
		while(abs(r[h2]-l[h1])>k&&h2<=m)
		    h2++;
		if(h2>m)
		    break;
		cnt++;
		h2++;
	}
	if(cnt<min(m,n))
	    return 0;
	else
	    return 1;
}
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	int i,le,ri,mid,ans;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	    cin>>l[i];
	for(i=1;i<=m;i++)
	    cin>>r[i];
	sort(l+1,l+n+1);
	sort(r+1,r+m+1);
	le=0;
	ri=max(l[n]-r[1],r[n]-l[1]);
	while(le<=ri)
	{
		mid=(le+ri)/2;
		if(check(mid)==1)
		{
			ans=mid;
			ri=mid-1;
		}
		else
		    le=mid+1;
	}
	cout<<ans;
	return 0;
} 
