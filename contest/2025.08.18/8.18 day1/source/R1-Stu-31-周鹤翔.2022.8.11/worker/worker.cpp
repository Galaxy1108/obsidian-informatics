#include<bits/stdc++.h>
#define INF 2147483647
using namespace std;
inline int read()
{
	int s=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';s=(s<<3)+(s<<1)+(ch^48),ch=getchar());
	return (f==1)?s:-s;
}
inline void write(int n)
{
	if(n<0)putchar('-'),write(-n);
	if(n>9)write(n/10);
	putchar(n%10+'0');
}
int a[200],n,dp[200],cnt[4];
int sum(int l,int r)
{
	int bk[4]={0,0,0,0};
	for(int i=l;i<=r;i++)bk[a[i]]=1;
	return bk[1]+bk[2]+bk[3];
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	n=read();
	char ch;
	for(int i=1;i<=n;i++)
	{
		cin>>ch;
		if(ch=='A')a[i]=1;
		if(ch=='B')a[i]=2;
		if(ch=='C')a[i]=3;
		dp[i]=INF;
	}
	if(n<=10)
	{
		write(sum(1,n));putchar('\n');
		return 0;
	}
	if(n>10)
	{
		for(int i=1;i<=10;i++)cnt[a[i]]++;
		int i=11,ans=0;
		while(i<=n)
		{
			if(cnt[1]>=cnt[2]&&cnt[1]>=cnt[3])
			{
				ans++;
				int num=cnt[1];
				if(i+num>=n)
				{
					ans+=(cnt[1]>0);
					ans+=(cnt[2]>0);
					ans+=(cnt[3]>0);
					cout<<ans<<endl;
					return 0;
				}
				cnt[1]=0;
				for(int j=i+1;j<=i+num;j++)
				{
					cnt[a[j]]++;
				}
				i=i+num+1;
			}
			if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[3])
			{
				ans++;
				int num=cnt[2];
				if(i+num>=n)
				{
					ans+=(cnt[1]>0);
					ans+=(cnt[2]>0);
					ans+=(cnt[3]>0);
					cout<<ans<<endl;
					return 0;
				}
				cnt[2]=0;
				for(int j=i+1;j<=i+cnt[2];j++)
				{
					cnt[a[j]]++;
				}
				i=i+num+1;
			}
			if(cnt[3]>=cnt[2]&&cnt[3]>=cnt[1])
			{
				ans++;
				int num=cnt[3];
				if(i+num>=n)
				{
					ans+=(cnt[1]>0);
					ans+=(cnt[2]>0);
					ans+=(cnt[3]>0);
					cout<<ans<<endl;
					return 0;
				}
				cnt[3]=0;
				for(int j=i+1;j<=i+num;j++)
				{
					cnt[a[j]]++;
				}
				i=i+num+1;
			}
		}
		return 0;
	}
	return 0;
}
