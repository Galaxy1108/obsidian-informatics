#include<bits/stdc++.h>
#define int long long
using namespace std;
int ans[1100];
double eps=0.00000000000001;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
signed main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	int a=fread(),b=fread();
	if(b==1)
	{
		cout<<1<<endl<<1;
		return 0;
	}
	if(b==2)
	{
		cout<<a<<endl;
		for(int i=1;i<=a;i++)
		cout<<2<<' ';
		return 0;
	}
	int l=2,r=1111111100;
	double now=a*1.0/b;
	int cnt=0;
	while(now>eps)
	{
//		cout<<now<<endl;
		int ss=0;
		l=2,r=1111111100;
		while(l<r)
		{
//			cout<<l<<' '<<r<<endl;
			int mid=(l+r)/2;
//				cout<<now<<' '<<1.0/mid<<endl; 
			if(now-1.0/mid+eps>=0)
			{
				ss=mid;
				r=mid;
			}
			else l=mid+1;
		}
		now-=1.0/ss;
//		cout<<ss<<endl;
		ans[++cnt]=ss;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
