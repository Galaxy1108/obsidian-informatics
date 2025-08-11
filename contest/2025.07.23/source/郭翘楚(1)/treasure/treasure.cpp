#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int a[205];
int dp1[205];
int dp2[205][8];
int dp3[205][8][7];
int dp4[205][8][7][6];
int dp5[205][8][7][6][5];
int dp6[205][8][7][6][5][4];
int dp7[205][8][7][6][5][4][3];
long long ans=0;
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout); 
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp1[0]=1;
	dp2[0][0]=1;
	dp3[0][0][0]=1;
	dp4[0][0][0][0]=1;
	dp5[0][0][0][0][0]=1;
	dp6[0][0][0][0][0][0]=1;
	dp7[0][0][0][0][0][0][0]=1;
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int s=0;s<(1<<k);s++)
			{
				int f=__builtin_popcount(s);
				if(f!=a[i]) continue;
				dp1[i]=(dp1[i]+dp1[i-1])%mod;
				if(i==n) ans=ans+dp1[i-1]%mod;
			} 
		}
	}
	if(k==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(2,a[i]);j++)
			{
				for(int s=0;s<(1<<k);s++)
				{
					int f=__builtin_popcount(s);
					if(f+j!=a[i]) continue;
					int g1=(s&(1<<0)!=0);
					dp2[i][g1]=(dp2[i][g1]+dp2[i-1][j])%mod;
					if(i==n) ans=ans+dp2[i-1][j]%mod;
				}
			} 
		}
	}
	if(k==3)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(3,a[i]);j++)
			{
				for(int j1=0;j1<=min(2,a[i]);j1++)
				{
					for(int s=0;s<(1<<k);s++)
					{
						int f=__builtin_popcount(s);
						if(f+j+j1!=a[i]) continue;
						int g1=j1+((s&4)!=0);
						int g2=(s&(1<<0)!=0);
						dp3[i][g1][g2]=(dp3[i][g1][g2]+dp3[i-1][j][j1])%mod;
						if(i==n) ans=ans+dp3[i-1][j][j1]%mod;
					}
				}
			} 
		}
	}
	if(k==4)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(4,a[i]);j++)
			{
				for(int j1=0;j1<=min(3,a[i]);j1++)
				{
					for(int j2=0;j2<=min(2,a[i]);j2++)
					{
						for(int s=0;s<(1<<k);s++)
						{
							int f=__builtin_popcount(s);
							if(f+j+j1+j2!=a[i]) continue;
							int g1=j1+((s&8)!=0);
							int g2=j2+((s&4)!=0);
							int g3=(s&(1<<0)!=0);
							dp4[i][g1][g2][g3]=(dp4[i][g1][g2][g3]+dp4[i-1][j][j1][j2])%mod;
							if(i==n) ans=ans+dp4[i-1][j][j1][j2]%mod;
						}
					}
				}
			} 
		}
	}
	if(k==5)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(5,a[i]);j++)
			{
				for(int j1=0;j1<=min(4,a[i]);j1++)
				{
					for(int j2=0;j2<=min(3,a[i]);j2++)
					{
						for(int j3=0;j3<=min(2,a[i]);j3++)
						{
							for(int s=0;s<(1<<k);s++)
							{
								int f=__builtin_popcount(s);
								if(f+j+j1+j2+j3!=a[i]) continue;
								int g1=j1+((s&16)!=0);
								int g2=j2+((s&8)!=0);
								int g3=j3+((s&4)!=0);
								int g4=(s&(1<<0)!=0);
								dp5[i][g1][g2][g3][g4]=(dp5[i][g1][g2][g3][g4]+dp5[i-1][j][j1][j2][j3])%mod;
								if(i==n) ans=ans+dp5[i-1][j][j1][j2][j3]%mod;
							}
						}
					}
				}
			} 
		}
	}
	if(k==6)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(6,a[i]);j++)
			{
				for(int j1=0;j1<=min(5,a[i]);j1++)
				{
					for(int j2=0;j2<=min(4,a[i]);j2++)
					{
						for(int j3=0;j3<=min(3,a[i]);j3++)
						{
							for(int j4=0;j4<=min(2,a[i]);j4++)
							{
								for(int s=0;s<(1<<k);s++)
								{
									int f=__builtin_popcount(s);
									if(f+j+j1+j2+j3+j4!=a[i]) continue;
									int g1=j1+((s&32)!=0);
									int g2=j2+((s&16)!=0);
									int g3=j3+((s&8)!=0);
									int g4=j4+((s&4)!=0);
									int g5=(s&(1<<0)!=0);
									dp6[i][g1][g2][g3][g4][g5]=(dp6[i][g1][g2][g3][g4][g5]+dp6[i-1][j][j1][j2][j3][j4])%mod;
									if(i==n) ans=ans+dp6[i-1][j][j1][j2][j3][j4]%mod;
								}
							}
						}
					}
				}
			} 
		}
	}
	if(k==7)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(7,a[i]);j++)
			{
				for(int j1=0;j1<=min(6,a[i]);j1++)
				{
					for(int j2=0;j2<=min(5,a[i]);j2++)
					{
						for(int j3=0;j3<=min(4,a[i]);j3++)
						{
							for(int j4=0;j4<=min(3,a[i]);j4++)
							{
								for(int j5=0;j5<=min(2,a[i]);j5++)
								{
									for(int s=0;s<(1<<k);s++)
									{
										int f=__builtin_popcount(s);
										if(f+j+j1+j2+j3+j4+j5!=a[i]) continue;
										int g1=j1+((s&64)!=0);
										int g2=j2+((s&32)!=0);
										int g3=j3+((s&16)!=0);
										int g4=j4+((s&8)!=0);
										int g5=j5+((s&4)!=0);
										int g6=(s&(1<<0)!=0);
										dp7[i][g1][g2][g3][g4][g5][g6]=(dp7[i][g1][g2][g3][g4][g5][g6]+dp7[i-1][j][j1][j2][j3][j4][j5])%mod;
										if(i==n) ans=ans+dp7[i-1][j][j1][j2][j3][j4][j5]%mod;
									}
								}
							}
						}
					}
				}
			} 
		}
	}
	cout<<ans%mod;
	return 0;
} 
