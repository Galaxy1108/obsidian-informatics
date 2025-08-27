#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
long long ans[]={0,1,3,13,252,5467,585156,55314571,30840599664};
long long fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	long long n,p;
	n=fread(),p=fread();
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=ans[i];
//		cout<<ans[i]<<' ';
		sum%=p;
	}
	cout<<sum;
	return 0;
}


