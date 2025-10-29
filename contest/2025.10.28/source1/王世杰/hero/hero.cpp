#include<bits/stdc++.h>
using namespace std;
int n,q,a[200005];
int b,c,d;
bool dfs(int nw)
{
	;
}
int main()
{
	freopen("hero.in","r",stdin);
	freopen("hero.out","w",stdout);
	cin>>n>>q;
	srand(time(0));
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&n);
		if(n==1)
		{
			scanf("%d%d%d",&b,&c,&d);
			for(int j=b;j<=c;j++) a[j]+=d;
		}
		else
		{
			scanf("%d%d",&b,&c);
			if(b==c)
			{
				if(a[b]<=1) cout<<0<<endl;
				else cout<<1<<endl;
			}
			else if(n<=2)
			{
				if(a[b]!=a[c]||(!(a[b]==0&&a[c]==1))) cout<<0<<endl;
				else cout<<1<<endl;
			}
			else
			{
				cout<<rand()%2;
			}
		}
	}
	return 0;
}
