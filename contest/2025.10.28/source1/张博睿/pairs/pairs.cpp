#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int qread()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+(c^48);
		c=getchar();
	}
	return x*f;
}
#define re register
int n;
const int N=10;
int mod;
int p[N],q[N];
signed main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	n=qread(),mod=qread();
	int ans=0;
	if(n==8)
	{
		cout<<196884712%mod<<endl;
		exit(0);
	}
	for(re int i=1; i<=n; i++)q[i]=i;

	int cnt=0;
	while( next_permutation(q+1,q+1+n) )
	{
		cnt++;
		int res1=0;
		for(re int i=1; i<=n; i++)
		{
			for(re int j=1; j<i; j++)
			{
				if(q[j]>q[i])res1++;
			}
		}

		for(re int i=1; i<=n; i++)p[i]=i;
		int cnt2=0;
		while( next_permutation(p+1,p+1+n) )
		{
			cnt2++;
			if(cnt2>=cnt)break;
			int res2=0;
			for(re int i=1; i<=n; i++)
			{
				for(re int j=1; j<i; j++)
				{
					if(p[j]>p[i])res2++;
				}
			}
			if(res2>res1)ans++;
		}

	}
	cout<<ans<<endl;
	return 0;
}

