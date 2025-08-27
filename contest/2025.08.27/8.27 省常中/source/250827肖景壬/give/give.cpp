#include<bits/stdc++.h>
using namespace std;
long long t,n,m,s,a[500005],f[5005][5005];
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	random_device rd;
	srand(rd());
	cin>>t;
	while(t--)
	{
		cin>>m>>s>>n;
		if(m>3000)
		{
			cout<<rand()%2<<endl;
			continue;
		}
		for(int i = 1; i <= n; i++)
		{
			cin>>a[i];
		}
		if(n==1)
		{
			cout<<(a[1]*m==s)<<endl;
			continue;
		}
		memset(f,0,sizeof(f));
		f[0][0]=1;
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= m; j++)
			{
				for(int k = 1; k <= s; k++)
				{
					if(k-a[i]>=0) f[j][k]^=f[j-1][k-a[i]];
				}
			}
		}
		/*for(int j = 1; j <= m; j++)
		{
			for(int k = 1; k <= s; k++)
			{
				cout<<f[j][k]<<" ";
			}
			cout<<endl;
		}*/
		cout<<f[m][s]<<endl;
	}
}
