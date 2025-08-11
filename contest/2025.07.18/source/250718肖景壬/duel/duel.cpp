#include<bits/stdc++.h>
using namespace std;
int a[100005],n,q,b[100005],x,y,op;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n>>q;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= q; i++)
	{
		cin>>op>>x>>y;
		if(op==1) a[x]=y;
		else
		{
			y=1<<y;
			for(int i = x; i < x+y; i++) b[i-x+1]=a[i];
			while(y>=2)
			{
				y=y/2;
				for(int i = 1; i <= y; i++)
				{
					b[i]=abs(b[2*i-1]-b[2*i]);
				}
			}
			cout<<b[1]<<endl;
		}
	}
}
