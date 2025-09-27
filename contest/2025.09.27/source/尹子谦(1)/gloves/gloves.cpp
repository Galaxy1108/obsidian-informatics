#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,m;
int a[N],b[N];
bool check(int x)
{
	int delt=abs(m-n);
	if(m>n)
	{
		int p=1;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(;p<=m;p++)
			{
				if(abs(a[i]-b[p])<=x) {p++;break;}
				else cnt++;
				if(cnt>delt) return 0;
			}
		}
		return 1;
	}
	else
	{
		int p=1;
		int cnt=0;
		for(int i=1;i<=m;i++)
		{
			for(;p<=n;p++)
			{
				if(abs(b[i]-a[p])<=x) {p++;break;}
				else cnt++;
				if(cnt>delt) return 0;
			}
		}
		return 1;
	}
}
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=m;j++) cin>>b[j];
	sort(a+1,a+n+1),sort(b+1,b+m+1);
	int l=0,r=max(a[n],b[m]);
	int ans;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
} 
