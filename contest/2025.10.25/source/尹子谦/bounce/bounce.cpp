#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,q;
int l[N],r[N],ll[N],rr[N],ans[N];
bool vis[N],viss[N];
void del(int pos)
{
	vis[pos]=0;
	r[l[pos]]=r[pos];
	l[r[pos]]=l[pos];
}
void del2(int pos)
{
	viss[pos]=0;
	rr[ll[pos]]=rr[pos];
	ll[rr[pos]]=ll[pos];
}
int main()
{
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) l[i]=i-1,r[i]=i+1,vis[i]=1;
	r[0]=1;
	l[n+1]=n;
	if(n<=1000)
	{
		while(q--)
		{
			int op,m;
			cin>>op>>m;
			if(op==1)
			{
				for(int i=1;i<=n;i+=m) if(vis[i]) del(i);
			}
			if(op==2)
			{
				int cnt=0;
				for(int i=r[0];i<=n;i=r[i]) 
				{
					if(cnt%m==0) del(i);
					cnt++; 
				}
			}
			if(op==3)
			{
				for(int i=0;i<=n+1;i++)ll[i]=l[i],rr[i]=r[i],viss[i]=vis[i];
				int pos=rr[0],cnt=0,lst;
				while(rr[0]!=n+1)
				{
					cnt=0;
					pos=rr[0];
					while(pos<=n)
					{
						if(cnt%m==0) del2(pos),lst=pos;
						pos=rr[pos];
						cnt++;
					}
					pos=ll[n+1],cnt=0;
					while(pos>=1)
					{
						if(cnt%m==0) del2(pos),lst=pos;
						pos=ll[pos];
						cnt++;
					}
				}
				cout<<lst<<endl;
			}
		}
	}
	else
	{
		while(q--)
		{
			int op,m;
			cin>>op>>m;
			if(ans[m]) cout<<ans[m]<<endl;
			else
			{
				for(int i=0;i<=n+1;i++)ll[i]=l[i],rr[i]=r[i],viss[i]=vis[i];
				int pos=rr[0],cnt=0,lst;
				while(rr[0]!=n+1)
				{
					while(pos<=n)
					{
						if(cnt%m==0) del2(pos),lst=pos;
						pos=rr[pos];
						cnt++;
					}
					pos=ll[n+1],cnt=0;
					while(pos>=1)
					{
						if(cnt%m==0) del2(pos),lst=pos;
						pos=ll[pos];
						cnt++;
					}
				}
				cout<<lst<<endl;
				ans[m]=lst;
			}
		}
	}
	return 0;
}
