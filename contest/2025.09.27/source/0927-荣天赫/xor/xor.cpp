#include<iostream>
#include<cmath>
using namespace std;
int num[100005];
int xorr[100005];
int st[100005][30];
int ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
	}
	xorr[1]=num[1];
	for(int i=2;i<=n;i++)
	{
		xorr[i]=xorr[i-1]^num[i];
	}
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<xorr[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int k=xorr[j]^xorr[i-1];
			cout<<i<<" "<<j<<" "<<k<<endl;
		}
	}
	cout<<endl<<endl;     //O(1)获取区间异或 
	*/
	for(int i=1;i<=n;i++)
	{
		st[i][0]=num[i];
	}
	for(int j=1;j<=26;j++)
	{
		for(int i=1;i+(1<<j)<=n+1;i++)
		{
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}//O(1)获取区间最值
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int k=log2(j-i+1);
			int xo=xorr[j]^xorr[i-1];
			int stt=max(st[i][k],st[j-(1<<k)+1][k]);
			if(xo==stt)
			{
				ans++;
			}
		}
	}//尽力了无法优化…… 
	cout<<ans;
	return 0;
}
