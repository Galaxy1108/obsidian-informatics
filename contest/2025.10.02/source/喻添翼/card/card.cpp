#include<bits/stdc++.h>

using namespace std;
const int mx=1e6+10;
int n,m,q;
int a[mx],p[mx],b[mx];

int f[mx],c1,c2;
int bl[mx];
map<int,bool> usd;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) cin>>a[i],f[i]=-1,usd[a[i]]=0;
	for(int i=1;i<=m;i++) cin>>p[i]>>b[i],f[p[i]]=b[i],usd[b[i]]=1;
	f[0]=-1;
	while(q--)
	{
		int op,pos;
		cin>>op>>pos;
		if(op==1)
		{
			usd[f[pos]]=0;
			f[pos]=-1;
		} 
		if(op==2) 
		{
			int x;
			cin>>x;
			usd[f[pos]]=0;
			f[pos]=x;
			usd[x]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(usd[a[i]]) continue;
			if(a[i]%2==1) c1++;
			else c2++;
		}
		int cnt=0,lst=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==-1) cnt++;
			else 
			{
				if(f[i]%2==1)
				{
					if(c1>=cnt)
					{
						c1-=cnt;
						if(lst&&f[lst]%2==0) ans++;
					}
					else
					{
						c1=0,c2=c2-cnt+c1,ans++;
						if(lst&&f[lst]%2==1) ans++;
					} 
				} 
				if(f[i]%2==0)
				{
					if(c2>=cnt) 
					{
						c2-=cnt;
						if(lst&&f[lst]%2==1) ans++;
					}
					else 
					{
						c2=0,c1=c1-cnt+c2,ans++;
						if(lst&&f[lst]%2==0) ans++;
					}
				} 
				cnt=0,lst=i;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
} 
