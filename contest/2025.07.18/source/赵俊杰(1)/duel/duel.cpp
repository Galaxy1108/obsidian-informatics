#include<bits/stdc++.h>
using namespace std;
const int N=800005;
int a[N],b[N];
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,T;
	cin>>n>>T;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(T--)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1)
		{
			a[x]=y;
		}
		else
		{
			int k=0;
			for(int j=1;j<=(1<<j);j++)
				b[++k]=a[x+(1<<j)-1];
			for(int i=1;i<=y;i++)
			{
				for(int j=1;j<=k/2;j++)
					b[j]=max(b[j<<1],b[j<<1|1])-min(b[j<<1],b[j<<1|1]);
				k/=2;
			}
			cout<<b[1]<<'\n';
		}
	}
	return 0;
}
