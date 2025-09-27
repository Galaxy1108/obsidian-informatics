#include<bits/stdc++.h>
using namespace std;

int r[100010],l[100010],n,m;

bool check(int x)
{
	int ll=1,rr=1,cnt=0;
	for(ll;ll<=n;ll++)
	{
		if(r[rr]-l[ll]>x) continue;
		while(abs(r[rr]-l[ll])>x&&rr<=m) rr++;
		if(rr>m) break;
		cnt++;
		rr++;
	}
	if(cnt<min(m,n)) return 0;
	else return 1;
}
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>l[i];
	for(int i=1;i<=m;i++) cin>>r[i];
	sort(l+1,l+n+1),sort(r+1,r+m+1);
    int p=0,q=max(l[n]-r[1],r[m]-l[1]),ans=0;
    while(p<=q)
    {
    	int mid=(p+q)/2;
    	if(check(mid)==1)
    	{
    		ans=mid;
    		q=mid-1;
		}
		else p=mid+1;
	}
	cout<<ans;
	return 0;
}
