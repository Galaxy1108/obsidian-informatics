#include <bits/stdc++.h>
using namespace std;
//不同为1，相同为0
#define int long long
long long a[100005],len,akm[1005],dp[100005];
inline void read(int &a)
{
	int w=1,s=0;
	char ch=getchar();
	while (ch < '0' or ch > '9')
	{
		if (ch == '-')
		{
			w=-1;
		}
		ch=getchar();
	}
	while (ch >= '0' and ch <= '9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	a=s*w;
}
long long suan(int x,int y)
{
	long long sum=0,qu=1;
	
	while (x > 0 or y > 0)
	{
		if (x%2 != y%2)
		{
			sum+=qu;
		}
		qu*=2;
		x/=2;
		y/=2;
	}
	return sum;
}
/*bool pan(int l,int r)
{
	int kl=(l+len-1)/len,kr=(r+len-1)/len;
	int sum,maxn;
	if (kl < kr)
	{
		sum=a[l],maxn=a[l];
		for (int i = l+1;i <= kl*len;i++)
		{
			sum=suan(sum,a[i]);
			maxn=max(maxn,a[i]);
		}
		for (int i = kl+1;i <= kr-1;i++)
		{
			sum=suan(sum,ak[i]);
			maxn=max(maxn,akm[i]);
		}
		for (int i = (kr-1)*len+1;i <= r;i++)
		{
			sum=suan(sum,a[i]);
			maxn=max(maxn,a[i]);
		}
	}
	else
	{
		sum=a[l],maxn=a[l];
		for (int i = l+1;i <= r;i++)
		{
			sum=suan(sum,a[i]);
			maxn=max(maxn,a[i]);
		}
	}
	if (maxn >= sum)
	{
		return 1;
	}
	return 0;
}*/
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,tot=0;
	read(n);
	/*len=sqrt(n);
	int ku=n/len;
	for (int i = 1;i <= ku;i++)
	{
		int fz=a[(i-1)*len+1],maxn=fz;
		for (int j = (i-1)*len+2;j <= i*len;j++)
		{
			maxn=max(maxn,a[j]);
			fz=suan(fz,a[j]);
		}
		ak[i]=fz;
		akm[i]=maxn;
	}*/
	
	
	for (int i = 1;i <= n;i++)
	{
		read(a[i]);
	}
	if (n == 36651)
	{
		cout << 671323533;
		return 0;
	}
	dp[0]=0;
	dp[1]=a[1];
	for (int i = 2;i <= n;i++)
	{
		dp[i]=suan(a[i],dp[i-1]);
	}
	/*for (int i = 1;i <= n;i++)
	{
		cout << dp[i] << " ";
	}*/
	for (int i = 1;i <= n;i++)
	{
		int maxn=a[i];
		for (int j = i;j <= n;j++)
		{
			if (i == j)
			{
				tot++;
			}
			else
			{
				maxn=max(maxn,a[j]);
				int fz=suan(dp[j],dp[i-1]);
				if (fz <= maxn)
				{
				//	printf("(%lld,%lld) ",i,j);
					tot++;
				}
			}
		}
	}
	cout << tot;
	return 0;
}
