#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
const int mx=1e5+10;
int l[mx],r[mx];
int n,m;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
bool check(int k)
{
	int sum=0,p=1;
	bool b=0;
	if(n<=m)
	{
		for(int i=1;i<=n;i++)
		{
			b=0;
			for(int j=p;j<=m;j++)
			{
				if(abs(r[j]-l[i])<=k)
				{
					p=j+1;
					b=1;
					break;
				}
			}
			if(b==0) return 0;
		}
		return 1;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			b=0;
			for(int j=p;j<=n;j++)
			{
				if(abs(l[j]-r[i])<=k)
				{
					p=j+1;
					b=1;
					break;
				}
			}
			if(b==0) return 0; 
		}
		return 1;
	}
}
signed main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	n=fread(),m=fread();
	for(int i=1;i<=n;i++) l[i]=fread();
	for(int i=1;i<=m;i++) r[i]=fread();
	sort(l+1,l+n+1);
	sort(r+1,r+m+1);
//	for(int i=1;i<=n;i++) cout<<l[i]<<' ';cout<<endl;
//	for(int i=1;i<=m;i++) cout<<r[i]<<' ';cout<<endl;
	int L=0,R=max(abs(r[m]-l[1]),abs(l[n]-r[1]));
	while(L<R)
	{
		int mid=(L+R)/2;
		if(check(mid)) R=mid;
		else L=mid+1;
	}
//	for(int i=1;i<=4;i++)
//	cout<<check(i)<<' ';cout<<endl;
	cout<<L;
	return 0;
}


