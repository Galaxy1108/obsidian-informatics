#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,cnt=0;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i+j>n)break;
			for(int k=0;k<=n;k++)
			{
				if(i+j+k>n)break;
				for(int l=0;l<=n;l++)
				{
					if(i+j+k+l>n)break;
					for(int m=0;m<=n;m++)
					{
						if(i+j+k+l+m>n)break;
						for(int o=0;o<=n;o++)
						{
							if(i+j+k+l+m+o>n)break;
							for(int p=0;p<=n;p++)
							{
								if(i+j+k+l+m+o+p>n)break;
								for(int q=0;q<=n;q++)
								{
									if(i+j+k+l+m+o+p+q>n)break;
									for(int t=0;t<=n;t++)
									{
										if(i+j+k+l+m+o+p+q+t>n)break;
										cnt++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<cnt<<'\n';
	return 0;
}
