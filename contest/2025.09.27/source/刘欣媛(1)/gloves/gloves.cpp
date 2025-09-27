#include <bits/stdc++.h>
using namespace std;
int l[100005],r[100005],n,m;
bool check(long long mx,int type)
{
	if(type==1)
	{
		int tot=1;
		for(int i=1;i<=n;i++)
		{
			while(abs(r[tot]-l[i])>mx)
			{
				tot++;
				if(tot>m) return 0;
			}
		
			if(tot>m){
				return 0;
				
			} 
			tot++;
			
		}
		return 1;
	}
	else
	{
		int tot=1;
		for(int i=1;i<=m;i++)
		{
			while(abs(l[tot]-r[i])>mx)
			{
				tot++;
				if(tot>n) return 0;
			}
			if(tot>n) return 0;
			tot++;
		}
		return 1;
	}
	
}
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
//	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>r[i];
	}
	sort(l+1,l+n+1);
	sort(r+1,r+m+1);
	int c=min(m,n);
	if(n<m)
	{
		c=1;
	}
	else
	{
		c=0;
	}
	long long L=0,R=1e14;
	long long mid=(L+R)>>1;
	while(L<R)
	{
		mid=(L+R)>>1;
		if(check(mid,c))
		{
			R=mid;
		}
		else
		{
			L=mid+1;
		}
//		cout<<L<<" "<<R<<"\n";
	}
	cout<<L;	
	return 0;
}


