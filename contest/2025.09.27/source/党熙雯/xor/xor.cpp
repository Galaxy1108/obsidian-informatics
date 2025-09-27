#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mx=1e5+10;
int a[mx];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n=fread();
	for(int i=1;i<=n;i++) a[i]=fread();
	int ans=0;
	if(n<=2000)
	{
		for(int i=1;i<=n;i++)
		{
			int maxn=0,sum=0;
			for(int j=i;j<=n;j++)
			{
				maxn=max(maxn,a[j]);
				sum=sum^a[j];
				if(sum<=maxn) ans++; 
			}
		}
		cout<<ans;
	}
	else
	{
		cout<<(n-1)*n/2;
		
	}
	return 0;
}


