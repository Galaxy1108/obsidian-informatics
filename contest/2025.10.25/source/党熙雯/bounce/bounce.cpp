#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mx=1e5+100;
int vis[mx];
int n,q;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	n=fread(),q=fread();
	int cnt=0;
	while(q--)
	{
		int tp=fread();
		int m=fread();
		if(tp==1)
		{
			for(int i=1;i<=n;i+=m)
			{
				if(!vis[i]) cnt++;
				vis[i]=1;
			}
		}
		else if(tp==2)
		{
			int js=m-1;
			for(int i=1;i<=n;i++)
			{
				if(!vis[i]) js++;
				if(js==m)
				{
					js=0;
					cnt++;
					vis[i]=1;
				}
			}
		}
		else
		{
			int js=m-1;
			int cnt1=n-cnt;
			int ans=0;
			while(cnt1)
			{
				ans++;
				cnt1-=((cnt1-1)/m+1);
			}
			ans=ceil(ans/2.0);
			for(int i=1;i<=n;i++)
			{
				if(!vis[i]) ans--;
				if(ans==0)
				{
					cout<<i<<endl;
					break;
				}
			}
		}
//		for(int i=1;i<=n;i++) cout<<vis[i]<<' ';cout<<endl;

	}
	return 0;
}


