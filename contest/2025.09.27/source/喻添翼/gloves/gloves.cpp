#include<bits/stdc++.h>
//#define int long long 
using namespace std;
const int mx=1e5+10;
const int inf=1e1;
int n,m,k1,k2;
int l[mx],r[mx];
int ans;
int mabs(int a,int b)
{
	if(a>=b) return a-b;
	return b-a;
}
bool check(int x)
{
	int pos=1;
	if(n>=m)
	{
		for(int i=1;i<=n;i++)
		{
			if(abs(l[i]-r[pos])<=x) pos++;
			if(pos==m+1) return 1;
		}
		return 0;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			if(abs(r[i]-l[pos])<=x) pos++;
			if(pos==n+1) return 1;
		}
		return 0;
	}
}
signed main() 
{
	freopen("gloves.in","r",stdin); 
	freopen("gloves.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>l[i];
	for(int i=1;i<=m;i++) cin>>r[i];
	
	sort(l+1,l+1+n);
	sort(r+1,r+1+m);
	int L=0,R=1e9;
	ans=-1;
	while(L<R)
	{
		int mid=(L+R)/2;
		if(check(mid)) R=mid;
		else L=mid+1;
	}
	
	cout<<L;
	return 0;
}
