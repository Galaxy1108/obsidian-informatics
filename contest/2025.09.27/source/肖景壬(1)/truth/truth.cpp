#include<bits/stdc++.h>
using namespace std;
int n,k,m,a[50005],f[50005][35],lst,op,x,y,ry,ans,tmp;
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	cin>>n>>k>>m;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	 }
	for(int nw = 1; nw <= k; nw++)
	{
		lst=-100000000;
		for(int i = 1; i <= n; i++)
		{
			if(a[i]==nw) lst=i;
			f[i][nw]=lst;
			//cout<<f[i][nw]<<" ";
		}
		//cout<<endl;
	}
	while(m--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			ry=a[x];
			a[x]=y;
			lst=-100000000;
			for(int i = 1; i <= n; i++)
			{
				if(a[i]==y) lst=i;
				f[i][y]=lst;
			}
			lst=-100000000;
			for(int i = 1; i <= n; i++)
			{
				if(a[i]==ry) lst=i;
				f[i][ry]=lst;
			}
		}
		else
		{
			ans=1000000000;
			for(int i = 1; i <= n; i++)
			{
				tmp=100000000;
				for(int j = 1; j <= k; j++)
				{
					tmp=min(tmp,f[i][j]);
				}
				if(tmp>0) ans=min(ans,i-tmp+1);
				//cout<<i<<" "<<tmp<<endl;
			}
			cout<<(ans<1000000?ans:-1)<<endl;
		}
	}
}
