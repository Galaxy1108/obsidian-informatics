#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int T;
bool pr[N];
signed main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int s,k;
		cin>>s>>k;
		if(s%2)
		{
			if(k>s/2) cout<<-1<<endl;
			else cout<<2*k<<endl;
		}
		else
		{
			int cnt=0;
			memset(pr,0,sizeof pr);
			if(k>=s/2) cout<<-1<<endl;
			else
			{
				for(int i=3;i<=s;i++)
				{
					if(pr[i]||s%i==0) continue;
					if(++cnt==k)
					{
						cout<<i<<endl;
						break;
					}
					for(int j=i;j<=s;j+=i)
					{
						int p=s-j;
						for(int t=1;t<=p;t++) if(p%t==0) pr[t]=1;
					}
				}
			}
		}
	}
	return 0;
} 
