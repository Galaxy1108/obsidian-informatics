#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
int a[110000];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
signed main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	int n,m;
	n=fread(),m=fread();
	for(int i=1;i<=n;i++) a[i]=fread();
	while(m--)
	{
		int l=fread(),r=fread(),c=fread();
		int ans=c;
		for(int i=l;i<=r;i++)
		{
			if(a[i]<ans) ans--;
			else if(a[i]>ans) ans++; 
		}
		cout<<ans<<endl;
	}
	return 0;
}


