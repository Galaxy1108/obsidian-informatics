#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mx=1e6+100;
int a[mx],b[mx];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
//void solve(int x)
//{
//	b[n]-=b[x];
//	if(b[n])
//}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T=fread(),t=T;
	int n;
	while(T--)
	{
		if(T==t-1) 
		{
			n=fread();
			for(int i=1;i<=n;i++) a[i]=fread();
		}
		else
		{
			int k=fread();
			for(int i=1;i<=k;i++)
			{
				int x=fread(),y=fread();
				a[x]=y;
			}
		}
		for(int i=1;i<=n;i++) b[i]=a[i];
		int sum=0;
		for(int i=1;i<n;i++)
		sum+=a[i];
		if(a[n]>=sum)
		{
			cout<<"1\n";
			continue;
		}
//		for(int i=1;i<=n-1;i++)
//		{
//			if(solve(i)==0)
//			ans=i;
//		}
		cout<<n;
	}
	return 0;
}


