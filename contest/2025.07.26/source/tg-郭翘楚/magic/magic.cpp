#include <bits/stdc++.h>
using namespace std;
int p[200005];
int h[200005];
int lh[200005],rh[200005];
struct node{
	int l,t;
}y[200005];
int g[200005];
bool cmp(node x,node y)
{
	return x.t<y.t;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		h[i]=p[i];
	}
	sort(h+1,h+n+1);
	for(int i=1;i<=q;i++)
	{
		memset(lh,0x3f,sizeof(lh));
		memset(rh,0x3f,sizeof(rh));
		cin>>y[i].t>>y[i].l;
		if(y[i].t>=n*n)
		{
			cout<<h[y[i].l]<<endl;
			continue;
		}
		if(y[i].t==0)
		{
			cout<<p[y[i].l]<<endl;
			continue;
		}
		int c=y[i].t;
		for(int j=1;j<=n;j++)
		{
			g[j]=p[j];
		}
		int maxlh=-1,minlh=0x3f3f3f3f;
		int maxrh=-1,minrh=0x3f3f3f3f;
		while(c--)
		{
			if(g[n/2+1]==n or maxlh<minrh and maxlh!=-1 and minrh!=0x3f3f3f3f)
			{
				break;
			}
			for(int j=1;j<=n/2;j++)
			{
				
				lh[j]=g[j];
				maxlh=max(maxlh,lh[j]);
				minlh=min(minlh,lh[j]);
				rh[j]=g[j+n/2];
				maxrh=max(maxrh,rh[j]);
				minrh=min(minrh,rh[j]); 
			}
			int f=1,f1=1;
			for(int j=1;j<=n;j++)
			{
				if(lh[f]<rh[f1])
				{
					g[j]=lh[f];
					f++;
				}
				else
				{
					g[j]=rh[f1];
					f1++;
				}
			}
//			for(int j=1;j<=n;j++)
//			{
//				cout<<g[j]<<" ";
//			}
//			cout<<endl;
		}
		cout<<g[y[i].l]<<endl;
	}
}
